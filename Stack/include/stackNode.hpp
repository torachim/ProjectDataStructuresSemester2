#pragma once
#include <memory>
#include <iostream>

namespace ProjectAlpha{

template <class T>
class Node {
public:
    Node(T element);
    T element_;
    std::shared_ptr<Node<T>> next;

    };
}