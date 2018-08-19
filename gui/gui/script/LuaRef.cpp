//
//  LuaRef.cpp
//  gui
//
//  Created by working on 2018/8/19.
//  Copyright © 2018年 working. All rights reserved.
//

#include "LuaRef.hpp"

// 初始化
LuaRef::LuaRef() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    this->L = L;
}

// 载入 lua 文件并执行
void LuaRef::DoFile(string path) {
    lua_State *L  = this->L;
    if(luaL_dofile(L, path.c_str())) {
        cout << "LUA ERROR config: " <<  lua_tostring(L, -1) << endl;
//        printf("LUA ERROR config: %s\n", lua_tostring(L, -1));
    }
}

// close
void LuaRef::Close() {
    lua_State *L  = this->L;
    lua_close(L);
}

// 注册api
void LuaRef::Register(string funcName, lua_CFunction func) {
    lua_State *L  = this->L;
    lua_register(L, funcName.c_str(), func);
}
    
// 
void configFromLua(lua_State *L) {
    // int n1 = 1;
    // int n2 = 2;
    
//    // 读取函数
//    lua_getglobal(L, "config");
//    lua_pushstring(L, "aaaa");  // 压入第一个参数
//    // lua_pcall 运行Lua函数
//    // 第一个 是参数数量
//    // 第二个 是返回值的数量
//    // 第三个 是 lua 中的错误处理函数，这里不提供所以传 0
//    // 检查 pcall 的返回值以捕捉调用错误
//    if(lua_pcall(L, 1, 3, 0) != 0) {
//        printf("LUA ERROR: %s\n", lua_tostring(L, -1));
//    }
//    // 1 代表栈底
//    const char * t = lua_tostring(L, 1);
//    int w = lua_tonumber(L, 2);
//    int h = lua_tonumber(L, 3);
//    lua_pop(L, 1);
//    // printf("n1: %s\n", n1);
//    // lua_pop(L, 2);
//    // lua_pop(L, 3);
//    printf("t: %s, h:%d w:%d\n", t, w, h);
//
//    // 读取变量
//    lua_getglobal(L,"str");
//    std::string str = lua_tostring(L,-1);
//    std::cout<<"str = "<<str.c_str()<< std::endl;        //str = I am so cool~
//
//    //5.读取table
//    lua_getglobal(L,"tbl");
//    lua_getfield(L, -1,"name");
//    str = lua_tostring(L,-1);
//    std::cout<<"tbl:name = "<<str.c_str()<<std::endl; //tbl:name = shun
//
//    lua_getfield(L, -2,"id");
//    int num = lua_tonumber(L,-1);
//    printf("num:%d \n", num);
//
}

//void runLua() {
//    lua_State *L = luaL_newstate();
//    luaL_openlibs(L);
    
//    lua_register(L, "drawLine", drawLine);
    
    // 载入 lua 文件并执行
//    if(luaL_dofile(L, "/Users/Shared/github/GcUI-cpp/gui/gui/script/config.lua")) {
//        printf("LUA ERROR config: %s\n", lua_tostring(L, -1));
//    }
    
//    configFromLua(L);
//}

