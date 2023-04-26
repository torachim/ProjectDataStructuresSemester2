#include "../include1/stack1.hpp"
#include "../include1/list1.hpp"
//#include "../include/listnode.hpp"
#include <iostream>
//#include "../src/stack.ipp"
#include kaka
#include "iostream"


using namespace ProjectAlpha;

int main(){

     stack<int>s;

     s.push(6);
     s.push(1);
     s.push(9);
     s.drucke();


}


//clang++ -std=c++17 -I./include src/stack.ipp examples/aufg2.cpp

//clang++ -std=c++17 -I./include include1/stack1.hpp examples/aufg2.cpp