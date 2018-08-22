//
//  GcTextRender.cpp
//  gui
//
//  Created by working on 2018/8/22.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GcTextRender.hpp"


namespace gc {
    
    using namespace std;
    
    GcTextRender::GcTextRender(SDL_Renderer *renderer) {
        this->renderer = renderer;
    }
    
    void GcTextRender::Draw(string text) {
        
        TTF_Font *font = this->font;
        int x = 200;
        int y = 200;
        
        SDL_Color fontColor = {123, 123, 123, 255};
    
        SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), fontColor);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        
        // 设置座标为 100 200
        SDL_Rect size;
        SDL_QueryTexture(textTexture, NULL, NULL, &size.w, &size.h);
        size.x = x;
        size.y = y;
        
        // 画文字 注意参数
        SDL_RenderCopy(this->renderer, textTexture, NULL, &size);
        SDL_DestroyTexture(textTexture);
        
    }
}
