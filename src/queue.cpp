//mithilfe einfach verketteter Liste
#include<iostream>
#include<queue.hpp>



using namespace ProjectAlpha;

    class queue{

        struct Node{
            int data;
            Node* next;
            Node(int d, Node* n = nullptr): data(d), next(n){}
        }

        Node* front;
        Node* back;

        Queue(): front(nullptr), back(nullptr){}

        void enqueue(int data){

            Node* newNode = newNode (data);
            if(back == nullptr){
                front = newNode;
                back = newNode;
            }
            else{
                back->next = newNode;
                back = newNode;
            }
        }

        int dequeue(){

            if(front == nullptr){
                std::cout << "Queue is empty." << std::endl;
                return -1;
            }
            else{                                      //??????? else hin oder nicht
                int data= front->value;                              
                Node* temp = front;
                front= front->next
                if(front== nullptr){
                    back = nullptr;
                }
                return data;
            }

            int size(){
                int size =0;
                Node* current = front;
                while (current != nullptr){
                    size++;
                    current = current ->next;
                }
                return size;
            }
            
        }
    }
