//
//  GuiInput.cpp
//  gui
//
//  Created by working on 2018/8/21.
//  Copyright © 2018年 working. All rights reserved.
//  输入框

#include "GuiInput.hpp"

namespace gc {
    
    using namespace std;
    
    GuiInput::GuiInput(GcRect rect, GcColor backgroundColor, GcColor checkedColor): GuiView(rect, backgroundColor),
    rect(rect),
    backgroundColor(backgroundColor),
    checkedColor(checkedColor) {
        
    }
    
    GuiInput::~GuiInput(){
        
    }
    
    void GuiInput::Draw() {
//        this->renderer->DrawText();
    }
    
    void GuiInput::Initialize() {
    }
    
    void GuiInput::OnMouse(GcEvent event) {
    
    }
    
}
