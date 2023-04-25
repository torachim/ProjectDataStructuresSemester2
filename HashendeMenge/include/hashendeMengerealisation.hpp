#include <iostream>
#include "hashendemenge.hpp"
#include <memory>
#include <string>

using namespace ProjectAlpha;

    class hashendemengerela : public hashendemenge<std::string>{
        public:
            hashendemengerela();

            void insert(const std::string x);

        private:
            //hier folgen private Funktionen der Hashtabelle    

    };

    


