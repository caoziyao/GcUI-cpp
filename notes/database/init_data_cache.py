# coding: utf-8
"""
@author: csy
@license: (C) Copyright 2017-2018
@contact: wyzycao@gmail.com
@time: 2018/6/4 
@desc:
"""
import time
import redis
import random
import json
import math
import logging
from src.config import config

logger = logging.getLogger('dblog')


class RedisClient(object):
    _instance = None
    default_retry_count = 2

    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance = super(RedisClient, cls).__new__(cls)
        return cls._instance

    def __init__(self):
        host = config.redis_host
        port = config.redis_port
        password = config.redis_password
        db = config.redis_db

        pool = redis.ConnectionPool(host=host, port=port, password=password, db=db)
        self.client = redis.Redis(connection_pool=pool)
        testKey = "testKey%s" % random.randint(1, 100)
        self.client.set(testKey, "test redis ok")
        self.client.delete(testKey)
        logger.info('test redis ok')


client = RedisClient().client
