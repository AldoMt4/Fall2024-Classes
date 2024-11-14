#include <stdio.h>

// Define the fraction structure
typedef struct {
    int numerator;
    int denominator;
} FRACTION;

// Import a fraction by setting its numerator and denominator
FRACTION importFraction(int numerator, int denominator) {
    FRACTION f;
    f.numerator = numerator;
    f.denominator = denominator;
    return f;
}

// Export a fraction by printing it
void exportFraction(FRACTION f) {
    printf("%d/%d\n", f.numerator, f.denominator);
}

// Find the Greatest Common Divisor (GCD) to reduce fractions
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduce fraction to its simplest form
FRACTION reduceFraction(FRACTION f) {
    int divisor = gcd(f.numerator, f.denominator);
    f.numerator /= divisor;
    f.denominator /= divisor;
    return f;
}

// Add two fractions
FRACTION addFractions(FRACTION f1, FRACTION f2) {
    FRACTION result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return reduceFraction(result);
}

// Subtract two fractions
FRACTION subtractFractions(FRACTION f1, FRACTION f2) {
    FRACTION result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return reduceFraction(result);
}

// Multiply two fractions
FRACTION multiplyFractions(FRACTION f1, FRACTION f2) {
    FRACTION result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return reduceFraction(result);
}

// Divide two fractions
FRACTION divideFractions(FRACTION f1, FRACTION f2) {
    FRACTION result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    return reduceFraction(result);
}

// Find Least Common Multiple (LCM) for making denominators the same
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Make the denominators of two fractions the same
void makeSameDenominator(FRACTION *f1, FRACTION *f2) {
    int common_denominator = lcm(f1->denominator, f2->denominator);
    f1->numerator *= common_denominator / f1->denominator;
    f2->numerator *= common_denominator / f2->denominator;
    f1->denominator = f2->denominator = common_denominator;
}

// Check if a fraction is positive
int isPositive(FRACTION f) {
    return (f.numerator * f.denominator > 0) ? 1 : 0;
}

// Compare two fractions
int compareFractions(FRACTION f1, FRACTION f2) {
    makeSameDenominator(&f1, &f2);
    if (f1.numerator > f2.numerator) return 1;      // f1 > f2
    else if (f1.numerator < f2.numerator) return -1; // f1 < f2
    else return 0;                                   // f1 == f2
}

// Main function for testing
int main() {
    FRACTION f1 = importFraction(1, 2);
    FRACTION f2 = importFraction(1, 3);

    printf("f1: ");
    exportFraction(f1);
    printf("f2: ");
    exportFraction(f2);

    FRACTION sum = addFractions(f1, f2);
    printf("Sum: ");
    exportFraction(sum);

    FRACTION diff = subtractFractions(f1, f2);
    printf("Difference: ");
    exportFraction(diff);

    FRACTION product = multiplyFractions(f1, f2);
    printf("Product: ");
    exportFraction(product);

    FRACTION quotient = divideFractions(f1, f2);
    printf("Quotient: ");
    exportFraction(quotient);

    printf("Comparison (f1 ? f2): %d\n", compareFractions(f1, f2));
    printf("Is f1 positive? %d\n", isPositive(f1));

    return 0;
}
