//#include "../include/hashendemenge.hpp"
//#include "../include/hashendeMengerealisation.hpp"
//#include "../include/list.hpp"
//#include "../include/listnode.hpp"
#include <iostream>
#include <memory>
#include "../src/hashendeMengerealisation.ipp"

using namespace ProjectAlpha;

int main(){
    hashendeMengerealisation<int> n;
    n.insert(5);
    n.insert(10);
    n.insert(18);
    n.insert(100);
    n.print();    
}

//Hier Beispiel der Hashtabelle reinschreiben...