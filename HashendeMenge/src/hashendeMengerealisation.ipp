#include <functional>
#include <iostream>
#include <string>
#include "../include/hashendeMengerealisation.hpp"

namespace ProjectAlpha{

     template<class T>
     hashendeMengerealisation<T>::hashendeMengerealisation():  
          hashfkt(std::hash<T>()),
          num_buckets(32)
     {
          buckets = std::vector<List>(num_buckets);
     }

     template<class T>
     void hashendeMengerealisation<T>::insert(const T x){
          if(find(x)){
               std::cout << "Das Element existiert bereits!" << std::endl;
               return;
          }
          double s = size();
          double a = num_buckets;

          if((s/a)<0.75){
               buckets[hashfkt(x) % num_buckets].insert_front(x);
          }
          else {
               belegungsfaktor(x);
               insert(x);
          }
          
     }

     template<class T>
     void hashendeMengerealisation<T>::remove(const T& x){
          if(not find(x)){
               std::cout << "Das Element konnte nicht gefunden werden!" << std::endl;
               return;
          }
          double s = size();
          double a = num_buckets;
          if((s/a) > 0.25){
               int element = hashfkt(x) % num_buckets;
               ListNodeptr aktuell = buckets[element].get_head();
               if(aktuell -> data_ == x){
                    buckets[element].remove_front();
               }
               ListNodeptr hilfe = aktuell;
               while(aktuell != nullptr){
                    if(aktuell -> data_ = x){
                         buckets[element].remove_after(hilfe);
                         break;
                    }
                    hilfe = aktuell;
                    aktuell = aktuell -> next;
               }
          }
          else{
               belegungsfaktor(x);
               remove(x);
          }
     }

     template<class T>
     void hashendeMengerealisation<T>::belegungsfaktor(){
          double = size();
          double a = num_buckets;
          std::vector<T> zwischenspeicher;
          for(int i = 0; i < num_buckets; i++){
               ListNodeptr current = buckets[i].get_head();
               while(current != nullptr){
                    zwischenspeicher.push_back(current -> data_);
                    current = current -> next;
               }
          }
          if((s/a) >= 0.75){
               num_buckets = num_buckets * 2;
          }
          else{
               num_buckets = num_buckets * 0.5;
          }
          buckets = std::vector<List>(num_buckets);

          for(const T &wort : zwischenspeicher){
               insert(wort);
          }

     }

     template<class T>
     void hashendeMengerealisation<T>::print() const{
          for(int i = 0; i < num_buckets, i++){
               buckets[i].print();
          }
          std::cout << "Hashtabelle gedruckt" << std::endl;
     }

     template<class T>
     size_t hashendeMengerealisation<T>::size() const{
          int j = 0;
          for(int i = 0; i < num_buckets; i++){
               ListNodeptr current = buckets[i].get_head();
               while(current != nullptr){
                    j = j + 1;
                    current = current -> next;
               }
          }
          return j;
     }

     template<class T>
     bool hashendeMengerealisation<T>::find(const T& x)const{
          int Element = hashfkt(x) % num_buckets;
          ListNodeptr current = buckets[Element].get_head();
          while(current != nullptr){
               if(current -> data_ == x){
                    return true;
               }
               else{
                    current = current -> next;
               }
          }
          return falsee;
     }

     template<class T>
     listNode<T>::listNode(T data){
          data_ = data;
          next = nullptr;
     }

     template<class T>
     List<T>::List(){
          head = nullptr;
     }

     template<class T>
     ListNodeptr List<T>::get_head() const{
          return head;
     }

     template<class T>
     ListNodeptr List<T>::insert_front(T x){
          ListNodeptr n = std::make_shared<ListNode>(x);
          if(head){
               n -> next = head;
               head = n;
          }
          head = n;
          return n;
     }

     template<class T>
     void List<T>::print() const{
          ListNodeptr current = head;
          while(current){
               std::cout << current -> data_ << "->";
               current = current -> next;
          }
          std::cout << "null" << std::endl;
     }

     template<class T>
     ListNodeptr List<T>::remove_front(){
          if(not head){
               return nullptr;
          }
          ListNodeptr neuerHead = head -> next;
          head = neuerHead;
          return neuerHead;
     }

     template<class T>
     ListNodeptr List<T>::next(const ListNodeptr& vorhaerigerknoten){
          return vorhaerigerknoten -> next;
     }

     template<class T>
     ListNodeptr List<T>::insert_after(const ListNodeptr& vorhaerigerknoten, T x){
          ListNodeptr neuerNaechsterKnoten = std::make_shared<ListNode>(x);
          neuerNaechsterKnoten -> next = vorhaerigerknoten -> next;
          vorhaerigerknoten -> next = neuerNaechsterKnoten;
          return neuerNaechsterKnoten;
     }

     template<class T>
     ListNodeptr List<T>::remove_after(const ListNodeptr& vorhaerigerknoten){
         ListNodeptr loeschenKnoten = vorhaerigerknoten -> next;
         vorhaerigerknoten -> next = loeschenKnoten -> next;
         return vorhaerigerknoten -> next;
     }

     





//Hier Implementierung der Funktionen fortsetzen.
}