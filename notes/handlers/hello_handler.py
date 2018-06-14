# coding: utf-8

def hello_handler(request_data):
    data = request_data
    r = "Hello " + data["name"] + "!",
    return r
