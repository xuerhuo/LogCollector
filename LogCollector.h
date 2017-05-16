//
// Created by erhuo on 2017/5/3.
//

#ifndef LOGCOLLECTOR_LOCOLECTOR_H
#define LOGCOLLECTOR_LOCOLECTOR_H

#include "OutPut.h"
#include "FileTools.h"

typedef struct options {
    char *logfile = NULL;
    char *readtype = NULL;
    char *outputype = NULL;
    char *redishost = NULL;
    char *redisport = NULL;
    char *redispassword = NULL;
    char *logrediskey = NULL;
    char *ppushbuffernum = NULL;
    long pushbuffernum = 1;
    char *preadrow = NULL;
    long readrow = 0;
    char *predismaxnum;
    long redismaxnum = 0;
} Option;
enum {
    CONFIG_LOGREDISKEY,
    CONFIG_OUTPUTYPE,
    CONFIG_LOGFILE,
    CONFIG_REDISHOST,
    CONFIG_REDISPORT,
    CONFIG_REDISPASSWORD,
    CONFIG_PUSHBUFFERNUM,
    CONFIG_READROW,
    CONFIG_REDISMAXNUM
};
extern Option option_my;

typedef struct logFile {
    char *path = NULL;
    unsigned long long size = 0;
    unsigned long long readrow = 0;
    unsigned long long coutline = 0;
} Logfile;
extern Logfile logfile, runlog;
extern OutPut out;
extern FileTools f;
int init();

#endif //LOGCOLLECTOR_LOCOLECTOR_H
