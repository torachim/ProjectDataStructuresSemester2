#ifndef PQUEUE_REAL
#define PQUEUE_REAL
#include <iostream>
#include "pqabstract.hpp"
#include "PQueuenode.hpp"
#include <vector>



using namespace ProjectAlpha;

    /// @brief Klasse welche eine Priority Queue realisiert 
    /// @tparam T Daten eines Knoten werden generisch gespeichert
    template<class T>

    class PQueue_realisation : public abstract_Pqueue<T>{
    public:

        /// @brief Knstruktor einer PriorityQueue
        PQueue_realisation();

        /// @brief Funktion welche die groesse der PriorityQueue zuruckgibt
        /// @return Groesse der PQ
        int get_size();

        /// @brief Funktion welche einen Knoten in die PriorityQueue hinzufuegt
        /// @param data Information welche in einem PQ Noten gespeichert wird
        /// @param prioritaet Information nach welcher die einzelnen Knoten geordnet werden
        void insert(T data, int prioritaet);

        /// @brief Funktion welche das Element mit der hoechsten Prioritaet entfernt
        /// @return Die data des entsprechenden Element
        T remove();

        /// @brief Funktion welche die PQ ausdruckt
        void print();

        

        

    private:

        /// @brief PriorityQueue
        std::vector<PQnode <T> > Schlange;

        /// @brief Groesse der PriorityQueue
        int size;

        /// @brief Funktion welche den Index des Elternknoten eines Knoten zurueck gibt
        /// @param i Index des Knoten
        /// @return int Index des Elternknoten
        int parent(int i);

        /// @brief Funktion welche den Index des rechten Kindes eines Knoten zurueckgibt
        /// @param i Index eines Knoten
        /// @return int Index des rechten Kindes
        int right_child(int i);

        /**
         * @brief Funktion welche den Index des linken Kindes eines Knoten zurueckgibt
         * 
         * @param i Index eines Knoten
         * @return int Index des linken Kindes
         */
        int left_child(int i);

        /**
         * @brief Funktion wlche die Heapeingenschaft nach dem Entfernen des Elementes mit der hoechsten Prioritaet wiederherstellt. Rekursiv
         * 
         * @param i Index des Elemtes auf welches die Funktion eingesetzt werden soll
         */
        void shift_down(int i);

        /**
         * @brief Funktion welche die Heapeigenschaft nach dem Einfuegen eines neuen Knoten wiederherstellt
         * 
         * @param i Index des Knoten auf welchen die Funktion eingesetzt werden soll 
         */
        void shift_up(int i);

    };





