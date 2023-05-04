#include <gtest/gtest.h>
#include "../include/stack.hpp" 

using namespace ProjectAlpha;

//Test: werden die richtigen Elemente eingefügt und das richtige entfernt?

TEST(Stack,push_pop){  

    stack<int>s;

     s.push(6);
     s.push(1);
     s.push(9);
     
     EXPECT_EQ(s.pop(), 9);
     EXPECT_EQ(s.pop(), 1);
     EXPECT_EQ(s.pop(), 6);

}


//Test: wird die richtige Größe des Stacks zurückgegeben?

TEST(Stack,size){

    stack<int>s;

    s.push(1);
    s.push(2);

    EXPECT_EQ(s.size(),2);

}


//clang++ -std=c++17 -I./include  tests/stackTest.cpp -o stackt


/*TEST(Stack,printStack){

    stack<int>s;

    s.push(1);

    EXPECT_EQ(1,s.printStack());
}*/

//EXPECT_TRUE für isEmpty Funktion Fehlermeldung


