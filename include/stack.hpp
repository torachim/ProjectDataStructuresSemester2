#include <iostream>
#include <stacktemplate.hpp>
#define SIZE 100      ////////////

namespace ProjektAlpha{

    class stack{

        public:
         void push (int data);
         auto pop ();
         int size();

        private:
        std::vector<int> data;
        Node* top;



    }

}


