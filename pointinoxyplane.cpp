#include <stdio.h>
#include <math.h>

// Define the POINT structure
typedef struct {
    double x;
    double y;
} POINT;

// Import a point by entering coordinates
POINT inputPoint() {
    POINT p;
    printf("Enter x and y coordinates: ");
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

// Export a point by printing its coordinates
void outputPoint(POINT p) {
    printf("(%.2f, %.2f)\n", p.x, p.y);
}

// Calculate distance between two points
double distanceBetweenPoints(POINT p1, POINT p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Find the point symmetrical about the origin
POINT symmetricAboutOrigin(POINT p) {
    POINT sym;
    sym.x = -p.x;
    sym.y = -p.y;
    return sym;
}

// Find the point symmetrical about the x-axis
POINT symmetricAboutOx(POINT p) {
    POINT sym;
    sym.x = p.x;
    sym.y = -p.y;
    return sym;
}

// Find the point symmetrical about the y-axis
POINT symmetricAboutOy(POINT p) {
    POINT sym;
    sym.x = -p.x;
    sym.y = p.y;
    return sym;
}

// Main function for testing
int main() {
    // Input two points
    printf("Input Point 1:\n");
    POINT p1 = inputPoint();
    printf("Point 1: ");
    outputPoint(p1);

    printf("\nInput Point 2:\n");
    POINT p2 = inputPoint();
    printf("Point 2: ");
    outputPoint(p2);

    // Calculate distance between the two points
    double distance = distanceBetweenPoints(p1, p2);
    printf("\nDistance between Point 1 and Point 2: %.2f\n", distance);

    // Find symmetrical points
    POINT symOrigin = symmetricAboutOrigin(p1);
    POINT symOx = symmetricAboutOx(p1);
    POINT symOy = symmetricAboutOy(p1);

    printf("\nSymmetrical point of Point 1 about the origin: ");
    outputPoint(symOrigin);

    printf("Symmetrical point of Point 1 about the x-axis (Ox): ");
    outputPoint(symOx);

    printf("Symmetrical point of Point 1 about the y-axis (Oy): ");
    outputPoint(symOy);

    return 0;
}
