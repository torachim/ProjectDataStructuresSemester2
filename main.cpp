#include <stdexcept>
#include <iostream>
#include <string>
#include "../include/abstractVerketteteListe.hpp"


namespace ProjectAlpha {

int main() {

    
    std::cout << "EinfachVerkettet Test:" << std::endl;
    AbstractListe<int>* list1 = new EinfachVerkettet<int>(); //element 1,2,3 wird hinzugefügt, int genutzt
    list1->add(1);
    list1->add(2);
    list1->add(3);
    list1->addFirst(0); //danach wird 0 als erstes hinzugefügt
    list1->addLast(4); //am ende die 4
    std::cout << "Listengröße: " << list1->size() << std::endl; //größe ausgegeben
    std::cout << "Liste Elemente: "; //schleife wird verwendet, um größe und elemente derliste auszugeben
    for (int i = 0; i < list1->size(); i++) {
        std::cout << list1->get(i) << " ";
    }
    std::cout << std::endl;
    list1->remove(2); //element 2 wird entfernt
    std::cout << "Listengröße: " << list1->size() << std::endl;
    std::cout << "Liste Elemente: ";
    for (int i = 0; i < list1->size(); i++) { //größe, elemente erneut
        std::cout << list1->get(i) << " ";
    }
    std::cout << std::endl << std::endl;

    // DoppeltVerkettet
    std::cout << "DoppeltVerkettet Test:" << std::endl;
    AbstractListe<std::string>* list2 = new DoppeltVerkettet<std::string>(); //string genutzt
    list2->add("Hallo");
    list2->add("Welt!");
    list2->addFirst("Start<");
    list2->addLast(">Ende");
    std::cout << "Listengröße: " << list2->size() << std::endl;
    std::cout << "Liste Elemente: ";
    for (int i = 0; i < list2->size(); i++) {
        std::cout << list2->get(i) << " ";
    }
    std::cout << std::endl;
    list2->remove(1); //Element an index 1 "world" wird entfernt
    std::cout << "Listengröße: " << list2->size() << std::endl;
    std::cout << "Liste Elemente: ";
    for (int i = 0; i < list2->size(); i++) {
        std::cout << list2->get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
};
 }
//Test Git 
