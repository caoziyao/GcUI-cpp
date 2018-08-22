//
//  GuiRadio.hpp
//  gui
//
//  Created by working on 2018/8/21.
//  Copyright © 2018年 working. All rights reserved.
//  单选

#ifndef GuiRadio_hpp
#define GuiRadio_hpp

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
    
    class GuiRadio: public GuiView{
    public:
        GuiRadio(GcRect rect, GcColor backgroundColor, GcColor checkedColor);
        void Initialize();
        void Draw();
        ~GuiRadio();
        void OnMouse(GcEvent event);
    private:
        GcRect rect;
        GcColor backgroundColor;
        GcColor checkedColor;
        bool checked = false;
    };
    
}

#endif /* GuiRadio_hpp */
