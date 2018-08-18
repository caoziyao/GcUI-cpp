//
//  GcGui.hpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GcGui_hpp
#define GcGui_hpp

#include <string>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include <vector>

#include "GuiView.hpp"

using std::string;
using std::vector;

class Gui {
public:
    void run();
    Gui(int width = 800, int height = 600, string title = "gc ui");
    void AddView(GuiView GuiView);
    ~Gui();
private:
    void InitGui(int width = 800, int height = 600, string title= "gc ui");
    void show();
    void clear();
    void draw();
    void UpdateInput();
    void update();
    
    vector<GuiView> GuiViews;   // GuiView
    int numOfViews = 0;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif /* GcGui_hpp */
