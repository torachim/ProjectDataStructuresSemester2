#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>
#include "../include/sarahlist.hpp"

namespace ProjectAlpha{ 

template <typename E>
class AbstractListe {
public:
    virtual void add(E element) = 0;
    virtual void addFirst(E element) = 0;
    virtual void addLast(E element) = 0;
    virtual E remove(int index) = 0;
    virtual E removeFirst() = 0;
    virtual E get(int index) const = 0;
    virtual int size() const = 0;
};

template <typename E>
class Node {
public:
    E element;
    std::shared_ptr<Node<E>> next;
    std::shared_ptr<Node<E>> prev;

    Node(E element, std::shared_ptr<Node<E>> next = nullptr, std::shared_ptr<Node<E>> prev = nullptr) {
        //this->element = element;
        //this->next = next;
        //this->prev = prev;
    }
};

template <typename E>
    class DoppeltVerkettet : public EinfachVerkettet<E> {
    private:
        std::shared_ptr<Node<E>> tail;

    public:
        DoppeltVerkettet() : EinfachVerkettet<E>(), tail(nullptr) {}

        void add(E element)  {
            addLast(element);
        }

        void addFirst(E element) {
            if (this->head == nullptr) {
                this->head = std::make_shared<Node<E>>(element);
                this->tail = this->head;
            } else {
                this->head = std::make_shared<Node<E>>(element, this->head, nullptr);
                this->head->next->prev = this->head;
            }
            this->size_++;
        }

        void addLast(E element) {
            if (this->tail == nullptr) {
                this->tail = std::make_shared<Node<E>>(element);
                this->head = this->tail;
            } else {
                std::shared_ptr<Node<E>> newTail = std::make_shared<Node<E>>(element, nullptr, this->tail);
                this->tail->next = newTail;
                this->tail = newTail;
            }
            this->size_++;
        }

        E remove(int index)  {
            if (index < 0 || index >= this->size_) {
                throw std::out_of_range("Index out of range");
            }
            if (index == 0) {
                return removeFirst();
            }
            std::shared_ptr<Node<E>> prev = nullptr;
            std::shared_ptr<Node<E>> current = this->head;
            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }
            E removed = current->element;
            prev->next = current->next;
            if (current->next == nullptr) {
                this->tail = prev;
            } else {
                current->next->prev = prev;
            }
            current.reset();
            this->size_--;
            return removed;
        }

        E removeFirst()  {
            if (this->head == nullptr) {
                throw std::out_of_range("List is empty");
            }
            E removed = this->head->element;
            this->head = this->head->next;
            if (this->head == nullptr) {
                this->tail = nullptr;
            } else {
                this->head->prev = nullptr;
            }
            this->size_--;
            return removed;
        }

        int size() const  {
            return this->size_;
        }
    };



}
