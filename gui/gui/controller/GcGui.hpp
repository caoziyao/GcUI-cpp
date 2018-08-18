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
#include <vector>

#include "GuiView.hpp"
#include "GcRenderer.hpp"

using std::string;
using std::vector;

class GcGui {
public:
    GcGui(int width = 800, int height = 600, string title = "gc ui");
    ~GcGui();
    void AddView(GuiView GuiView);
    void run();
private:
    void InitGui(int width = 800, int height = 600, string title= "gc ui");
    void show();
    void Clear();
    void draw();
    void UpdateInput();
    void update();
    
    vector<GuiView> views;   // views
    int numOfViews = 0;
    
    GcRenderer renderer;
};


#endif /* GcGui_hpp */
