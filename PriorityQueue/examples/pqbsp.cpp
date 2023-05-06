#include<iostream>
#include "../include/pqreal.hpp"
#include<vector>
#include <chrono>


using namespace ProjectAlpha;

int main(){
    PQueue_realisation<int> pq = PQueue_realisation<int>();
    //pq.remove();
    /*pq.insert(7,5);
    pq.insert(100, 4);
    pq.insert(9, 10);
    pq.insert(22, 0);
    pq.insert(44, 22);*/
    for(size_t i = 0; i <= 10000000; i++){
        int x = rand() % 20;
        pq.insert(i,x);    
    }
    auto start = std::chrono::steady_clock::now();
    pq.remove();
    //pq.insert(5, 1);
    /*pq.insert(7, 5);
    pq.insert(100, 4);
    pq.insert(9, 10);
    pq.insert(22, 0);
    pq.insert(44, 22);
    pq.remove();*/
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
    //pq.print();

}