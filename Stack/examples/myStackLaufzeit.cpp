#include "../include/stack.hpp" 
#include <iostream>
#include <chrono>


using namespace ProjectAlpha;

int main(){

     stack<int>s;

    // Messung der Zeit für das Pushen von x Elementen auf den Stack
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 10000000; ++i)
    {
        s.push(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Zeit für das Pushen: " << duration << " Mikrosekunden\n";

    // Messung der Zeit für das Abfragen der Größe des Stacks
    start = std::chrono::high_resolution_clock::now();
    int size = s.size();
    end = std::chrono::high_resolution_clock::now();
    auto duration_size = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Zeit für Rückgabe der Größe: " << duration_size << " Nanosekunden\n";


    // Messung der Zeit für das Popping von x Elementen vom Stack
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 10000000; ++i)
    {
        s.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Zeit für das Popping: " << duration << " Mikrosekunden\n";

    return 0;

}


//clang++ -std=c++17 -I./include  examples/myStackLaufzeit.cpp -o stack
