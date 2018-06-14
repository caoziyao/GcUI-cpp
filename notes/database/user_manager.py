# coding: utf-8
"""
@author: csy
@license: (C) Copyright 2013-2018
@contact: wyzycao@gmail.com
@time: 2018/5/31
@desc:
"""
import pymongo
from bson import ObjectId
import hashlib
import logging
from datetime import datetime
from src.models.user_model import UserModel
from .data_manger import DataManager
from src.utilities.util import to_objectid

logger = logging.getLogger('dblog')


class UserManager(DataManager):
    _users = {}

    def __init__(self):
        super(UserManager, self).__init__()

    def new_user(self):
        """
        创建一个 model 实例
        :return:
        """
        model = UserModel()
        result = model.ensure_index()
        return model

    def get_user(self, _id, user_id):
        """
        返回一个已存在的 model 实例
        :return:
        """
        query = {
            '_id': to_objectid(_id),
            'user_id': user_id,
        }
        fields = ['_id']
        user = UserModel()
        data = user.user_one_by_query(query, fields)
        if data:
            user.document = data
            return user
        else:
            return None

    def is_exit_user(self, user_id):
        """
        查询是否存在该用户
        :param title:
        :param user_id:
        :return:
        """
        query = {
            'user_id': user_id,
        }
        fields = ['_id', 'user_id']
        user = UserModel()
        exit_user = user.user_one_by_query(query, fields)
        return True if exit_user else False

    def user_by_userid(self, user_id):
        """
        获取用户
        :param user_id:
        :return:
        """
        query = {
            'user_id': user_id
        }
        fields = ['user_id', 'create_time', 'update_time']
        user = UserModel()
        res = user.user_one_by_query(query, fields)
        return res
