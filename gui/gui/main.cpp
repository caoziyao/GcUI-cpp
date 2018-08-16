//
//  main.cpp
//  gui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>


static SDL_Window *window;
static SDL_Renderer *renderer;


int
initsdl() {
    // 初始化 SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    char *t = "gua gui";
    int width = 800;
    int height = 600;
    // 创建窗口
    // 窗口标题 窗口x 窗口y 宽 高 额外参数
    window = SDL_CreateWindow(
                              t,
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
    
    return 0;
}



void
show() {
    SDL_RenderPresent(renderer);
}


void
updateInput() {
    // 事件套路，参考我 github 的渲染器相关代码
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

void
update() {
    
}

void
clear() {
    // 设置背景颜色并清除屏幕
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void
draw() {
    // 设置画笔颜色
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    
    SDL_Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.w = 20;
    rect.h = 20;
    
    SDL_RenderDrawRect(renderer, &rect);
}

void
clickBtn() {
    printf("click btn2\n");
}

int main(int argc, const char * argv[]) {
    
    initsdl();

    
    while(true) {
        updateInput();
        // 1, update
        update();
        
        // 2, clear
        clear();
        
        // 3, draw
        draw();
        
        // 4, present
        show();
    }
    
    return 0;
}

