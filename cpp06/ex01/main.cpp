#include "Serializer.hpp"

int main() {
    Data myData;
    myData.nbr = 42;
    myData.text = "Hello, World!";

    Data* originalPtr = &myData;

    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* recoveredPtr = Serializer::deserialize(raw);

    std::cout << "Orijinal address : " << originalPtr << std::endl;
    std::cout << "Returned address : " << recoveredPtr << std::endl;

    if (originalPtr == recoveredPtr) {
        std::cout << "✅ Success: Pointers matched!" << std::endl;
    } else {
        std::cout << "❌ Failure: Pointers didn't match!" << std::endl;
    }

    return 0;
}