//
// Created by lmu on 18. 1. 8.
//

#ifndef CPPEXAMPLE_JSON_H
#define CPPEXAMPLE_JSON_H
#include <string>
#include <iostream>
#include <stack>
#define JSON_EMPTY_DATA 0x0010
using JSON_ERROR=int;
class Json{
private:
    std::string m_data;
    bool m_bValid;
    bool m_Changed;

    static bool checkValid(const std::string &jsonData);

public:
    Json(){};
    Json(const std::string& jsonData);
    Json(const char* jsonData);

    bool setData(const std::string& jsonData);
    bool setData(const char* jsonData);

    bool isValid();

};

#endif //CPPEXAMPLE_JSON_H
