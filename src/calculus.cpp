#include <emscripten.h>
#include <emscripten/bind.h>
#include <iostream>
#include <string>
#include <vector>

using namespace emscripten;
// void use_vector_double(const std::vector<double> &vec) {
//     std::cout << "size() = " << vec.size() << ", capacity()=" << vec.capacity() << "\n";
//     for (const auto &str : vec) {
//         std::cout << "vec[]=|" << str << "|\n";
//     }
// }

std::vector<double> get_derivative_function(const std::vector<double> &coefficients) {
    int degree = coefficients.size();
    std::vector<double> derivative(degree - 1, 0);
    
    for (int i = 0; i < degree - 1; i++) {
        // Derivative of a_n * x^n is n * a_n * x^(n-1)
        derivative[i] = coefficients[i] * (degree - 1 - i);
    }

    for (int i = 0; i < degree - 1; i++) { // Print up to degree - 1
        if (derivative[i] != 0) {
            std::cout << derivative[i] << "*x^" << (degree - 2 - i);
        }
    }

    return derivative;
}

EMSCRIPTEN_BINDINGS(my_module) {
    register_vector<double>("DoubleList");
    // emscripten::function("use_vector_double", &use_vector_double);
    function("get_derivative_function", &get_derivative_function);
}
