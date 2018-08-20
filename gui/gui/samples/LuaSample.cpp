//
//  LuaSample.cpp
//  gui
//
//  Created by working on 2018/8/20.
//  Copyright © 2018年 working. All rights reserved.
//

#include "LuaSample.hpp"

void LuaSample() {
    int w = 800;
    int h = 600;
    
    GcGui gui(w, h, "sss");

    GcRect rect(10, 10, 120, 230);
    GcColor viewColor(255, 255, 255, 255);
    
    GuiView view(rect, viewColor);
    gui.AddView(&view);
    
    LuaRef lua;
    GuiApi api(&gui, &lua);
    
    api.RunScript("/Users/Shared/github/GcUI-cpp/gui/gui/script/config.lua");
    gui.run();
}

