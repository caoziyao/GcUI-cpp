//
//  GuiImage.hpp
//  gui
//
//  Created by working on 2018/8/21.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef GuiImage_hpp
#define GuiImage_hpp

#include <stdio.h>
#include <string>
#include "GuiView.hpp"
#include "GcEvent.hpp"
#include "GcEventType.hpp"
#include "GcPoint.hpp"
#include "utils.hpp"
#include "GcRect.hpp"
#include "GcRenderer.hpp"

namespace gc {
    
    class GuiImage: public GuiView{
    public:
        GuiImage(GcRect rect, GcColor color);
        void Initialize(std::string imageUrl);
        void Draw();
        // evnet
//        void OnMouse(GcEvent event);
//        void OnKey(GcEvent event);
        ~GuiImage();
    private:
        GcRect rect;
        GcColor color;
        std::string imageUrl;
        
    };

}
#endif /* GuiImage_hpp */
