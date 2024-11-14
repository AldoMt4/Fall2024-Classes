#include <stdio.h>
#include <math.h>

// Define the monomial structure
typedef struct {
    double coefficient;
    int exponent;
} MONO;

// Import a monomial by setting its coefficient and exponent
MONO importMonomial(double coefficient, int exponent) {
    MONO m;
    m.coefficient = coefficient;
    m.exponent = exponent;
    return m;
}

// Export a monomial by printing it
void exportMonomial(MONO m) {
    if (m.exponent == 0) {
        printf("%.2f\n", m.coefficient);
    } else if (m.exponent == 1) {
        printf("%.2fx\n", m.coefficient);
    } else {
        printf("%.2fx^%d\n", m.coefficient, m.exponent);
    }
}

// Calculate the product of two monomials
MONO multiplyMonomials(MONO m1, MONO m2) {
    MONO result;
    result.coefficient = m1.coefficient * m2.coefficient;
    result.exponent = m1.exponent + m2.exponent;
    return result;
}

// Calculate the quotient of two monomials (only if m2 is non-zero)
MONO divideMonomials(MONO m1, MONO m2) {
    MONO result;
    if (m2.coefficient != 0) {
        result.coefficient = m1.coefficient / m2.coefficient;
        result.exponent = m1.exponent - m2.exponent;
    } else {
        printf("Error: Division by zero monomial.\n");
        result.coefficient = 0;
        result.exponent = 0;
    }
    return result;
}

// Calculate the first derivative of a monomial
MONO derivativeMonomial(MONO m) {
    MONO result;
    if (m.exponent == 0) {  // Derivative of a constant is 0
        result.coefficient = 0;
        result.exponent = 0;
    } else {
        result.coefficient = m.coefficient * m.exponent;
        result.exponent = m.exponent - 1;
    }
    return result;
}

// Evaluate the monomial at a given x = x0
double evaluateMonomial(MONO m, double x0) {
    return m.coefficient * pow(x0, m.exponent);
}

// Main function for testing
int main() {
    MONO m1 = importMonomial(3.0, 2);  // 3x^2
    MONO m2 = importMonomial(2.0, 3);  // 2x^3

    printf("m1: ");
    exportMonomial(m1);
    printf("m2: ");
    exportMonomial(m2);

    MONO product = multiplyMonomials(m1, m2);
    printf("Product of m1 and m2: ");
    exportMonomial(product);

    MONO quotient = divideMonomials(m1, m2);
    printf("Quotient of m1 and m2: ");
    exportMonomial(quotient);

    MONO derivative = derivativeMonomial(m1);
    printf("First derivative of m1: ");
    exportMonomial(derivative);

    double x0 = 2.0;
    double value = evaluateMonomial(m1, x0);
    printf("Value of m1 at x = %.2f: %.2f\n", x0, value);

    return 0;
}
