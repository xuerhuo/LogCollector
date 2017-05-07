//
// Created by erhuo on 2017/5/6.
//

#include <iostream>
#include <cstring>
#include "OutPut.h"
#include "LogCollector.h"
#include "lib/hiredis/hiredis.h"

void OutPut::output(std::string value) {
    if (strcmp(option_my.outputype, "screen") == 0) {
        this->screen_output(value);
    }
    redisContext *c = redisConnect("127.0.0.1", 6379);
    if (c == NULL || c->err) {
        if (c) {
            printf("Error: %s\n", c->errstr);
            // handle error
        } else {
            printf("Can't allocate redis context\n");
        }
    }
}

void OutPut::screen_output(std::string value) {
    std::cout << value << std::endl;
}

#pragma clang diagnostic pop