//
//  GuiView.cpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GuiView.hpp"

GuiView::GuiView(GcRect rect, GcColor backgroundColor) : rect(rect), backgroundColor(backgroundColor) {
//    this->CreateView(rect, backgroundColor);
}

// draw
void GuiView::Draw() {
    GcRect rect = this->rect;
    GcColor color = this->backgroundColor;
    
    // 画自己
    this->renderer->DrawRect(rect, color);
    this->renderer->RenderFillRect(rect, color);
    
    // 画 child
    for (GuiView *e : this->elements) {
        e->Draw();
    }
}

// 新建 view
void GuiView::CreateView(GcRect rect, GcColor backgroundColor) {
//    this->rect = rect;
//    this->backgroundColor = backgroundColor;
}

// SetRenderer
void GuiView::SetRenderer(GcRenderer *renderer) {
    this->renderer = renderer;
}

// 添加元素
void GuiView::AddElements(GuiView *element) {
    element->renderer = this->renderer;
    this->elements.push_back(element);
}

// event
void GuiView::OnMouse(GcEvent event) {
    // 子元素
    for (GuiView *e : this->elements) {
        e->OnMouse(event);
    }
}

void GuiView::OnKey(GcEvent event) {
    
}
