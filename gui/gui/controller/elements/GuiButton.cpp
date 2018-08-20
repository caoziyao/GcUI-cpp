//
//  button.cpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GuiButton.hpp"

namespace gc{
    //
    GuiButton::GuiButton(GcRect rect, GcColor color): GuiView(rect, color), rect(rect), color(color) {
        
    }
    
    // draw
    void GuiButton::Draw() {
        GcRect rect = this->rect;
        GcColor color = this->backgroundColor;
        
        this->renderer->DrawRect(rect, color);
        if (this->pressed) {
            this->renderer->RenderFillRect(rect, color);
        }
    }
    
    // event
    void GuiButton::OnMouse(GcEvent event) {
        std::cout << "btn," << std::endl;
        
        int x = event.x;
        int y = event.y;
        GcPoint point(x, y);
        GcRect rect = this->rect;
        
        if (PointInRect(point, rect)) {
            this->pressed = true;
        } else {
            this->pressed = false;
        }
        
        if (this->pressed) {
            this->OnButtonDown();
        }
        
    }
    
    void GuiButton::OnKey(GcEvent event) {
        
    }

}

