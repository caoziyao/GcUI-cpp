//
//  GuiView.hpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GuiView_hpp
#define GuiView_hpp

#include <stdio.h>
#include "GcRect.hpp"
#include "GcColor.hpp"
#include "GcRenderer.hpp"

class GuiView{
public:
    GcRect rect;
    GcColor backgroundColor;
    GuiView(GcRect rect, GcColor backgroundColor);
    void draw();
    void SetRenderer(GcRenderer *renderer);
private:
    GcRenderer *renderer = nullptr;
    void CreateView(GcRect rect, GcColor backgroundColor);
};

#endif /* GuiView_hpp */
