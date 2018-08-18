//
//  GcGui.cpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GcGui.hpp"

using std::string;

// 构造函数
GcGui::GcGui(int width, int height, string title): renderer(width, height, title) {
    InitGui(width, height, title);
}

// 析构函数
GcGui::~GcGui() {
    
}

// 初始化 SDL
void GcGui::InitGui(int width, int height, string title) {
//    GcRenderer renderer(width, height, title);
//    this->renderer = renderer;
}

// 添加 GuiView
void GcGui::AddView(GuiView view) {
    view.SetRenderer(&this->renderer);
    views.push_back(view);
    
    numOfViews = (int)views.size();
}

// 显示
void GcGui::show() {
    this->renderer.Show();
//    SDL_RenderPresent(renderer);
}

//
void GcGui::Clear() {
    // 设置背景颜色并清除屏幕
    this->renderer.Clear();
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_RenderClear(renderer);
}

void GcGui::draw() {
    for (GuiView view : this->views) {
        view.draw();
    }
}

// update input
void GcGui::UpdateInput() {
    this->renderer.UpdateInput();
}

// update
void GcGui::update() {
    
}

// 运行
void GcGui::run() {
    while(true) {
        UpdateInput();
        // 1, update
        update();
        
        // 2, clear
        Clear();
        
        // 3, draw
        draw();
        
        // 4, present
        show();
    }
}
