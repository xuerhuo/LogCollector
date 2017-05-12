//
// Created by erhuo on 2017/5/3.
//

#ifndef LOGCOLLECTOR_TOOLS_H
#define LOGCOLLECTOR_TOOLS_H

#include "getopt.h"
#include "LogCollector.h"

class Tools {
public:
    static void printarray(int len, char **arr);

    static bool optinit(int arg, char **argv);

    static void usage();

    unsigned long getEnds(char *pathfile);

    static std::string ltos(long l);

    static unsigned long long stoull(std::string str);

    static void debug();
};

const struct option long_options[] = {
        {"logfile",        required_argument, NULL, CONFIG_LOGFILE},
        {"outputype",      required_argument, NULL, CONFIG_OUTPUTYPE},
        {"redis_host",     required_argument, NULL, CONFIG_REDISHOST},
        {"redis_port",     required_argument, NULL, CONFIG_REDISPORT},
        {"redis_password", required_argument, NULL, CONFIG_REDISPASSWORD},
        {"logrediskey",    required_argument, NULL, CONFIG_LOGREDISKEY},
        {"ppushbuffernum", required_argument, NULL, CONFIG_PUSHBUFFERNUM},
        {"preadrow",       required_argument, NULL, CONFIG_READROW},
};
#endif //LOGCOLLECTOR_TOOLS_H
