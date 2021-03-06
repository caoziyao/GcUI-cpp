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
#include "GcPoint.hpp"
#include "utils.hpp"
#include "GcRect.hpp"

namespace gc{
    
    class GuiButton:public GuiView {
    public:
        GcRect rect;
        GcColor color;
        GcRenderer *renderer;
        void Draw();
        GuiButton(GcRect rect, GcColor color);
        enum type {UP, DOWN};
        int pressed = type::UP;   // 按下
        bool isActive;
//        int direction = type::UP;
        
        // evnet
        void OnMouse(GcEvent event);
        void OnKey(GcEvent event);
        
        void (*OnButtonDown)();
    };
}


#endif /* button_hpp */
