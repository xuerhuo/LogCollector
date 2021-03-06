//
// Created by erhuo on 2017/5/6.
//

#include <iostream>
#include <cstring>
#include <unistd.h>
#include "OutPut.h"
#include "LogCollector.h"

void OutPut::init() {
    if (strcmp(option_my.outputype, "redis") == 0) {
        this->redisinit();
        if (!this->redisinited) {
            exit(-1);
        }
    }
    logrediskey = option_my.logrediskey;
}
void OutPut::output(std::string value) {
    if (strcmp(option_my.outputype, "screen") == 0) {
        this->screen_output(value);
    }
    if (strcmp(option_my.outputype, "redis") == 0) {
        this->redis_output(value);
    }
}

void OutPut::screen_output(std::string value) {
    std::cout << value << std::endl;
}

void OutPut::redis_output(std::string value) {
    std::string temp = option_my.logrediskey;
    this->redis_Command("llen " + temp);
    while (this->redisreply->integer >= option_my.redismaxnum) {
        sleep(2);
        this->redis_Command("llen " + temp);
    }
    this->redis_Command("lpush " + logrediskey + " " + value);
}

void OutPut::redisinit() {
    this->redis = redisConnect(option_my.redishost, atoi(option_my.redisport));
    if (this->redis == NULL || this->redis->err != 0) {
        if (this->redis) {
            printf("Redis Error: %s\n", this->redis->errstr);
            // handle error
        } else {
            printf("Can't allocate redis context\n");
        }
        this->redisinited = false;
        return;
    }
    if (option_my.redispassword) {
        std::string temp, sauth = "auth ";
        sauth += option_my.redispassword;
        temp = this->redis_Command(sauth);
        if (temp == "OK") {
            NULL;
        } else {
            this->redisinited = false;
            return;
        }
    }
    this->redisinited = true;
}

std::string OutPut::redis_Command(std::string cmd) {
    std::string temp;
    this->redisreply = (redisReply *) redisCommand(this->redis, cmd.c_str());
    if (this->redisreply == NULL) {
        puts("excute error");
        exit(-1);
    } else if (this->redisreply->type == REDIS_REPLY_INTEGER) {//return from integer
        temp = std::to_string(this->redisreply->integer);
    } else if (this->redisreply->type == REDIS_REPLY_STATUS) {//return from str
        temp = this->redisreply->str;
    } else if (this->redisreply->type == REDIS_REPLY_ERROR) {//has error
        temp = this->redisreply->str;
        std::cout << "redis has error info:" << temp << std::endl;
        exit(1);
    } else {
        std::cout << "unkonw error with redis" << std::endl;
        exit(1);
    }
    //freeReplyObject(this->redisreply);
    return temp;
}