#include <functional>
#include <iostream>
#include <string>
#include <memory>
#include "../include/list.hpp"
#include "../include/listnode.hpp"
#include "../include/hashendeMengerealisation.hpp"

using namespace ProjectAlpha;

     template<class T>
     hashendeMengerealisation<T>::hashendeMengerealisation():  
          hashfkt(std::hash<T>()),
          num_buckets(32)
     {
          buckets = std::vector<List <T> >(num_buckets);
     }

     template<class T>
     listnode<T>::listnode(T data){
          data_ = data;
          next = nullptr;
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
               belegungsfaktor();
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
               std::shared_ptr<listnode <T> > aktuell = buckets[element].get_head();
               if(aktuell -> data_ == x){
                    buckets[element].remove_front();
               }
               std::shared_ptr<listnode <T> > hilfe = aktuell;
               while(aktuell != nullptr){
                    if(aktuell -> data_ == x){
                         buckets[element].remove_after(hilfe);
                         break;
                    }
                    hilfe = aktuell;
                    aktuell = aktuell -> next;
               }
          }
          else{
               belegungsfaktor();
               remove(x);
          }
     }

     template<class T>
     void hashendeMengerealisation<T>::belegungsfaktor(){
          double s = size();
          double a = num_buckets;
          std::vector <T> zwischenspeicher;
          for(int i = 0; i < num_buckets; i++){
               std::shared_ptr<listnode <T> > current = buckets[i].get_head();
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
          buckets = std::vector<List <T> >(num_buckets);

          for(const T &wort : zwischenspeicher){
               insert(wort);
          }

     }

     template<class T>
     void hashendeMengerealisation<T>::print() const{
          for(int i = 0; i < num_buckets; i++){
               buckets[i].print();
          }
          std::cout << "Hashtabelle gedruckt" << std::endl;
     }

     template<class T>
     size_t hashendeMengerealisation<T>::size() const{
          int j = 0;
          for(int i = 0; i < num_buckets; i++){
               std::shared_ptr<listnode <T> > current = buckets[i].get_head();
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
          std::shared_ptr<listnode <T> > current = buckets[Element].get_head();
          while(current != nullptr){
               if(current -> data_ == x){
                    return true;
               }
               else{
                    current = current -> next;
               }
          }
          return false;
     }



     template<class T>
     List<T>::List(){
          head = nullptr;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::get_head() const{
          return head;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::insert_front(T x){
          std::shared_ptr<listnode <T> > n = std::make_shared<listnode <T> >(x);
          if(head){
               n -> next = head;
               head = n;
          }
          head = n;
          return n;
     }

     template<class T>
     void List<T>::print() const{
          std::shared_ptr<listnode <T> > current = head;
          while(current){
               std::cout << current -> data_ << "->";
               current = current -> next;
          }
          std::cout << "null" << std::endl;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::remove_front(){
          if(not head){
               return nullptr;
          }
          std::shared_ptr<listnode <T> > neuerHead = head -> next;
          head = neuerHead;
          return neuerHead;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::next(const std::shared_ptr<listnode <T> >& vorhaerigerknoten){
          return vorhaerigerknoten -> next;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::insert_after(const std::shared_ptr<listnode <T> >& vorhaerigerknoten, T x){
          std::shared_ptr<listnode <T> > neuerNaechsterKnoten = std::make_shared<listnode <T> >(x);
          neuerNaechsterKnoten -> next = vorhaerigerknoten -> next;
          vorhaerigerknoten -> next = neuerNaechsterKnoten;
          return neuerNaechsterKnoten;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::remove_after(const std::shared_ptr<listnode <T> >& vorhaerigerknoten){
         std::shared_ptr<listnode <T> > loeschenKnoten = vorhaerigerknoten -> next;
         vorhaerigerknoten -> next = loeschenKnoten -> next;
         return vorhaerigerknoten -> next;
     }

     






