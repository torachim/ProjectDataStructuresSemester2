#pragma once
#include <memory>
#include <iostream>

namespace ProjectAlpha{

template <class T>
class Node {        // Erstellen einer Node Hpp, da Stack als einfach verkettete Liste implementiert
public:
    Node(T element);         
    T element_;         // Enspricht eingefügeten Zahl, ein Element der Liste 
    std::shared_ptr<Node<T>> next;  // Nutzung shared poitner um auf das nachfolgende Element zu referieren

    };
}