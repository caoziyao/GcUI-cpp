//
//  GcTextRender.hpp
//  gui
//
//  Created by working on 2018/8/22.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GcTextRender_hpp
#define GcTextRender_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include "GcRect.hpp"

namespace gc {
    
    class GcTextRender {
    public:
        GcTextRender(SDL_Renderer *renderer);
        void Draw(std::string text);
        TTF_Font *font = nullptr;
    private:
        SDL_Renderer *renderer;
    };
}

#endif /* GcTextRender_hpp */
