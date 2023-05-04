#include <gtest/gtest.h>
#include "../include/hashendeMengerealisation.hpp"

using namespace ProjectAlpha;

TEST(hashendeMengerealisation, insert){

    hashendeMengerealisation<std::string> n;
    n.insert("5");
    n.insert("10");
    n.insert("18");
    n.insert("100");
    n.insert("kein");
    n.insert("blas");

    EXPECT_EQ(n.size(), 6);
}

using namespace ProjectAlpha;

TEST(hashendeMengerealisation, remove){

    hashendeMengerealisation<std::string> n;
    n.insert("5");
    n.insert("10");
    n.insert("18");
    n.insert("100");
    n.insert("kein");
    n.insert("blas");
    n.remove("5");

    EXPECT_EQ(n.size(), 5);
}

TEST(hashendeMengerealisation, find){

    hashendeMengerealisation<std::string> n;
    n.insert("5");

    EXPECT_EQ(n.find("5"), true);

}