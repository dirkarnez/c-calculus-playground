#include <stdio.h>

void getDerivativeFunction(int *coefficients, int degree, int *derivative) {
    // Calculate the derivative
    for (int i = 0; i < degree - 1; i++) {
        // Derivative of a_n * x^n is n * a_n * x^(n-1)
        derivative[i] = coefficients[i] * (degree - 1 - i);
    }
}

int main() {
    // Example polynomial: y = 1*x^2 + 0*x^1 + 0 (represented as [1, 0, 0])
    int coefficients[] = {1, 0, 0}; // Represents 1*x^2
    int degree = sizeof(coefficients) / sizeof(coefficients[0]);
    
    // Prepare an array for the derivative
    int derivative[degree - 1]; // The degree of the derivative will be degree - 1

    // Calculate the derivative
    getDerivativeFunction(coefficients, degree, derivative);

    // Print the derivative
    printf("The derivative of the polynomial is: ");
    for (int i = 0; i < degree - 1; i++) { // Print up to degree - 1
        if (derivative[i] != 0) {
            printf("%d*x^%d ", derivative[i], (degree - 2 - i));
        }
    }
    printf("\n");

    return 0;
}
