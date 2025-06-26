#include "Base.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));

    Base* p = generate();
    
    identify(p);
    identify(*p);

    delete p;

    return 0;
}