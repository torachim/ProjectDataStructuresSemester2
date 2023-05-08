#include <iostream>
#include <memory>
#include <string>
#include "../include/hashendeMengerealisation.hpp"

using namespace ProjectAlpha;

int main(){
    hashendeMengerealisation<std::string> n;
    n.insert("5");
    n.insert("10");
    n.insert("18");
    n.insert("100");
    n.insert("kein");
    n.insert("blas");
    n.insert("A");
    n.insert("B");
    n.insert("C");
    n.insert("D");
    n.insert("E");
    n.insert("F");
    n.insert("G");
    n.insert("H");
    n.insert("I");
    n.insert("J");
    n.insert("K");
    n.insert("L");
    n.insert("M");
    n.insert("N");
    n.insert("O");
    n.insert("P");
    n.insert("Q");
    n.insert("R");
    n.insert("S");
    n.insert("T");
    n.insert("U");
    n.insert("V");
    n.insert("W");
    //n.insert("W");
    n.remove("W");
    n.print();    
}

