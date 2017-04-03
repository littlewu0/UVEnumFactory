//
//  main.m
//  EnumToStringDemo
//
//  Created by 伍学俊 on 2017/4/2.
//  Copyright © 2017年 伍学俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UVEnumFactory.h"

#define SOME_ENUM(XX) \
    XX(FirstValue,) \
    XX(SecondValue,) \
    XX(SomeOtherValue,=100) \
    XX(OneMoreValue,=50) \

UV_DECLARE_ENUM(SomeEnum, SOME_ENUM)
UV_DEFINE_ENUM(SomeEnum, SOME_ENUM)

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        int a = uv_getSomeEnumValue("SomeOtherValue");
        printf("%d", a);
    }
    return 0;
}
