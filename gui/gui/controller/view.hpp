//
//  view.hpp
//  gui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef view_hpp
#define view_hpp

#include <stdio.h>

class GcView{
public:
    GcView(int x, int y, int width, int height);
    void draw();
private:
    void CreateView();
};

#endif /* view_hpp */
