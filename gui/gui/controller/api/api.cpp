//
//  api.cpp
//  gui
//
//  Created by working on 2018/8/19.
//  Copyright © 2018年 working. All rights reserved.
//

#include "api.hpp"

//extern GuiButton *btn;

namespace gc {
    
    using namespace std;
    static GuiView *view;
    
    int DrawLine(lua_State *L) {
        printf("drawLine----\n");
        return 1;
    }
    
    GuiApi::GuiApi(GcGui *gui, LuaRef *lua) {
        this->lua = lua;
        this->gui = gui;
        RegisterAllApi();
    }
    
    int CreateButton(lua_State *L) {
        int x = lua_tonumber(L, 1);
        int y = lua_tonumber(L, 2);
        int w = lua_tonumber(L, 3);
        int h = lua_tonumber(L, 4);
        
        GcRect btnRect(x, y, w, h);
        GcColor btnColor(255, 12, 100, 255);
        //    static GuiButton btn(btnRect, btnColor);
        auto btn = new GuiButton(btnRect, btnColor);
        
        //    btn = btnT;
        //    gui->views[0]->AddElements(&btn);
        btn->renderer = view->renderer;
        view->AddElements(btn);
        return 1;
    }
    
    // 注册api
    void GuiApi::RegisterAllApi() {
        LuaRef *lua = this->lua;
        lua->Register("drawLine", DrawLine);
        
        GcGui *gui = this->gui;
        view = gui->views[0];
        lua->Register("CreateButton", CreateButton);
    }
    
    // run script
    void GuiApi::RunScript(string path) {
        LuaRef *lua = this->lua;
        lua->DoFile(path);
    }
}

