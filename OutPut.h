//
// Created by erhuo on 2017/5/6.
//

#ifndef LOGCOLLECTOR_OUTPUT_H
#define LOGCOLLECTOR_OUTPUT_H


#include <string>
#include "lib/hiredis/hiredis.h"

class OutPut {
    void screen_output(std::string value);
public:
    redisContext *redis;
    bool redisinited;

    OutPut();
    void output(std::string value);

    void redisinit();
};


#endif //LOGCOLLECTOR_OUTPUT_H
