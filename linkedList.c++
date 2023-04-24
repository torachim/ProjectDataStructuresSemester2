#include <stdexcept>
#include <iostream>
#include <string>


template <typename E>
class AbstractListe { // enthält rein virtuelle methoden, die in den Subklassen überschrieben werden müssen
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
class Node { // definiert die Knoten der Liste
public:
    E element; //enthält ein Element, zwei zeiger die auf nächsten und vorherigen knoten der liste zeigen
    Node<E>* next;
    Node<E>* prev;

    Node(E element, Node<E>* next = nullptr, Node<E>* prev = nullptr) { //Konstruktor
        this->element = element;
        this->next = next;
        this->prev = prev;
    }
};

template <typename E>
class EinfachVerkettet : public AbstractListe<E> { //erbt von AbsractListe

protected:
    int size_;
    Node<E>* head; //Zeiger auf dem Kopf der liste sowie die Größenvariabel

public:
    EinfachVerkettet() : size_(0), head(nullptr) {} //leere Liste

    void add(E element) override { //fügt ein Element am Ende hinzu, indem sie die "addLast" Methode aufruft
        addLast(element);
    }

    void addFirst(E element) override { //fügt E am anfang
        head = new Node<E>(element, head); //neuen knoten mit E als wert erstellt und ihn als neuen kopf der liste setzt
        size_++;
    }

    void addLast(E element) override { //fügt element am ende hinzu
        if (head == nullptr) { //wenn liste leer dann,..
            head = new Node<E>(element); // neuen knoten am ende der liste herstellt
        } else { //oder..
            Node<E>* current = head; 
            while (current->next != nullptr) { //Die liste ist nicht leer:
                current = current->next; // der nächste zeiger des letzten knotens
            }
            current->next = new Node<E>(element); //wird auf den neuen knoten gesetzt
        }
        size_++; //Größe der Liste wird entspechend erhöht
    }

    E remove(int index) override { //entfernt Element  an der angegebenen Position in der Liste
        if (index < 0 || index >= size_) { //es wierd überprrüft, ob der angegebene index im gültigen bereich der liste liegt
            throw std::out_of_range("Index out of range"); //out of range ausnahme, fehler meldung
        }
        if (index == 0) { //wenn index gleich 0 null
            return removeFirst(); // methode aufgerufen, entfernt das erste element, siehe z.84
        }
        Node<E>* prev = nullptr;  //neuer zeiger prev, zeigt auf nullptr 
        Node<E>* current = head; //neuer zeiger current, wird auf das kopfelement gesetzt
        for (int i = 0; i < index; i++) { //Schleife, liste wird durchlaufen um elemnt zu finden
            prev = current; //prev wird jedesmal auf current gesetzt  um es um ein element zu verschieben
            current = current->next;
        }
        E removed = current->element; //gesuchte element wird in removed gespeichert um es zurückzugeben
        prev->next = current->next; //next zeiger vor dem Element wird auf das nachfolger element gesetzt sodass das zu löschende element herausgeschnitten wird
        delete current; // das zu löschende element wird gelöscht
        size_--; //größe der liste wird reduziert
        return removed; //entfernte element wird zurückgegeben 
    }

    E removeFirst() override {
        if (head == nullptr) { //wenn die Liste leer ist= head zeigt auf nullptr
            throw std::out_of_range("List is empty"); //ausnahme 
        }
        E removed = head->element; //wenn nichtt leer, wert des elements wird gespeichert
        Node<E>* temp = head;  //aktuelle kopfzeiger
        head = head->next; //wird auf den nachfolgerknoten des ersten knotens  umgestellt
        delete temp; // der knoten der auf head mal verwiesen hat, wird gelöscht
        size_--; //Größe der Liste wird reduziert
        return removed; //wird returned, also das entfernte element
    }

    E get(int index) const override { // gibt das Element zurück
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range"); //ausnahme wie zuvor
        }
        Node<E>* current = head; // 
        for (int i = 0; i < index; i++) { // wie ab z. 72
            current = current->next; //findet knoten und gibt dessen wert zurück
        }
        return current->element;
    }

    int size() const override { //gibt wert zurück
        return size_;
    }
};

//******************************************************************************************

template <typename E>
class DoppeltVerkettet : public EinfachVerkettet<E> {
private:
    Node<E>* tail; // Tail zeigt auf den letzten knoten

public:
    DoppeltVerkettet() : EinfachVerkettet<E>(), tail(nullptr) {} //Konstruktor= Tail wird auf nullptr gesetzt

    void add(E element) override {  //addLast, addFirst, remove, removeFirst, removeLst wird überschrieben
        addLast(element); //überschreibt add von basisklasse EinfachVerkettet, indem sie die Methode addLast aufruft, sodass element am ende der liste hinzufügen
    }

