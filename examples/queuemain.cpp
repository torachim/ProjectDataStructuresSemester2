#include <iostream>
#include "../include/queue1.hpp"


using namespace ProjectAlpha;

int main(){

     queue<int>q;

     q.enqueue(6);
     q.enqueue(1);
     q.enqueue(9);
     q.printQueue();


}

//clang++ -std=c++17 -I./include  examples/queuemain.cpp -o queue