//
// Created by lmu on 18. 1. 8.
//

#include "json.h"
#include <gtest/gtest.h>

TEST(test, test){
    EXPECT_EQ(1,1);
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}