//
//  GcRenderer.cpp
//  gui
//
//  Created by working on 2018/8/18.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GcRenderer.hpp"

namespace gc {
    using namespace std;
    GcRenderer::GcRenderer(int width, int height, string title) {
        SDL_Init(SDL_INIT_VIDEO);
        
        // 创建窗口
        // 窗口标题 窗口x 窗口y 宽 高 额外参数
        this->window = SDL_CreateWindow(
                                        title.c_str(),
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        width,
                                        height,
                                        SDL_WINDOW_RESIZABLE
                                        );
        
        // 创建渲染层
        this->renderer = SDL_CreateRenderer(
                                            this->window,
                                            -1,
                                            SDL_RENDERER_ACCELERATED
                                            );
    }
    
    //
    GcRenderer::~GcRenderer() {
    }
    
    // clear
    void GcRenderer::Clear() {
        SDL_Renderer *r = this->renderer;
        SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
        SDL_RenderClear(r);
    }
    
    // show
    void GcRenderer::Show() {
        SDL_Renderer *r = this->renderer;
        SDL_RenderPresent(r);
    }
    
    void GcRenderer::GcUIClose() {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }
    
    // 鼠标事件
    void GcRenderer::GcOnMouse(SDL_Event *event, GcEvent *gcevent) {
        
        SDL_MouseButtonEvent *e = (SDL_MouseButtonEvent *)event;
        int x = e->x;
        int y = e->y;
        size_t type = e->type;
        
        if (type == SDL_MOUSEBUTTONDOWN) {
            gcevent->type = EnumMouseButtonDown;
        } else if (type == SDL_MOUSEBUTTONUP) {
            gcevent->type = EnumMouseButtonUp;
        }
        
        gcevent->x = x;
        gcevent->y = y;
    }
    
    // 键盘事件
    void GcRenderer::GcOnKey(SDL_Event event) {
        
    }
    
    // update input
    GcEvent GcRenderer::UpdateInput() {
        SDL_Event event;
        GcEvent e;
        
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEMOTION:
                    // 鼠标事件
                    GcOnMouse(&event, &e);
                    break;
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    // 键盘事件
                    //                GcOnKey(event);
                    break;
                case SDL_QUIT:
                    // 退出，点击关闭窗口按钮的事件
                    GcUIClose();
                    exit(0);
                    break;
            }
        }
        return e;
    }
    
    // set color
    void GcRenderer::SetColor(GcColor color) {
        int r = color.r;
        int g = color.g;
        int b = color.b;
        int a = color.a;
        SDL_Renderer *renderer = this->renderer;
        
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }
    
    // draw rect
    void GcRenderer::DrawRect(GcRect rect, GcColor color) {
        //     设置画笔颜色
        SetColor(color);
        
        SDL_Rect r;
        r.x = rect.x;
        r.y = rect.y;
        r.w = rect.width;
        r.h = rect.height;
        SDL_Renderer *renderer = this->renderer;
        SDL_RenderDrawRect(renderer, &r);
    }
    
    // fill rect
    void GcRenderer::RenderFillRect(GcRect rect, GcColor color) {
        
        SetColor(color);
        
        SDL_Rect r;
        r.x = rect.x;
        r.y = rect.y;
        r.w = rect.width;
        r.h = rect.height;
        
        SDL_RenderFillRect(renderer, &r);
    }
    
    // 画图
    void GcRenderer::DrawImage(string path, GcRect rect) {
        SDL_Renderer *renderer = this->renderer;
        GcImage img(renderer, path);
        // rect
        img.DrawImage();
    }
}

