//
// Created by lmu on 18. 1. 9.
//

#include <iostream>
#include <fstream>
#include <string>

#include "json.h"
int main(int argc, char** argv){
    std::string jsonFileName;
    std::cout << "File Name : " << std::endl;
    std::cin >> jsonFileName;
    std::ifstream jsonFile{ jsonFileName };
    std::string jsonFileContents { std::istreambuf_iterator<char>(jsonFile),
                                   std::istreambuf_iterator<char> ()};
    Json json = jsonFileContents;
    std::cout << "Is json valid? : " << json.isValid()? "Yes" : "No" << std::endl;
    return 0;
}
