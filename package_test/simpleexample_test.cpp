#include <simpleexample.hpp>
#include <iostream>

int main(int argc, char **argv) {
    if(argc != 1) {
        std::cout << argv[0] << " takes no arguments.\n";
        return 1;
    }
    simpleexample::Simpleexample c;
    return c.get_number() != 6;
}
