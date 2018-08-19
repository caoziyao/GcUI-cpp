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

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <iostream>
#include <string>

#include "GcGui.hpp"
#include "GuiView.hpp"
#include "GcColor.hpp"
#include "GcRect.hpp"
#include "GuiButton.hpp"

#include "gtest/gtest.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"



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

void configFromLua(lua_State *L) {
    // int n1 = 1;
    // int n2 = 2;
    lua_getglobal(L, "config");
    // lua_pushstring(L, "aaaa");
    // 2 是参数数量
    // 1 是返回值的数量
    // 0 是 lua 中的错误处理函数，这里不提供所以传 0
    // 检查 pcall 的返回值以捕捉调用错误
    if(lua_pcall(L, 0, 3, 0) != 0) {
        printf("LUA ERROR: %s\n", lua_tostring(L, -1));
    }
    const char * t = lua_tostring(L, 0);
    int w = lua_tonumber(L, 1);
    int h = lua_tonumber(L, 2);
    lua_pop(L, 1);
    // printf("n1: %s\n", n1);
    // lua_pop(L, 2);
    // lua_pop(L, 3);
    printf("t: %s, h:%d w:%d\n", t, w, h);
}

int drawLine(lua_State *L) {
    printf("drawLine----\n");
    return 1;
}

void runLua() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    lua_register(L, "drawLine", drawLine);
    
    // 载入 lua 文件并执行
    if(luaL_dofile(L, "/Users/Shared/github/GcUI-cpp/gui/gui/script/config.lua")) {
        printf("LUA ERROR config: %s\n", lua_tostring(L, -1));
    }
    
    configFromLua(L);
}

int main(int argc,  char ** argv) {
    runLua();
//    RunTest(argc, argv);
    RunGui();
    
//    lua_close(L);
    return 0;
}

