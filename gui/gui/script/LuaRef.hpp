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


namespace gc {
//    using std::cout;
//    using std::endl;
//
    // typedef int (*lua_CFunction) (lua_State *L);
    
    class LuaRef {
    public:
        LuaRef();
        void DoFile(std::string path);
        void Register(std::string funcName, lua_CFunction func);
        void Close();
        //private:
        //    lua_State *L;
    };

}
//using std::string;


#endif /* LuaRef_hpp */