    void addFirst(E element) override {
        if (this->head == nullptr) { //wenn Liste leer ist..
            this->head = new Node<E>(element); //neues Knoten erstellt
            this->tail = this->head; //head und tail pointer werden auf neuen knoten gesetzt
        } else { //wenn liste nicht leer..
            this->head = new Node<E>(element, this->head, nullptr); //neuer knoten und wird als neues head der liste gesetzt
            this->head->prev = nullptr; //next zeiger wird auf aktuelle head gesetzt, prev zeiger auf nullptr. der prev zeigerdes vorherigen head knotens wird nun auf neuen head gesetzt
}
this->size_++; //größe wird um eins erhöht
}
void addLast(E element) override {
    if (this->tail == nullptr) { //wenn liste leer ist..
        this->tail = new Node<E>(element); //neuer knoten,vorgänger element wird auf dass aktuelle tail element gesetzt und next element auf nullptr gesetzt
        this->head = this->tail; //beide zeiger zeigen auf knoten
    } else { //wenn liste nicht leer..
        Node<E>* newTail = new Node<E>(element, nullptr, this->tail); //knoten erstellt, 3 argumente , element= gibt wert an, nullptr=knoten kein nachfolger, this->tail=vorgängerknoten ist aktuelle tail
        this->tail->next = newTail; // vorgänger knoten ist tail-> next ptr(nachfolger) davon wird auf neuen knoten gesetzt
        this->tail = newTail; //der tail wird dann auf den neuen knoten gesetzt bzw aktualisiert 
    }
    this->size_++; // größe um eins erhöht
}

E remove(int index) override { //entfernt knoten an den angegebenen index
    if (index < 0 || index >= this->size_) { //index kleiner als 0, größer oder kleiner als größe von liste, fehlermeldung
        throw std::out_of_range("Index nicht auffindbar");
    }
    if (index == 0) { //wenn index null ist..
        return removeFirst(); //removeFirst fubktion aufgerufen
    }
    if (index == this->size_ - 1) { //wenn index dem letzten element entspricht :letzter knoten wird entfernt
        return removeLast(); //funktion wird aufgerufen
    }
    Node<E>* prev = nullptr; //variabel prev wird initialisiert und auf nullptr gesetzt, vorgänger des aktuellen knoten gespeichert
    Node<E>* current = this->head; // current wird initalisiert und auf erstes element der liste gesetzt
    for (int i = 0; i < index; i++) { //schleife läuft von null bis index
        prev = current; //wechselt akutellen knoten auf nächsten knoten
        current = current->next; //während der vorgänger auf den vorherigen knoten gesetzt wird
    }
    E removed = current->element; //Wert des aktuellen knotens wird in variabel removed gespeichert
    prev->next = current->next; //zeiger auf nächsten knoten(next) des vorgängers wird auf knoten gesetzt der nach akutellen knoten kommt
    current->next->prev = prev; //der zeiger auf vorherigen knoten des knotens, der nach dem aktuellen knoten kommt wird auf vorgänger gesetzt
    delete current; //knoten wird gelöscht
    this->size_--; //größe reduziert
    return removed; //entfernter Wert wird zurückgegeben
}

E removeFirst() override { //entfernt den erste knoten aus der liste
    if (this->head == nullptr) { //wenn liste leer, fehlermeldung
        throw std::out_of_range("Liste ist leer");
    }
    E removed = this->head->element; //erste element entfernt: Element des ersten knoten in removed gespeichert
    Node<E>* temp = this->head; //variabel erweist auf ersten knoten
    this->head = this->head->next; //head  verschiebt sich auf das nächsten knoten, zweiter knoten ist head
    if (this->head == nullptr) { //wenn neue kopf der liste nullptr ist, also es gibt keinen nächsten knoten in der liste :
        this->tail = nullptr; //wenn einziges knoten in liste: tail zeigt auf nullptr
    } else {
        this->head->prev = nullptr; //wenn weiterer knoten da, prev zeiger des neuen ersten knoten zeigt auf nullptr, um zu zeigen, dass erste knoten in der liste ist
    }
    delete temp; //wird gelöscht
    this->size_--; //größe der liste wird verringert um 1
    return removed; //wert wird zurückgegeben
}

E removeLast() {
    if (this->tail == nullptr) { //wenn liste leer ist, fehlermeldung
        throw std::out_of_range("Liste ist leer");
    }
    E removed = this->tail->element; //element des letzten knoten wird in removed gespeichert
    Node<E>* temp = this->tail; //zeiger temp wird erstellt, der aud knoten zeigt den wir entfernen wollen
    this->tail = this->tail->prev; //zeiger tail wird auf vorgänger des aktuellen tail gesetzt, letzte knoten is entfernt und neue knoten ist der vorgänger des alten letzten knoten
    if (this->tail == nullptr) { //wenn tail nullptr ist= einziges knoten in er liste
        this->head = nullptr; //head wird dann auuf nullptr gesetzt
    } else { //andersfalls
        this->tail->next = nullptr; //next zeiger des neuen tail auf nullptr um zu zeigen, dass es keinen nachfolger gibt
    }
    delete temp; //knoten auf dem temp zeigt wird freigegeben bzw knoten gelöscht
    this->size_--; // um eins reduziert
    return removed; //wert zurückgegeben
}
};



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ main



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
