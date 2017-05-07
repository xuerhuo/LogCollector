//
// Created by erhuo on 2017/5/3.
//

#ifndef LOGCOLLECTOR_LOCOLECTOR_H
#define LOGCOLLECTOR_LOCOLECTOR_H
typedef struct options {
    char *logfile = NULL;
    char *readtype = NULL;
    char *outputype;
    char *redishost;
    char *redisport;
    char *redispassword;
} Option;
enum {
    CONFIG_READTYPE, CONFIG_OUTPUTYPE, CONFIG_LOGFILE, CONFIG_REDISHOST, CONFIG_REDISPORT, CONFIG_REDISPASSWORD
};
extern Option option_my;

typedef struct logFile {
    char *path = NULL;
    unsigned long long size = 0;
    unsigned long long readrow = 0;
    unsigned long long coutline = 0;
} Logfile;
extern Logfile logfile, runlog;

int init();

#endif //LOGCOLLECTOR_LOCOLECTOR_H
