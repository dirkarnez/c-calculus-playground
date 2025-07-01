#include <emscripten/bind.h>
#include <iostream>
#include <string>
#include <vector>

void use_vector_double(const std::vector<double> &vec) {
    std::cout << "size() = " << vec.size() << ", capacity()=" << vec.capacity() << "\n";
    for (const auto &str : vec) {
        std::cout << "vec[]=|" << str << "|\n";
    }
}
 
EMSCRIPTEN_BINDINGS(EmbindVectorStringDemo) {
    emscripten::register_vector<double>("DoubleList");
    emscripten::function("use_vector_double", &use_vector_double);
}
