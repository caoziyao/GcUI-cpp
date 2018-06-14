# coding: utf-8
"""
@author: csy
@license: (C) Copyright 2017-2018
@contact: wyzycao@gmail.com
@time: 2018/6/3 
@desc:
"""

import pymongo
from datetime import datetime
import logging
from bson import ObjectId
from src.models import NoteModel
from src.utilities.util import to_objectid
from .data_manger import DataManager

logger = logging.getLogger('dblog')


class NoteManager(DataManager):
    _users = {}

    def __init__(self):
        super(NoteManager, self).__init__()

    def new_note(self):
        """
        创建一个 model 实例
        :return:
        """
        model = NoteModel()
        result = model.ensure_index()
        return model

    def get_note(self, _id, user_id):
        """
        返回一个已存在的 model 实例
        :return:
        """
        query = {
            '_id': to_objectid(_id),
            'user_id': user_id,
        }
        fields = ['_id']
        notebook = NoteModel()
        data = notebook.note_one_by_query(query, fields)
        if data:
            notebook.document = data
            return notebook
        else:
            return None

    def is_exit_note_by_id(self, _id, user_id):
        """
        查询是否存在该笔记
        :param _id:
        :return:
        """
        query = {
            '_id': to_objectid(_id),
            'user_id': user_id,
        }
        fields = ['_id']
        note = NoteModel()
        exit_books = note.note_one_by_query(query, fields)
        return True if exit_books else False

    def note_by_id(self, _id):
        """
        获取笔记
        :param user_id:
        :return:
        """
        query = {
            '_id': to_objectid(_id)
        }
        fields = ['_id', 'notebook_id', 'content', 'user_id']
        note = NoteModel()
        res = note.note_by_query(query, fields)
        return res

    def notes_by_notebook_id(self, notebook_id, user_id):
        """
        获取所有 笔记
        :param user_id:
        :return:
        """
        query = {
            'notebook_id': ObjectId(notebook_id),
            'user_id': user_id,
        }
        fields = ['_id', 'notebook_id', 'content']
        note = NoteModel()
        res = note.note_by_query(query, fields)
        return res

    def delete_one_note(self, _id, user_id):
        """
        删除笔记
        :param _id:
        :return:
        """
        query = {
            '_id': ObjectId(_id),
            'user_id': user_id,
        }
        note = NoteModel()
        result = note.delete_one_note(query)
        return result

    def delete_note_by_bookid(self, notebook_id, user_id):
        """
        删除笔记，
        :param notebook_id: notebook_id
        :return:
        """
        query = {
            'notebook_id': ObjectId(notebook_id),
            'user_id': user_id,
        }
        note = NoteModel()
        result = note.delete_note(query)
        return result



