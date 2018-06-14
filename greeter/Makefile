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
