#pragma once
#include <memory>
#include "../include/listnode.hpp"

namespace ProjectAlpha{

    template<class T>

    class List{

        public:
        List(): head(nullptr) {}
        std::shared_ptr<ListNode<T>> insertFront(T);
        std::shared_ptr<ListNode<T>> removeFront();   //7warum shared ptr ???
        std::shared_ptr<ListNode<T>> getHead();
        int size();  
        std::shared_ptr<ListNode<t>> next(const std::shared_ptr<ListNode<T>>&);
        void print() const;

        private:
        std::shared_ptr<<ListNode<T>> head;

    };
}