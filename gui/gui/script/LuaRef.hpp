//
//  LuaRef.hpp
//  gui
//
//  Created by working on 2018/8/19.
//  Copyright © 2018年 working. All rights reserved.
//

#ifndef LuaRef_hpp
#define LuaRef_hpp
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <stdio.h>
#include <iostream>
#include <string>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

using std::string;
using std::cout;
using std::endl;

class LuaRef {
public:
    LuaRef();
    void DoFile(string path);
    void Register(string funcName, lua_CFunction func);
    void Close();
private:
    lua_State *L;
};


#endif /* LuaRef_hpp */
