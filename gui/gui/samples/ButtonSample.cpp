//
//  ButtonSample.cpp
//  gui
//
//  Created by working on 2018/8/20.
//  Copyright © 2018年 working. All rights reserved.
//

#include "ButtonSample.hpp"

using namespace std;

void click() {
    cout << "btn click" << endl;
}

void ButtonSample1() {
    int w = 800;
    int h = 600;
    
    GcGui gui(w, h, "sss");

    GcRect rect(10, 10, 120, 230);
    GcColor viewColor(255, 255, 255, 255);
    
    GuiView view(rect, viewColor);
    gui.AddView(&view);
    
    GcRect btnRect(15, 205, 100, 30);
    GcColor btnColor(12, 12, 100, 255);
    GuiButton btn(btnRect, btnColor);
    
    btn.OnButtonDown = &click;
    
    btn.renderer = view.renderer;
    view.AddElements(&btn);
    
    gui.run();
}

