#include <iostream>
#include <unistd.h>
#include <cstring>
#include "Tools.h"
#include "FileTools.h"
#include "OutPut.h"

Option option_my;
Logfile logfile;
Logfile runlog;
FileTools ftrunlog;
FileTools f;

int main(int args, char *argv[]) {
    unsigned int itemp;
    std::string temps;
    char *tempc;
    OutPut out;
    if (Tools::optinit(args, argv) != 0) {
        Tools::usage();
        return itemp;
    }

    if (init() != 0)
        return 0;
    std::cout << runlog.readrow << std::endl;
    while (1) {
        f.getoneline();
        if (f.eof) {
            exit(0);
        }
        if (f.readpline >= runlog.readrow) {
            std::cout << f.readpline << std::endl;
            out.output(f.readtemp);
            ftrunlog.fileappend(Tools::ltos(f.readpline) + "\n");
        }
    }

    return 0;
}

int init() {
    logfile.path = option_my.logfile;
    logfile.size = 0;
    logfile.readrow = 0;
    f.filepath = logfile.path;
    f.fileTools();
    if (access(logfile.path, 04) != 0) {
        std::cout << "Can not read the logfile" << std::endl;
        return -1;
    }
    //判断应该从某行读起
    runlog.path = strcat(logfile.path, ".runlog");
    ftrunlog.filepath = runlog.path;
    ftrunlog.fileTools();
    runlog.coutline = ftrunlog.countline();
    std::cout << runlog.coutline << "lines\n";
    if (runlog.coutline == 0) {
        runlog.readrow = 1;
    } else if (runlog.coutline == 1) {
        runlog.readrow = 2;
    } else {
        runlog.readrow = Tools::stoull(ftrunlog.readline(runlog.coutline - 1));
        runlog.readrow = runlog.readrow + 1;
    }
    return 0;
}

void chekcfile() {

}