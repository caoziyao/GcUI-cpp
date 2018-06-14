# coding: utf-8
"""
@author: csy
@license: (C) Copyright 2017-2018
@contact: wyzycao@gmail.com
@time: 2018/6/2
@desc:
"""
import time
import redis
import random
import json
import math
import logging
from src.config import config
from src.models import DataCacheBase
from .init_data_cache import client

logger = logging.getLogger('dblog')


class DataCacheManager(object):
    _instance = None
    default_retry_count = 2

    def __init__(self):
        self.client = client

    def lock(self, lock_key):
        model = DataCacheBase()
        e = model.set(lock_key, "x", ex=self.default_retry_count, nx=True)
        # e = self.client.set(lock_key, "x", ex=self.default_retry_count, nx=True)
        return e

    def get_bylock(self, key):
        """
        避免redis超时时的惊群现象，请必须配合 `set_bylock` 使用
        调用方法与`get`一样
        用法：
        cache_data = get_bylock(cache_id)
        if not cache_data:
            set_bylock(
                cache_id,
                json.dumps(data),
                config.CACHE_ID_PRODUCT_DETAIL_CACHE
            )
        """
        lock_key = key + ".lock"

        model = DataCacheBase()
        data = model.get(key)
        # data = self.client.get(key)
        current = int(time.time())
        if data:
            real_data = json.loads(data)
            # 如果人为设置的超时时间超时了
            if real_data['expireat'] <= current:
                # EX second ：设置键的过期时间为 second 秒, NX ：只在键不存在时，才对键进行设置操作
                if self.lock(lock_key):
                    # 如果获取到锁
                    return None
                else:
                    # 如果没获取到锁
                    return real_data['data']
            else:
                return real_data['data']
        else:
            return None

    def set_bylock(self, key, data, expire_time=config.redis_cache_timeout):
        """
        避免redis超时时的惊群现象，请必须配合`get_bylock`使用
        调用方法与`setex`一样
        """
        current = int(time.time())
        expireat = current + expire_time - math.ceil(expire_time / 4)
        real_data = {
            'data': data,
            'expireat': expireat,
        }
        model = DataCacheBase()
        model.setex(key, json.dumps(real_data), expire_time)
        # self.client.setex(key, json.dumps(real_data), expire_time)
        # lock_key = key + ".lock"
        # self.client.delete(lock_key)

    def delete(self, key):
        """
        删除key
        :return:
        """
        model = DataCacheBase()
        model.delete(key)
        # self.client.delete(key)


data_cache = DataCacheManager()
