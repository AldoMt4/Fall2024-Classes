#include <stdio.h>
#include <math.h>

// Define a monomial structure
typedef struct {
    double coefficient;
    int exponent;
} MONO;

// Define a polynomial structure
typedef struct {
    MONO terms[50];  // Array to hold monomial terms (assuming max 50 terms)
    int termCount;   // Actual number of terms
} POLY;

// Import a polynomial by entering terms interactively
POLY inputPolynomial() {
    POLY p;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &p.termCount);
    for (int i = 0; i < p.termCount; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%lf %d", &p.terms[i].coefficient, &p.terms[i].exponent);
    }
    return p;
}

// Export a polynomial by printing its terms
void outputPolynomial(POLY p) {
    for (int i = 0; i < p.termCount; i++) {
        MONO m = p.terms[i];
        if (i > 0 && m.coefficient > 0) printf(" + ");
        printf("%.2fx^%d", m.coefficient, m.exponent);
    }
    printf("\n");
}

// Add two polynomials
POLY addPolynomials(POLY p1, POLY p2) {
    POLY result;
    result.termCount = 0;
    int i = 0, j = 0;
    while (i < p1.termCount || j < p2.termCount) {
        if (i < p1.termCount && (j >= p2.termCount || p1.terms[i].exponent > p2.terms[j].exponent)) {
            result.terms[result.termCount++] = p1.terms[i++];
        } else if (j < p2.termCount && (i >= p1.termCount || p2.terms[j].exponent > p1.terms[i].exponent)) {
            result.terms[result.termCount++] = p2.terms[j++];
        } else {
            result.terms[result.termCount] = p1.terms[i];
            result.terms[result.termCount++].coefficient += p2.terms[j++].coefficient;
            i++;
        }
    }
    return result;
}

// Subtract two polynomials
POLY subtractPolynomials(POLY p1, POLY p2) {
    POLY result;
    result.termCount = 0;
    int i = 0, j = 0;
    while (i < p1.termCount || j < p2.termCount) {
        if (i < p1.termCount && (j >= p2.termCount || p1.terms[i].exponent > p2.terms[j].exponent)) {
            result.terms[result.termCount++] = p1.terms[i++];
        } else if (j < p2.termCount && (i >= p1.termCount || p2.terms[j].exponent > p1.terms[i].exponent)) {
            result.terms[result.termCount] = p2.terms[j];
            result.terms[result.termCount++].coefficient = -p2.terms[j++].coefficient;
        } else {
            result.terms[result.termCount] = p1.terms[i];
            result.terms[result.termCount++].coefficient -= p2.terms[j++].coefficient;
            i++;
        }
    }
    return result;
}

// Calculate first derivative of polynomial
POLY firstDerivative(POLY p) {
    POLY result;
    result.termCount = 0;
    for (int i = 0; i < p.termCount; i++) {
        if (p.terms[i].exponent > 0) {
            result.terms[result.termCount].coefficient = p.terms[i].coefficient * p.terms[i].exponent;
            result.terms[result.termCount].exponent = p.terms[i].exponent - 1;
            result.termCount++;
        }
    }
    return result;
}

// Evaluate polynomial at a given value of x
double evaluatePolynomial(POLY p, double x) {
    double result = 0.0;
    for (int i = 0; i < p.termCount; i++) {
        result += p.terms[i].coefficient * pow(x, p.terms[i].exponent);
    }
    return result;
}

// Main function for testing
int main() {
    printf("Input Polynomial 1:\n");
    POLY p1 = inputPolynomial();
    printf("Polynomial 1: ");
    outputPolynomial(p1);

    printf("\nInput Polynomial 2:\n");
    POLY p2 = inputPolynomial();
    printf("Polynomial 2: ");
    outputPolynomial(p2);

    // Adding the polynomials
    POLY sum = addPolynomials(p1, p2);
    printf("\nSum: ");
    outputPolynomial(sum);

    // Subtracting the polynomials
    POLY diff = subtractPolynomials(p1, p2);
    printf("Difference: ");
    outputPolynomial(diff);

    // Calculating the first derivative of polynomial 1
    POLY derivative = firstDerivative(p1);
    printf("First derivative of Polynomial 1: ");
    outputPolynomial(derivative);

    // Evaluate polynomial 1 at a specific value of x
    double x0;
    printf("\nEnter a value of x to evaluate Polynomial 1: ");
    scanf("%lf", &x0);
    double value = evaluatePolynomial(p1, x0);
    printf("Value of Polynomial 1 at x = %.2f: %.2f\n", x0, value);

    return 0;
}
