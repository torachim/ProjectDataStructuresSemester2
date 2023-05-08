#include "../include/queue.hpp"
#include <iostream>


using namespace ProjectAlpha;

int main(){

     queue<int>q;

     q.enqueue(6);
     q.enqueue(1);
     q.enqueue(9);
     q.printQueue();
     q.dequeue();
     q.enqueue(8);
     q.printQueue();
     std::cout<< "Queue size:" << q.size() << std::endl;

}

//clang++ -std=c++17 -I./include  examples/queuemain.cpp -o queue