//
//  GcGui.cpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GcGui.hpp"

using std::string;

void Gui::InitGui(int width, int height, string title) {
    // 初始化 SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    //    char *t = "gua GcGui";
    
    // 创建窗口
    // 窗口标题 窗口x 窗口y 宽 高 额外参数
    window = SDL_CreateWindow(
                              title.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_RESIZABLE
                              );
    
    // 创建渲染层 文档如下
    // http://wiki.libsdl.org/SDL_CreateRenderer?highlight=%28SDL_CreateRenderer%29
    renderer = SDL_CreateRenderer(
                                  window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED
                                  );
}


// 构造函数
Gui::Gui(int width, int height, string title) {
    InitGui(width, height, title);
}


// 析构函数
Gui::~Gui() {
    
}

// 运行
void Gui::run() {
    while(true) {
        UpdateInput();
        // 1, update
        update();
        
        // 2, clear
        clear();
        
        // 3, draw
        draw();
        
        // 4, present
        show();
    }
}


// 添加 GuiView
void Gui::AddView(GuiView GuiView) {
    GuiViews.push_back(GuiView);
    numOfViews = (int)GuiViews.size();
}


// 显示
void Gui::show() {
    SDL_RenderPresent(renderer);
}

//
void Gui::clear() {
    // 设置背景颜色并清除屏幕
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}


void Gui::draw() {
    // 设置画笔颜色
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    
    SDL_Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.w = 20;
    rect.h = 20;
    
    SDL_RenderDrawRect(renderer, &rect);
}


// update input
void Gui::UpdateInput() {

    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
                break;
            case SDL_QUIT:
                // 退出，点击关闭窗口按钮的事件
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:

                break;
            case SDL_MOUSEBUTTONUP:

                break;
        }
    }
}


void Gui::update() {
    
}
