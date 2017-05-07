//
// Created by root on 17-5-7.
//

#ifndef LOGCOLLECTOR_BASE64_H
#define LOGCOLLECTOR_BASE64_H

#include <iostream>

std::string base64_encode(unsigned char const *, unsigned int len);

std::string base64_decode(std::string const &s);


#endif //LOGCOLLECTOR_BASE64_H
