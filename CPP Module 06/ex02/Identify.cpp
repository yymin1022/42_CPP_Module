#include "Identify.hpp"

Base* generate(){
    static bool isFirst = true;
    if(isFirst){
        std::srand(std::time(0));
        isFirst = false;
    }

    int random = std::rand() % 3;
    if(random == 0)
        return new A();
    if(random == 1)
        return new B();
    return new C();
}

void identify(Base* p){
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }catch(const std::exception &e){
        try{
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }catch(const std::exception &e){
            try{
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }catch(const std::exception &e){
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}
