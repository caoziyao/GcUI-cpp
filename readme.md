main.go
users/
	services/
		auth.go
	handlers/
		auth.go
		user.go
	users/
		user.go
containers/
	services/
		manage.go
	models/
		container.go

consignmet-service/
    ├── Dockerfile
    ├── Makefile
    ├── datastore.go	# 创建与 MongoDB 的主会话
    ├── handler.go	# 实现微服务的服务端，处理业务逻辑
    ├── main.go		# 注册并启动服务
    ├── proto
    └── repository.go	# 实现数据库的基本 CURD 操作
