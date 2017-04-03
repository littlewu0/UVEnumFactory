//
//  UVEnumFactory.h
//  EnumDemo
//
//  Created by littlewu0 on 2017/4/2.
//  Copyright © 2017年 littlewu0. All rights reserved.
//
//  Description:
//      提供将宏定义表示自动字符串化的功能
//      下面的宏定义包含三个部分：
//      1. 枚举定义
//      2. 将枚举值字符串化的函数声明和定义
//      3. 根据字符串获取枚举值的函数声明和定义
//  代码参考：http://stackoverflow.com/questions/147267/easy-way-to-use-variables-of-enum-types-as-string-in-c/202511#202511

#import <Foundation/Foundation.h>

// 定义枚举中的每一项
#define UV_ENUM_VALUE(name,assign) name assign,
// 将枚举值符号化
#define UV_ENUM_CASE(name,assign) case name: return #name;
// 将字符串转成对应枚举值
#define UV_ENUM_STRCMP(name,assign) if (!strcmp(str,#name)) return name;

// 枚举声明的宏定义，这个宏定义会定义相应的枚举类型
// 声明将枚举值符号化的函数
// 声明将符号转成枚举值的函数
#define UV_DECLARE_ENUM(EnumType,ENUM_DEF) \
    typedef enum { \
        ENUM_DEF(UV_ENUM_VALUE) \
    } EnumType; \
    \
    const char *uv_getStringOf##EnumType##Type(EnumType dummy); \
    EnumType uv_get##EnumType##Value(const char *string); \

 // 定义将枚举值符号化的函数
 // 定义将符号转成枚举值的函数
#define UV_DEFINE_ENUM(EnumType,ENUM_DEF) \
    const char *uv_getStringOf##EnumType##Type(EnumType value) \
    { \
        switch(value) \
        { \
            ENUM_DEF(UV_ENUM_CASE) \
            default: return ""; /* handle input error */ \
        } \
    } \
    EnumType uv_get##EnumType##Value(const char *str) \
    { \
        ENUM_DEF(UV_ENUM_STRCMP) \
        return (EnumType)0; /* handle input error */ \
    } \

// 使用举例
/*
in .h file
 
#define SOME_ENUM(XX) \
    XX(FirstValue,) \
    XX(SecondValue,) \
    XX(SomeOtherValue,=50) \
    XX(OneMoreValue,=100) \

 // SomeSnum is the name of the enum type
 UV_DECLARE_ENUM(SomeEnum,SOME_ENUM)
 
 in source file
 
 UV_DEFINE_ENUM(SomeEnum,SOME_ENUM)
 
 */
