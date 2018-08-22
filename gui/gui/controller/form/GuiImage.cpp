//
//  GuiImage.cpp
//  gui
//
//  Created by working on 2018/8/21.
//  Copyright © 2018年 working. All rights reserved.
// 图片

#include "GuiImage.hpp"

namespace gc {
    
    using namespace std;
    
    GuiImage::GuiImage(GcRect rect, GcColor color): GuiView(rect, color), rect(rect), color(color) {
    
    }
    
    GuiImage::~GuiImage(){
        
    }
    
    void GuiImage::Draw() {
        GcRect rect = this->rect;
        GcColor color = this->backgroundColor;
        
        this->renderer->DrawImage("/Users/Shared/github/GcUI-cpp/gui/gui/resources/image/brush.png", rect);
    }
    
    void GuiImage::Initialize(string imageUrl) {
        this->imageUrl = imageUrl;
    }
    
}
