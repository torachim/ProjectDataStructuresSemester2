#include<iostream>
#include "../include/pqreal.hpp"
#include<vector>
#include<algorithm>
#include <utility>
#include <string_view>

using namespace ProjectAlpha;

int main(){
    PQueue_realisation<int> pq;
    PQnode<int> a = PQnode<int>(5,1);
    PQnode<int> b = PQnode<int>(7,5);
    PQnode<int> c = PQnode<int>(100,4);
    PQnode<int> d = PQnode<int>(9,10);
    PQnode<int> e = PQnode<int>(22,0);
    PQnode<int> f = PQnode<int>(44,22);
    pq.insert(a);
    pq.insert(b);
    pq.insert(c);
    pq.insert(d);
    pq.insert(e);
    pq.insert(f);
   // pq.print();

}