#include <iostream>
#include <stack>

int main(){

     std::stack<int>s;

     s.push(6);
     s.push(1);
     s.push(9);
     s.push(6);
     s.push(1);
     s.push(9);
     s.push(6);
     s.push(1);
     s.push(9);
     s.push(6);
     s.push(1);
     s.push(9);
     //s.printStack();
     s.pop();
     //s.printStack();
     //s.pop();
     //s.pop();
     //s.pop();
     std::cout<< "Stack size:" << s.size() << std::endl;
     


}


//clang++ -std=c++17 -I./include  examples/c++stackmain.cpp -o std::stack
//./std::stack


 



