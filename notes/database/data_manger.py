# coding: utf-8

import sys
import traceback
import logging
from bson import ObjectId
from datetime import datetime
from pymongo import MongoClient
from src.config import config
from src.utilities.util import utc_to_localtime
logger = logging.getLogger('dblog')


def connect_database():
    host = config.mongodb_host
    port = config.mongodb_port
    admin = config.mongodb_admin
    username = config.mongodb_username
    passwd = config.mongodb_password
    db_name = config.mongodb_db

    try:
        client = MongoClient(host, port)
        admin = client[admin]
        admin.authenticate(username, passwd)
        db = client[db_name]
        logger.info('connect mongodb success {}:{} {}.'.format(host, port, db_name))
        return db
    except Exception as e:
        logging.error(traceback.format_exc())
        logger.error('connect mongodb failed {}:{} {}.'.format(host, port, db_name))
        sys.exit(1)

db = connect_database()

class DataManager(object):
    _instance = None

    def __init__(self):
        self.db = db


# class DataManager(object):
#     _instance = None
#
#     def __new__(cls, *args, **kwargs):
#         if cls._instance is None:
#             cls._instance = super(DataManager, cls).__new__(cls)
#         return cls._instance
#
#     def __init__(self):
#         host = config.mongodb_host
#         port = config.mongodb_port
#         admin = config.mongodb_admin
#         username = config.mongodb_username
#         passwd = config.mongodb_password
#         db_name = config.mongodb_db
#         try:
#             client = MongoClient(host, port)
#             self.admin = client[admin]
#             self.connected = self.admin.authenticate(username, passwd)
#             self.db = client[db_name]
#             logger.info('connect mongodb success {}:{} {}.'.format(host, port, db_name))
#         except Exception as e:
#             traceback.print_exc()
#             logger.info('connect mongodb failed {}:{} {}.'.format(host, port, db_name))
#             sys.exit(1)
#

# datas = [
#         { 'data':12},
#         { 'data':22},
#         { 'data':'cc'}
#     ]
#     #插入数据，'mytest'是上文中创建的表名
# db['mytest'].insert(datas)
# post = {"author": "Mike"}
#
# result = collection.insert(post)
