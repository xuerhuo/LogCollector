#include <iostream>
#include <unistd.h>
#include <cstring>
#include "Tools.h"
#include "base64.h"

Option option_my;
Logfile logfile;
Logfile runlog;
FileTools ftrunlog;
FileTools f;
OutPut out;
std::string sendbuffer = "";
int main(int args, char *argv[]) {
    unsigned int itemp;
    std::string temps;
    char *tempc;
    if (Tools::optinit(args, argv) != 0) {
        Tools::usage();
        return itemp;
    }
    out.init();
    if (init() != 0)
        return 0;
    std::cout << runlog.readrow << std::endl;
    while (1) {
        //Tools::debug();
        f.getoneline();
        if (f.eof) {
            sleep(1);
            if (sendbuffer != "") {
                out.output(sendbuffer);
                sendbuffer = "";
            }
        } else {

            if (f.readpline >= runlog.readrow) {
                sendbuffer += base64_encode(reinterpret_cast<const unsigned char *>(f.readtemp.c_str()),
                                            f.readtemp.length())
                f.readtemp + " ";
                if (f.readpline % option_my.pushbuffernum == 0) {
                    //std::cout << f.readtemp << std::endl;
                    out.output(sendbuffer);
                    sendbuffer = "";
                }
                ftrunlog.fileappend(Tools::ltos(f.readpline) + "\n");
            }
        }

        if (option_my.readrow > 0 && (long long) (f.readpline - runlog.readrow) >= option_my.readrow) {
            //read lines exit
            if (sendbuffer.length() > 0) {
                out.output(sendbuffer);
            }
            exit(0);
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