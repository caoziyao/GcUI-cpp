//
//  GuiCheckbox.hpp
//  gui
//
//  Created by working on 2018/8/21.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GuiCheckbox_hpp
#define GuiCheckbox_hpp

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
    
    class GuiCheckbox: public GuiView{
    public:
        GuiCheckbox(GcRect rect, GcColor backgroundColor, GcColor checkedColor);
        void Initialize();
        void Draw();
        ~GuiCheckbox();
        void OnMouse(GcEvent event);
    private:
        GcRect rect;
        GcColor backgroundColor;
        GcColor checkedColor;
        bool checked = false;
    };
    
}

#endif /* GuiCheckbox_hpp */
