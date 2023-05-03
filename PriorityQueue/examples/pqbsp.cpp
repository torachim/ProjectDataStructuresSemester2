#include<iostream>
#include "../include/pqreal.hpp"
#include<vector>



using namespace ProjectAlpha;

int main(){
    PQueue_realisation<int> pq = PQueue_realisation<int>();
    //pq.remove();
    pq.insert(5, 1);
    pq.insert(7, 5);
    pq.insert(100, 4);
    pq.insert(9, 10);
    pq.insert(22, 0);
    pq.insert(44, 22);
    pq.remove();
    pq.print();

}