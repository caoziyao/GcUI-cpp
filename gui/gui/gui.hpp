//
//  gui.hpp
//  gui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef gui_hpp
#define gui_hpp

#include <string>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

using std::string;

class Gui {
public:
    void run();
    Gui(int width = 800, int height = 600, string title = "gc ui");
    ~Gui();
private:
    void initGui(int width = 800, int height = 600, string title= "gc ui");
    void show();
    void clear();
    void draw();
    void updateInput();
    void update();
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif /* gui_hpp */
