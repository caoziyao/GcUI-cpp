//
//  main.cpp
//  gui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

/*
 todo
 自定义的视频编码格式 .uipn
 涉及 单张图片 的编码和压缩, 自定义格式
 涉及 视频 的编码和压缩, 自定义格式 .guavideo
 */

#include <iostream>
#include <string>

#include "gui.hpp"
#include "view.hpp"

using std::string;


int main(int argc, const char * argv[]) {
    
    int w = 800;
    int h = 600;
    
    Gui gui(w, h, "sss");
    
    gui.run();
    return 0;
}

