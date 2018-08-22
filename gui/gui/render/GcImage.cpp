//
//  GcImage.cpp
//  gui
//
//  Created by working on 2018/8/22.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GcImage.hpp"

namespace gc {
    
    using namespace std;
    
    GcImage::GcImage(SDL_Renderer *renderer, string imageUrl) {
        this->imageUrl = imageUrl;
        std::string path = imageUrl;
        this->icon = IMG_Load(path.c_str());    //采用image加载png格式图片;
        this->renderer = renderer;
    }
    
    void GcImage::DrawImage(GcRect rect) {
        
        SDL_Rect r;
        r.x = rect.x;
        r.y = rect.y;
        r.w = rect.width;
        r.h = rect.height;
        
        string path = this->imageUrl;
        SDL_Renderer *renderer = this->renderer;
        SDL_Surface *icon = this->icon;
        
//        SDL_Surface *newTexture = SDL_CreateTextureFromSurface(renderer, icon);
        SDL_Texture *newTexture = SDL_CreateTextureFromSurface(renderer, icon);
        SDL_RenderCopy(renderer, newTexture, NULL, &r);
    }
}
