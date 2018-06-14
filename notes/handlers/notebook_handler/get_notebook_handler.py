# coding: utf-8
"""
@author: csy
@license: (C) Copyright 2017-2018
@contact: wyzycao@gmail.com
@time: 2018/6/15 
@desc:
"""

from notes.services.notebook_service import NoteBookService


def clear_get_fedata(request_data):
    """
    校验前端数据
    :param body:
    :return:
    """
    data = request_data
    notebook_id = data.get('notebook_id', '')
    # if not notebook_id:
    #     self.raise_param_error('notebook_id')

    data = {
        'notebook_id': notebook_id,
    }
    return data


def get_notebook(request_data):

    # user_info = self.current_user
    #
    # # 如果没有用户，或用户 id 为空
    # if not user_info or not user_info.get('user_id'):
    #     raise ServerError(EnumServiceCode.user_not_exists)

    # user_id = user_info.get('user_id', '')
    notebook_manger = NoteBookService()
    books = notebook_manger.notebooks_by_userid(user_id)
    res = {
        'books': books,
    }
    return self.send_success(res)