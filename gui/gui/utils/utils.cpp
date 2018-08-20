//
//  utils.cpp
//  gui
//
//  Created by working on 2018/8/21.
//  Copyright © 2018年 working. All rights reserved.
//

#include "utils.hpp"

bool PointInRect(GcPoint point, GcRect rect) {
    
    int x = point.x;
    int y = point.y;
    int rectX = rect.x;
    int rectY = rect.y;
    int width = rect.width;
    int height = rect.height;
    
    if (x >= rectX && x <= width + rectX && y >= rectY && y <= rectY + height) {
        return true;
    } else {
        return false;
    }
}
