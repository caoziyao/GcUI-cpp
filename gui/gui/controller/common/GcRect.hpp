//
//  GcRect.hpp
//  gui
//
//  Created by working on 2018/8/18.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GcRect_hpp
#define GcRect_hpp

#include <stdio.h>

namespace gc {
    
    class GcRect{
    public:
        int x;
        int y;
        int width;
        int height;
        GcRect(int x, int y, int width, int height);
    };

}
#endif /* GcRect_hpp */
