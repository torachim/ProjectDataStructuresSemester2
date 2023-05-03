#include <gtest/gtest.h>
#include "../include/queue.hpp" 

using namespace ProjectAlpha;

//Test: werden die richtigen Elemente eingefügt und das richtige entfernt?

TEST(Queue,enqueue_dequeue){  

    queue<int>q;

     q.enqueue(6);
     q.enqueue(1);
     q.enqueue(9);
     
     EXPECT_EQ(q.dequeue(), 9);
     EXPECT_EQ(q.dequeue(), 1);
     EXPECT_EQ(q.dequeue(), 6);

}


//Test: wird die richtige Größe der Queue zurückgegeben?

TEST(Queue,size){

    queue<int>q;

    q.enqueue(1);
    q.enqueue(2);

    EXPECT_EQ(q.size(),2);

}



