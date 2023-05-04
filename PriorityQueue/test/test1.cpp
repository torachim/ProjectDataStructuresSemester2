#include <gtest/gtest.h>
#include "../include/pqreal.hpp"

using namespace ProjectAlpha;

TEST(Pqueue, remove){

    PQueue_realisation<int> pq;

    pq.insert(5, 1);
    pq.insert(7, 5);
    pq.insert(100, 4);

    EXPECT_EQ(pq.remove(), 7);
    EXPECT_EQ(pq.remove(), 5);

}