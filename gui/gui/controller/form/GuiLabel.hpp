//
//  GuiLabel.hpp
//  gui
//
//  Created by working on 2018/8/23.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GuiLabel_hpp
#define GuiLabel_hpp


#include <stdio.h>
#include <string>
#include "GuiView.hpp"
#include "GcEvent.hpp"
#include "GcEventType.hpp"
#include "GcPoint.hpp"
#include "utils.hpp"
#include "GcRect.hpp"
#include "GcRenderer.hpp"

namespace gc {
    
    class GuiLabel: public GuiView{
    public:
        GuiLabel(GcRect rect, GcColor backgroundColor, std::string text);
        void Initialize();
        void Draw();
        ~GuiLabel();
        void OnMouse(GcEvent event);
    private:
        GcRect rect;
        GcColor backgroundColor;
        std::string text;
        bool checked = false;
    };
    
}


#endif /* GuiLabel_hpp */
