//
//  GcColor.hpp
//  GcGui
//
//  Created by working on 2018/8/18.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GcColor_hpp
#define GcColor_hpp

#include <stdio.h>

namespace gc {
    class GcColor{
    public:
        int r;
        int g;
        int b;
        int a;
        GcColor(int r, int g, int b, int a);
    };

}
#endif /* GcColor_hpp */
