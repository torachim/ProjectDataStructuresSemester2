#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>


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

    Node(E element, std::shared_ptr<Node<E>> next = nullptr) {
        this->element = element;
        this->next = next;
    }
        
};

template <typename E>
class EinfachVerkettet : public AbstractListe<E> {
public:
    int size_;
    std::shared_ptr<Node<E>> head;


    EinfachVerkettet() : size_(0), head(nullptr) {}

    void add(E element) override {
        addLast(element);
    }

    void addFirst(E element) override {
        head = std::make_shared<Node<E>>(element, head);
        size_++;
    }

    void addLast(E element) override {
        if (head == nullptr) {
            head = std::make_shared<Node<E>>(element);
        } else {
            std::shared_ptr<Node<E>> current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = std::make_shared<Node<E>>(element);
        }
        size_++;
    }

    E remove(int index) override {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            return removeFirst();
        }
        std::shared_ptr<Node<E>> prev = nullptr;
        std::shared_ptr<Node<E>> current = head;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        E removed = current->element;
        prev->next = current->next;
        current.reset();
        size_--;
        return removed;
    }

    E removeFirst() override {
        if (list.head== nullptr) {
            throw std::out_of_range("list is empty");
        }
        else{
        E removed = head->element;
        head = head->next;
        size_--;
        return removed;
        }
    }

    E get(int index) const override {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        std::shared_ptr<Node<E>> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->element;
    }

    int size() const override {
        return size_;
    }

     void print() const{
        std::shared_ptr<Node<E>> current = head;
        while (current){
            std::cout<< current-> element <<" | ";
            current= current ->next;
        }
        std::cout<< std::endl;
    }


};
}