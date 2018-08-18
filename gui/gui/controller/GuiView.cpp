//
//  GuiView.cpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GuiView.hpp"

void GuiView::draw() {
    GcRect rect = this->rect;
    GcColor color = this->backgroundColor;
    
    this->renderer->DrawRect(rect, color);
    this->renderer->RenderFillRect(rect, color);
}

GuiView::GuiView(GcRect rect, GcColor backgroundColor) : rect(rect), backgroundColor(backgroundColor) {
    this->CreateView(rect, backgroundColor);
}

void GuiView::CreateView(GcRect rect, GcColor backgroundColor) {
    this->rect = rect;
    this->backgroundColor = backgroundColor;
}

// SetRenderer
void GuiView::SetRenderer(GcRenderer *renderer) {
    this->renderer = renderer;
}
