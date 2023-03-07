#include <iostream>
#include "ConcreteSingleton.hpp"

int main(int, char**) {
    auto s = AbstractSingleton::GetInstance<ConcreteSingleton>();
    //auto s1 = AbstractSingleton::GetInstance<AbstractSingleton>(); - not possible, AbstractSingleton is not allowed as template type
    //auto s2 = AbstractSingleton::GetInstance<std::string>(); - also not possible, std::string does not have GetInstance() member function
}