//
//  GuiLabel.cpp
//  gui
//
//  Created by working on 2018/8/23.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GuiLabel.hpp"

namespace gc {
    
    using namespace std;
    
    GuiLabel::GuiLabel(GcRect rect, GcColor backgroundColor, string text): GuiView(rect, backgroundColor),
    rect(rect),
    backgroundColor(backgroundColor),
    text(text){
        
    }
    
    GuiLabel::~GuiLabel(){
        
    }
    
    void GuiLabel::Draw() {
        string t = this->text;
        this->renderer->DrawText(t);
    }
    
    void GuiLabel::Initialize() {
    }
    
    void GuiLabel::OnMouse(GcEvent event) {
        
    }
    
}
