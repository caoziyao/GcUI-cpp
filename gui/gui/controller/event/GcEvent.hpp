//
//  GcEvent.hpp
//  gui
//
//  Created by working on 2018/8/18.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GcEvent_hpp
#define GcEvent_hpp

#include <stdio.h>
#include "GcEventType.hpp"

class GcEvent {
public:
    int type = EnumUnKnowEvent;
    int x = 0;
    int y = 0;
};


#endif /* GcEvent_hpp */
