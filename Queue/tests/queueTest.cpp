#include <gtest/gtest.h>
#include "../include/queue.hpp" 


using namespace ProjectAlpha;

queue<int> q;


TEST(Queue,enqueue_dequeue){  


     q.enqueue(9);
     q.enqueue(0);
     q.enqueue(3);
     
     ASSERT_EQ(q.dequeue(), 9);
     ASSERT_EQ(q.dequeue(), 1);
     ASSERT_EQ(q.dequeue(), 6);

}

using namespace ProjectAlpha;

TEST(Queue,size){

    queue<int>q;

    q.enqueue(1);
    q.enqueue(2);

    EXPECT_EQ(q.size(),3);

}

//clang++ -std=c++17 -I./include  tests/queueTest.cpp -o queuet


