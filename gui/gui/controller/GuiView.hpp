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
#include <vector>

#include "GcRect.hpp"
#include "GcColor.hpp"
#include "GcRenderer.hpp"
#include "GcEvent.hpp"

using std::vector;

class GuiView{
public:
    GcRect rect;
    GcColor backgroundColor;
    GcRenderer *renderer = nullptr;
    
    GuiView(GcRect rect, GcColor backgroundColor);
    virtual void Draw();
    void SetRenderer(GcRenderer *renderer);
    void AddElements(GuiView *element);
    vector<GuiView *> elements;   // elements
    
    // evnet
    virtual void OnMouse(GcEvent event);
    virtual void OnKey(GcEvent event);
private:
    void CreateView(GcRect rect, GcColor backgroundColor);
    
    
};

#endif /* GuiView_hpp */
