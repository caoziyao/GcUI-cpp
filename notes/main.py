# coding: utf-8

# 注册并启动服务
from werkzeug.wrappers import Request, Response
from werkzeug.serving import run_simple

from jsonrpc import JSONRPCResponseManager, dispatcher
from notes.api.api import route

import uuid
import requests
from notes import micro_sidecar

service = {
    "name": "go.micro.srv.py_greeter",
    "nodes": [{
        "id": "go.micro.srv.py_greeter-" + str(uuid.uuid4()),
        "address": "127.0.0.1",
        "port": 4000,
    }],
}

def init_handler():
    for k, v in route.items():
        dispatcher[k] = v

@Request.application
def application(request):
    print('in rpc py_greeter')
    # dispatcher["Say.Hello"] = lambda s: "Hello " + s["name"] + "!"
    #
    # dispatcher["Say.Hello22"] = lambda s: "Hello22 " + s["name"] + "!"
    response = JSONRPCResponseManager.handle(request.data, dispatcher)
    return Response(response.json, mimetype='application/json')

if __name__ == '__main__':
    micro_sidecar.register(service)
    init_handler()
    run_simple('localhost', 4000, application)
    micro_sidecar.deregister(service)
