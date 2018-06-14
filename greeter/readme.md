参考： https://github.com/micro/micro/tree/master/proxy
https://github.com/micro/examples/tree/b166f720b69a3d04938bb292e4d79adf083c4507/proxy/python

## 其他语言 proxy
# 安装
go get -u github.com/micro/micro

# 依赖
brew install consul
consul agent -dev

# 运行
默认是 port 8081 by default
micro proxy


# 运行 python server
python3 rpc_server.py

# 运行 python client
http://127.0.0.1:8081/rpc

Content-Type:application/json

{
    "service": "go.micro.srv.greeter",
    "method": "Say.Hello",
    "request": {
        "id": "12",
		 		"name": "adfw kuaibiji"
    }
}


## golang api
1, 运行服务
先运行 python-service/main.go
$python-service > make build & make run
```make
build:
		# 告知 Go 编译器生成二进制文件的目标环境：amd64 CPU 的 Linux 系统
		GOOS=linux GOARCH=amd64 go build
		# 根据当前目录下的 Dockerfile 生成名为 consignment-service 的镜像
		docker build -t python-service .

run:
		# 在 Docker alpine 容器的 50001 端口上运行 consignment-service 服务
		# 可添加 -d 参数将微服务放到后台运行
		docker run -p 50052:50052 \
				-e MICRO_SERVER_ADDRESS=:50052 \
				-e MICRO_REGISTRY=mdns python-service

```

2, 运行 api
$greeter > make build & make run
```make
build:
		protoc -I. --go_out=plugins=micro:$(GOPATH)/src/kuaibiji/greeter proto/hello/hello.proto
		# 告知 Go 编译器生成二进制文件的目标环境：amd64 CPU 的 Linux 系统

run:
		# 在 Docker alpine 容器的 50001 端口上运行 consignment-service 服务
		# 可添加 -d 参数将微服务放到后台运行
		docker run -p 8080:8080 \
								 -e MICRO_REGISTRY=mdns \
								 microhq/micro api \
								 --handler=rpc \
								 --address=:8080 \
								 --namespace=greeter

```
3,
http://127.0.0.1:8081/rpc

Content-Type:application/json

{
    "service": "go.micro.srv.greeter",
    "method": "Say.Hello",
    "request": {
        "id": "12",
		 		"name": "adfw kuaibiji"
    }
}
