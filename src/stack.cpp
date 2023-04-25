//mithilfe einfach verketteter Liste
#include<iostream>
#include<stack.hpp>

using namspace ProjectAlpha;

    class stack{

        struct Node{
            int data;
            Node* next;
            Node(int d, Node* n = nullptr): data(d), next(n){}
        };

        Node* top; 

        stack(): top(nullptr){}


        void push(T data){
            Node* newNode = newNode (data,top); //Zeiger auf neuen Knoten 
            top= newNode;                       // Neuen Knoten als obersten makieren
        }

        int pull(){
            if(top==nullptr){                    //leer? oberster Knoten auf nullptr
                std::cout<< "Stack is empty." << std::endl;
                return -1;
            }
            else{
            T data = top ->data;           // data vorauf top zeigt, da oberste     //???????? T oder int ???????
            Node* temp = top;                // zeiger auf knoten der weg muss
            top = top->next;                // top zu einen danach wechseln
            return data;
            }
        }

        int size(){
            int size =0;           //zähler auf null
            Node* current = top;   // current auf ersten stellen, fängt am Anfang an
            while( current != nullptr){
                size++;
                current= current->next     // wandert eine Stelle weiter
            }
            return size;
        }   
}


