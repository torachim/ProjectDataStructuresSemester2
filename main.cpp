
#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>

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
        this->element = element;
        this->next = next;
        this->prev = prev;
    }
};

template <typename E>
class EinfachVerkettet : public AbstractListe<E> {
protected:
    int size_;
    std::shared_ptr<Node<E>> head;

public:
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
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        E removed = head->element;
        head = head->next;
        size_--;
        return removed;
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
};

template <typename E>
    class DoppeltVerkettet : public EinfachVerkettet<E> {
    private:
        std::shared_ptr<Node<E>> tail;

    public:
        DoppeltVerkettet() : EinfachVerkettet<E>(), tail(nullptr) {}

        void add(E element) override {
            addLast(element);
        }

        void addFirst(E element) override {
            if (this->head == nullptr) {
                this->head = std::make_shared<Node<E>>(element);
                this->tail = this->head;
            } else {
                this->head = std::make_shared<Node<E>>(element, this->head, nullptr);
                this->head->next->prev = this->head;
            }
            this->size_++;
        }

        void addLast(E element) override {
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

        E remove(int index) override {
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

        E removeFirst() override {
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

        int size() const override {
            return this->size_;
        }
    };




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
    }
    //Test Git




