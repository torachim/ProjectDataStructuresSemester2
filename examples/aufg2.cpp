#include "../include/stack.hpp"
#include "../include/list.hpp"
#include "../include/listnode.hpp"
#include <iostream>
#include "../src/stack.ipp"

using namespace ProjectAlpha;

int main(){

     stack<int> s;

     s.push(6);
     s.push(1);
     s.push(8);
     s.drucke();

}


//clang++ -std=c++17 -I./include src/stack.ipp examples/aufg2.cpp