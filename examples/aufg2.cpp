#include "../include/stack1.hpp" 
#include "../include/list1.hpp"
//#include "../include/listnode.hpp"
#include <iostream>
//#include "../src/stack.ipp"





int main(){

     ProjectAlpha::stack<int>s;

     s.push(6);
     s.push(1);
     s.push(9);
     s.printStack();


}


//clang++ -std=c++17 -I./include src/stack.ipp examples/aufg2.cpp

//clang++ -std=c++17 -I./include include/stack1.hpp examples/aufg2.cpp