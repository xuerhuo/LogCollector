//
// Created by erhuo on 2017/5/4.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "FileTools.h"

void FileTools::fileTools() {
    //std::string touch("touch ");
    char *filepath = this->filepath;
    if (access(filepath, 04) != 0) {
        if (access(filepath, 00) != 0) {
            //std::cout<<strcat((char *) touch.c_str(), filepath)<<std::endl;
            //system(strcat((char *) touch.c_str(), filepath));
            this->fileappend("");
        }
        if (access(filepath, 04) != 0) {
            std::cout << "No such file or directory or permission denied 1" << filepath << std::endl;
            exit(-1);
        }
    }
    this->readpline = 0;
    this->ReadFile.open(filepath, std::ios::in);
    if (ReadFile.fail()) {
        std::cout << "No such file or directory or permission denied 2" << filepath << std::endl;
        exit(-1);
    }
}

unsigned long long FileTools::countline() {
    std::fstream File;
    std::string temp;
    unsigned long long n = 0;
    File.open(this->filepath, std::ios::in);
    if (File.fail())//文件打开失败:返回0
    {
        return 0;
    } else {
        while (std::getline(File, temp)) {
            n++;
        }
        return n;
    }
    File.close();
}

std::string FileTools::readline(unsigned long long x) {
    std::fstream File;
    std::string temp = "NULL";
    unsigned long long n = 0;
    File.open(this->filepath, std::ios::in);
    if (File.fail())//文件打开失败:返回0
    {
        exit(-1);
        return 0;
    } else {

        while (std::getline(File, temp)) {
            n++;
            if (n == x) {
                return temp;
            }
            if (!x > n) {
                return 0;
            }
        }
        File.close();
    }
}

void FileTools::fileappend(std::string append) {
    std::ofstream File;
    File.open(this->filepath, std::ios::app);
    if (File.fail()) {
        puts("write error");
        exit(-1);
    } else {
        File << append;
    }
    File.close();
}

std::string FileTools::getoneline() {
    std::string temp;
    this->lastreadpoint = this->ReadFile.tellg();
    //std::cout<<"pointlast:"<<this->lastreadpoint<<std::endl;
    if (std::getline(this->ReadFile, this->readtemp)) {
        this->eof = false;
    } else {
        //std::cout<<temp<<std::endl;
        this->eof = true;
        this->readtemp = "0";
    }
    this->ReadFile.seekg(-1, std::ios::cur);
    char c = this->ReadFile.peek();
    this->ReadFile.seekg(1, std::ios::cur);
    if (c != 0x0a) {//LF
        //std::cout<<"pointnow:"<<this->ReadFile.tellg()<<"contetn:"+this->readtemp<<this->ReadFile.peek()<<std::endl;
        this->ReadFile.seekg(this->lastreadpoint);
        //std::cout<<"pointmoved:"<<this->ReadFile.tellg()<<"contetn:"+this->readtemp<<std::endl;
        this->readtemp = "";
    } else {
        this->readpline++;
    }
    return this->readtemp;
}

void FileTools::clear() {
    this->ReadFile.close();
    this->ReadFile.open(this->filepath, std::ios::in);
    this->ReadFile.clear();
    this->ReadFile.seekg(0, std::ios::beg);
}