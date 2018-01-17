//
// Created by lmu on 18. 1. 8.
//

#include "json.h"
#include <gtest/gtest.h>
#include <fstream>
using namespace std;
TEST(JSON1, JSON1_JSON_Test){
    ifstream jsonFile("example/map2_default.json");
    std::string jsonFileContents { std::istreambuf_iterator<char>(jsonFile),
                                   std::istreambuf_iterator<char> ()};
    Json json = jsonFileContents;
    EXPECT_EQ(true, json.isValid());
    jsonFile.close();
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}