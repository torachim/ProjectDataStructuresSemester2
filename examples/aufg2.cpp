#include "../include/stack1.hpp" 
//#include "../include/list1.hpp"
//#include "../include/sarahlist.hpp"
//#include "../include/listnode.hpp"
#include <iostream>
//#include "../src/stack.ipp"



using namespace ProjectAlpha;

int main(){

     stack<int>s;

     s.push(6);
     s.push(1);
     s.push(9);
     s.printStack();


}


//clang++ -std=c++17 -I./include  examples/aufg2.cpp -o stack
//./stack


 



