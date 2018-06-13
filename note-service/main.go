package main

import (
	pb "kuaibiji/note-service/proto/note"
	"context"
	"github.com/micro/go-micro"
	"log"
)

//
// 我们存放多批货物的仓库，实现了 IRepository 接口
//
type Repository struct {
	note []*pb.Note
}

//
// 定义微服务
//
type service struct {
	repo Repository
}


// 获取笔记
func (s *service) CreateNote(ctx context.Context, req *pb.Note, resp *pb.Response) error {
	// 接收承运的货物
	log.Printf("rev helllo ")
	resp.Content = "abc"
	resp.Id = "akaiwe"
	resp.CreateTime = "1234"
	resp.UpdateTime = "34455"
	return nil
}

func main()  {

	server := micro.NewService(
		// 必须和 note.proto 中的 package 一致
		micro.Name("go.micro.srv.note"),
		micro.Version("laster"),
	)

	//// 解析命令行参数
	server.Init()
	repo := Repository{}
	//
	pb.RegisterNoteServiceHandler(server.Server(), &service{repo})

	if err := server.Run(); err != nil {
		log.Fatal("failed to server: %v", err)
	}
}