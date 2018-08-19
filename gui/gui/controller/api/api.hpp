//
//  api.hpp
//  gui
//
//  Created by working on 2018/8/19.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef api_hpp
#define api_hpp
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "GuiButton.hpp"
#include "LuaRef.hpp"
#include "GcGui.hpp"

using std::string;

class GuiApi {
public:
    GuiApi(GcGui *gui, LuaRef *lua);
    void RegisterAllApi();
    void RunScript(string path);
private:
    GcGui *gui;
    LuaRef *lua;
};

int DrawLine(lua_State *L);


#endif /* api_hpp */
