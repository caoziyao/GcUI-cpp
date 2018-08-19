//
//  main.cpp
//  GcGui
//
//  Created by working on 2018/8/17.
//  Copyright © 2018年 working. All rights reserved.
//

/*
 C++主要是用来完成支持上层脚本运行的底层框架搭建
 方案：c++ 调用 Lua 来写
 
 基本的渲染底层: SDL
 脚本解析框架: C++？ HTML+CSS Lua/JS?
 内存管理: 是否要在UI库中自行划定内存池、小内存分配器的概念
 事件管理: 选用全局的事件队列+局部事件队列
 布局管理: 借鉴Android的五大不同Layout
 动画管理: 借鉴iOS上的Core Animation
 单元测试: google test
 */

#include <iostream>
#include <string>

#include "GcGui.hpp"
#include "GuiView.hpp"
#include "GcColor.hpp"
#include "GcRect.hpp"
#include "GuiButton.hpp"

#include "gtest/gtest.h"
#include "LuaRef.hpp"
#include "api.hpp"

//using std::string;

// Runs all tests using Google Test.
int RunTest(int argc,  char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void RunGui() {
    int w = 800;
    int h = 600;
    
    GcGui GcGui(w, h, "sss");
    GcRect rect(10, 10, 120, 230);
    GcColor viewColor(255, 255, 255, 255);
    
    GuiView view(rect, viewColor);
    GcGui.AddView(&view);
    
    GcRect btnRect(15, 205, 100, 30);
    GcColor btnColor(12, 12, 100, 255);
    GuiButton btn(btnRect, btnColor);
    
    view.AddElements(&btn);
    GcGui.run();
}

void RunLua() {
    LuaRef lua;
    lua.Register("drawLine", drawLine);
    lua.DoFile("/Users/Shared/github/GcUI-cpp/gui/gui/script/config.lua");
}

int main(int argc,  char ** argv) {
    RunLua();
//    RunTest(argc, argv);
    RunGui();
    
    return 0;
}

