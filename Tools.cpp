//
// Created by erhuo on 2017/5/3.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include "Tools.h"

void Tools::printarray(int len, char **arr) {
    unsigned int i;
    for (i = 0; i < len; i++) {
        std::cout << arr[i] << std::endl;
    }
}

bool Tools::optinit(int arg, char **argv) {
    int opt, sex;
    while ((opt = getopt_long(arg, argv, "", long_options, NULL)) != -1) {
//        printf ("\nopt:%c, optarg:%s, optind:%d, opterr:%d, optopt:%c, argv[optind]:%s\n",
//                opt, optarg, optind, opterr, optopt, argv[optind-1]);
        switch (opt) {
            case CONFIG_LOGFILE:
                option_my.logfile = optarg;
                break;
            case CONFIG_OUTPUTYPE:
                option_my.outputype = optarg;
                break;
            default:
                return -1;
        }
    }
    if (option_my.logfile == NULL || option_my.outputype == NULL) {
        Tools::usage();
        exit(1);
    }
    return 0;
}

void Tools::usage() {
    puts("Usage:LogCollector --logfile pathtolog");
    puts("                   --outputype [screen]");
}

unsigned long Tools::getEnds(char *pathfile) {

}

std::string Tools::ltos(long l) {
    std::ostringstream os;
    os << l;
    std::string result;
    std::istringstream is(os.str());
    is >> result;
    return result;
}

unsigned long long Tools::stoull(std::string str) {
    unsigned long long result;
    std::istringstream is(str);
    is >> result;
    return result;
}