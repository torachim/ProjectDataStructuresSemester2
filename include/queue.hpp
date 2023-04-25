#include <iostream>
#include <queuetemplate.hpp>

namespace ProjektAlpha{

    class queue{

        public:
         void enqueue (int data);
         auto dequeue ();
         int size();

        private:
        std::vector<int> data;
        Node* front;
        Node* back;

    }

}
