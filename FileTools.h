//
// Created by erhuo on 2017/5/4.
//

#ifndef LOGCOLLECTOR_FILETOOLS_H
#define LOGCOLLECTOR_FILETOOLS_H

#include   <fstream>


class FileTools {
public:
    char *filepath;
    std::fstream ReadFile;
    unsigned long long readpline;
    bool eof;
    std::string readtemp;

    void fileTools();

    unsigned long long int countline();

    std::string readline(unsigned long long x);

    void fileappend(std::string append);

    void clear();

    std::string getoneline();
};


#endif //LOGCOLLECTOR_FILETOOLS_H
