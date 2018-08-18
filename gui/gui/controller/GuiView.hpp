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

class GuiView{
public:
    int x;
    int y;
    int width;
    int height;
    GuiView(int x, int y, int width, int height);
    void draw();
private:
    void CreateView(int x, int y, int width, int height);
};

#endif /* GuiView_hpp */
