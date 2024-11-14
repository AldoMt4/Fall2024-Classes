#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Add this line to use bool

// Your other code follows...

// Define the FRACTION structure
typedef struct {
    int numerator;
    int denominator;
} FRACTION;

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to reduce a fraction
FRACTION reduceFraction(FRACTION frac) {
    int divisor = gcd(abs(frac.numerator), abs(frac.denominator));
    frac.numerator /= divisor;
    frac.denominator /= divisor;

    // Ensure the denominator is positive
    if (frac.denominator < 0) {
        frac.numerator = -frac.numerator;
        frac.denominator = -frac.denominator;
    }

    return frac;
}

// Function to input a fraction
FRACTION inputFraction() {
    FRACTION frac;
    printf("Enter numerator and denominator: ");
    scanf("%d %d", &frac.numerator, &frac.denominator);
    return frac;
}

// Function to output a fraction
void outputFraction(FRACTION frac) {
    printf("%d/%d", frac.numerator, frac.denominator);
}

// Function to check if a fraction is positive
bool isPositive(FRACTION frac) {
    return frac.numerator > 0;
}

// Function to check if a fraction is negative
bool isNegative(FRACTION frac) {
    return frac.numerator < 0;
}

// Function to find the first positive fraction
int findFirstPositiveFraction(FRACTION *fractions, int n) {
    for (int i = 0; i < n; i++) {
        if (isPositive(fractions[i])) {
            return i; // Return index of the first positive fraction
        }
    }
    return -1; // If no positive fraction found
}

// Function to compare fractions for sorting (ascending)
int compareFractionsAscending(const void *a, const void *b) {
    FRACTION frac1 = *(FRACTION *)a;
    FRACTION frac2 = *(FRACTION *)b;

    return (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
}

// Function to compare fractions for sorting (descending)
int compareFractionsDescending(const void *a, const void *b) {
    return compareFractionsAscending(b, a); // Reverse the order for descending
}

// Main function for testing
int main() {
    int n;
    printf("Enter the number of fractions: ");
    scanf("%d", &n);

    FRACTION *fractions = malloc(n * sizeof(FRACTION));

    // Input fractions
    for (int i = 0; i < n; i++) {
        printf("Fraction %d:\n", i + 1);
        fractions[i] = inputFraction();
        fractions[i] = reduceFraction(fractions[i]); // Reduce fraction immediately
    }

    // Output all fractions
    printf("\nAll fractions (reduced):\n");
    for (int i = 0; i < n; i++) {
        outputFraction(fractions[i]);
        printf("\n");
    }

    // Count positive and negative fractions
    int positiveCount = 0, negativeCount = 0;
    for (int i = 0; i < n; i++) {
        if (isPositive(fractions[i])) {
            positiveCount++;
        } else if (isNegative(fractions[i])) {
            negativeCount++;
        }
    }

    printf("\nNumber of positive fractions: %d\n", positiveCount);
    printf("Number of negative fractions: %d\n", negativeCount);

    // Find the first positive fraction
    int firstPositiveIndex = findFirstPositiveFraction(fractions, n);
    if (firstPositiveIndex != -1) {
        printf("First positive fraction: ");
        outputFraction(fractions[firstPositiveIndex]);
        printf("\n");
    } else {
        printf("No positive fraction found.\n");
    }

    // Find the smallest and largest fractions
    FRACTION smallest = fractions[0];
    FRACTION largest = fractions[0];

    for (int i = 1; i < n; i++) {
        if (compareFractionsAscending(&fractions[i], &smallest) < 0) {
            smallest = fractions[i];
        }
        if (compareFractionsAscending(&fractions[i], &largest) > 0) {
            largest = fractions[i];
        }
    }

    printf("Smallest fraction: ");
    outputFraction(smallest);
    printf("\n");
    
    printf("Largest fraction: ");
    outputFraction(largest);
    printf("\n");

    // Sort fractions in ascending order
    qsort(fractions, n, sizeof(FRACTION), compareFractionsAscending);
    printf("\nFractions sorted in ascending order:\n");
    for (int i = 0; i < n; i++) {
        outputFraction(fractions[i]);
        printf("\n");
    }

    // Sort fractions in descending order
    qsort(fractions, n, sizeof(FRACTION), compareFractionsDescending);
    printf("\nFractions sorted in descending order:\n");
    for (int i = 0; i < n; i++) {
        outputFraction(fractions[i]);
        printf("\n");
    }

    free(fractions);
    return 0;
}
