package main

import (
	microclient "github.com/micro/go-micro/client"
	pb "kuaibiji/note-service/proto/note"
	"github.com/micro/go-micro/cmd"
	"context"
	"log"
	"io/ioutil"
	"encoding/json"
	"errors"
)

const (
	address		= "localhost:50051"
	dataPath	= "data.json"
)

// 读取 consignment.json 中记录的货物信息
func parseFile(fileName string) (*pb.Note, error) {
	data, err := ioutil.ReadFile(fileName)
	if err != nil {
		return nil, err
	}
	var consignment *pb.Note
	err = json.Unmarshal(data, &consignment)
	if err != nil {
		return nil, errors.New("consignment.json file content error")
	}
	return consignment, nil
}

func main()  {
	//conn, err := grpc.Dial(address, grpc.WithInsecure())
	//if err != nil {
	//	log.Fatalf("connect error: %v", err)
	//}
	//defer conn.Close()

	// 连接到 服务器
	cmd.Init()
	// 创建微服务的客户端，简化了手动 Dial 连接服务端的步骤
	client := pb.NewNoteServiceClient("go.micro.srv.note", microclient.DefaultClient)


	// 在命令行中指定新的货物信息 json 文件
	infoFile := dataPath

	// 解析货物信息
	consignment, err := parseFile(infoFile)
	if err != nil {
		log.Fatalf("parse info file error: %v", err)
	}

	log.Printf("parse info file error: %v", consignment)

	resp, err := client.CreateNote(context.Background(), consignment)
	if err != nil {
		log.Fatalf("create consignment error: %v", err)
	}

	log.Printf("created: %t", resp.Content)

}