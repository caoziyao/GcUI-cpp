//
//  GuiView.cpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GuiView.hpp"

void GuiView::draw() {
    
}

GuiView::GuiView(int x, int y, int width, int height) {
    this->CreateView(x, y, width, height);
}

void GuiView::CreateView(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