#endif

    /**
     * @brief Construct a new pqueue realisation<t>::pqueue realisation object
     * 
     * @tparam T 
     */
    template<class T>
    PQueue_realisation<T>::PQueue_realisation(){
        size = 0;
        //Schlange = std::vector<std::shared_ptr<PQnode <T> > >();
    }

    /**
     * @brief Construct a new PQnode<T>::PQnode object
     * data_ im Privat bekommt data selbiges gilt für prioritaet_
     * @tparam T 
     * @param data T ist generisch
     * @param prioritaet immer ein int 
     */
    template<class T>
    PQnode<T>::PQnode(T data, int prioritaet): data_(data), prioritaet_(prioritaet){
    }

    /**
     * @brief gibt die data_ eines Knoten zurueck
     * 
     * @tparam T generisch
     * @return T generisch
     */
    template<class T>
    T PQnode<T>::get_data(){
        return data_;
    }

    /**
     * @brief Gibt die Anzahl an Elementen der PriorityQueue zurueck
     * 
     * @tparam T 
     * @return int 
     */
    template<class T>
    int PQueue_realisation<T>::get_size(){
        return size;
    }

    /**
     * @brief Fuegt ein Element in die PriorityQueue ein
     * Es wird erst ein Knoten mit den entsprechenden Daten data und prioritaet erzeugt
     * Dieser Knoten wird hinten  in die PQ eingefuegt
     * Funktion shift_up wird aufgerufen um die Heapeigenschaft wieder herzustellen
     * size wird um eins erhoeht
     * @tparam T 
     * @param data Information des Knoten
     * @param prioritaet Prioritaet sprich wichtigkeit
     */
    template<class T>
    void PQueue_realisation<T>::insert(T data, int prioritaet){
        PQnode<T> p = PQnode<T>(data, prioritaet);
        Schlange.push_back(p);
        shift_up(size);
        size = size + 1;
    }

    /**
     * @brief Hilfsfunktion um den index des Elternknoten herauszufinden
     * Formel gibt Index des Elternknoten als Loesung
     * @tparam T 
     * @param i Index eines Knoten
     * @return int Index des Elternknoten
     */
    template<class T>
    int PQueue_realisation<T>::parent(int i){
        int t = (i - 1)/2;
        return t;
    }

    /**
     * @brief Hilfsfunktion um den Index des rechten Kindes zu bekommen
     * Formel gibt den Index des rechten Kindes als Loesung zurueck
     * @tparam T 
     * @param i Index eines Knoten
     * @return int Index des rechten Kindes
     */
    template<class T>
    int PQueue_realisation<T>::right_child(int i){
        int t = ((2 * i)+ 2);
        return t;
    }

    /**
     * @brief Hilfsfunktion um den Index des linken Kind zu bekommen 
     * Formel gibt den Index des linken Kindes als Loesung zurueck
     * @tparam T 
     * @param i Index eines Knoten
     * @return int Index des linken Kindes
     */
    template<class T>
    int PQueue_realisation<T>::left_child(int i){
        int t = ((2 * i)+ 1);
        return t;
    }

    /**
     * @brief Funktion welche die Prioritaet zurueckgibt
     * 
     * @tparam T 
     * @return int 
     */
    template<class T>
    int PQnode<T>::get_prioritaet(){
        return prioritaet_;
    }

    /**
     * @brief Funktion welche die Heap eigenschaft von unten wiederherstellt
     * Solange i > 0 also Das Element nicht die Wurzel ist und die die Prioriritaet des eingefuegten Knoten hoeher ist als die seines Elternknoten
     * Wird der Eingefuegte Knoten mit seinem Elternknoten getauscht. Das ganze wird so lange wiederholt bis eine der oben genannten Bedingungen nicht 
     * mehr gilt.
     * @tparam T 
     * @param i Index eines Knoten hier der Index des neu eingefuegten Knoten
     */
    template<class T>
    void PQueue_realisation<T>::shift_up(int i){
        while(i > 0 and (Schlange[i].get_prioritaet() > Schlange[parent(i)].get_prioritaet())){
            PQnode <T> hilfe = Schlange[parent(i)];
            Schlange[parent(i)] = Schlange[i];
            Schlange[i] = hilfe;
            i = parent(i);
        }
    }

    /**
     * @brief Funktion welche die Heapeigenschaft nach dem entfernen wieder herstellt
     * Eine Hilfsvariable max_index wird auf den Index des aufrufenden Knoten gesetzt. Wenn die Prioritaet des gegebenen Knoten niedriger 
     * ist als die seines linken Kindes wird max-indx auf den Index des linken Kindes gesetzt. Danach wird selbiges noch mit dem rechten
     * Kind von i ueberprueft. Wenn i und max_indx nicht der selbe Knoten ist sollen die beiden Knoten getauscht werden und die Funktion 
     * wird erneut aufgerufen.
     * @tparam T 
     * @param i Index eines Knoten hier der durch das entfernen hoch getauschte Knoten
     */
    template<class T>
    void PQueue_realisation<T>::shift_down(int i){
        int max_indx = i;
        int l = left_child(i);
        int r = right_child(i);
        if(l <= size and (Schlange[max_indx].get_prioritaet() < Schlange[l].get_prioritaet())){
            max_indx = l;
        }
        if(r <= size and (Schlange[max_indx].get_prioritaet() < Schlange[r].get_prioritaet())){
            max_indx = r;
        }
        if(i != max_indx){
           // std::swap(Schlange[i], Schlange[max_indx]);
            PQnode <T> hilfe = Schlange[max_indx];
            Schlange[max_indx] = Schlange[i];
            Schlange[i] = hilfe;
            shift_down(max_indx);
        }
    }

    /**
     * @brief Funktion welche das Element mit der hoechsten Prioritaet entfernt
     * Erst wird die data des zu entfernenden Knoten gespeichert. Dann wird der zu entfernende Knoten mit dem letzten Knoten getauscht.
     * Die size wird um eins reduziert und das letzte Element der PQ entfernt. Um die Heap Eigenschaft wieder herzustellen.
     * @tparam T 
     * @return T Die data des entfernten Knoten mit der hoechsten Prioritaet
     */
    template<class T>
    T PQueue_realisation<T>::remove(){
        if(size == 0){
            throw std::logic_error("Element aus leerer Liste kann nicht entfernt werden");
        }
        T result = Schlange[0].get_data();
        Schlange[0] = Schlange[size - 1];
        size = size - 1;
        Schlange.pop_back();
        shift_down(0);
        return result;
    }

    /**
     * @brief Funktion welche die PQ druckt
     * Funktion druckt die Priority Queue nach ihrer Priorisierung aus
     * @tparam T 
     */
    template<class T>
    void PQueue_realisation<T>::print(){
        for(int k = 0; k < size; k++){
            std::cout << Schlange[k].get_data() << std::endl;
        }
    }
