//
//  GcImage.hpp
//  gui
//
//  Created by working on 2018/8/22.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GcImage_hpp
#define GcImage_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

namespace gc {
    
    class GcImage {
    public:
        GcImage(SDL_Renderer *renderer, std::string imageUrl);
        void DrawImage();
    private:
        std::string imageUrl;
        SDL_Surface *icon;
        SDL_Renderer *renderer;
    };
}

#endif /* GcImage_hpp */
