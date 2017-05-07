//
// Created by erhuo on 2017/5/6.
//

#include <iostream>
#include <cstring>
#include "OutPut.h"
#include "LogCollector.h"

OutPut::OutPut() {
    if (strcmp(option_my.outputype, "redis") == 0) {
        this->redisinit();
    }
}
void OutPut::output(std::string value) {
    if (strcmp(option_my.outputype, "screen") == 0) {
        this->screen_output(value);
    }
}

void OutPut::screen_output(std::string value) {
    std::cout << value << std::endl;
}

void OutPut::redisinit() {
    this->redis = redisConnect("118.89.221.134", 6379);
    if (this->redis == NULL || this->redis->err != 0) {
        if (this->redis) {
            printf("Error: %s\n", this->redis->errstr);
            // handle error
        } else {
            printf("Can't allocate redis context\n");
        }
        this->redisinited = false;
    }
    this->redisinited = true;
}