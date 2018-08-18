//
//  button.hpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef button_hpp
#define button_hpp

#include <stdio.h>
#include "GuiView.hpp"
#include "GcEvent.hpp"
#include "GcEventType.hpp"

class GuiButton:public GuiView {
public:
    GcRect rect;
    GcColor color;
    void Draw();
    GuiButton(GcRect rect, GcColor color);
    bool pressed = false;   // true 按下
    
    // evnet
    void OnMouse(GcEvent event);
    void OnKey(GcEvent event);
};

#endif /* button_hpp */
