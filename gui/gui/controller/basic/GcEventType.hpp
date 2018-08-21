//
//  GcEventType.hpp
//  gui
//
//  Created by working on 2018/8/19.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GcEventType_hpp
#define GcEventType_hpp

#include <stdio.h>

namespace gc {
    typedef enum {
        // unknow event
        EnumUnKnowEvent = 0,
        
        // Keyboard events
        EnumKeyDown = 0x300,
        EnumKeyUp,
        EnumTextEditing,
        EnumTextInput,
        
        // Mouse events
        EnumMouseMotion = 0x400,
        EnumMouseButtonDown,
        EnumMouseButtonUp,
        EnumMouseWheel,
        
        // Clipboard events
        EnumClipboardUpdate = 0x900,
        
        // Drag and drop events
        EnumDropFile = 0x1000,
        EnumDropText,
        EnumDropBegin,
        EnumDropComplete,
        
    }GcEventType;
}


#endif /* GcEventType_hpp */
