#include <stdio.h>
#include <math.h>

// Define the POINT structure
typedef struct {
    double x;
    double y;
} POINT;

// Define the TRIANGLE structure
typedef struct {
    POINT vertex1;
    POINT vertex2;
    POINT vertex3;
} TRIANGLE;

// Input point coordinates
POINT inputPoint() {
    POINT p;
    printf("Enter x and y coordinates: ");
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

// Output point coordinates
void outputPoint(POINT p) {
    printf("(%.2f, %.2f)", p.x, p.y);
}

// Calculate distance between two points
double distanceBetweenPoints(POINT p1, POINT p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Input triangle by entering coordinates of vertices
TRIANGLE inputTriangle() {
    TRIANGLE t;
    printf("Enter coordinates for Vertex 1:\n");
    t.vertex1 = inputPoint();
    printf("Enter coordinates for Vertex 2:\n");
    t.vertex2 = inputPoint();
    printf("Enter coordinates for Vertex 3:\n");
    t.vertex3 = inputPoint();
    return t;
}

// Output triangle vertices
void outputTriangle(TRIANGLE t) {
    printf("Triangle vertices:\n");
    printf("Vertex 1: "); outputPoint(t.vertex1); printf("\n");
    printf("Vertex 2: "); outputPoint(t.vertex2); printf("\n");
    printf("Vertex 3: "); outputPoint(t.vertex3); printf("\n");
}

// Calculate perimeter of triangle
double perimeterOfTriangle(TRIANGLE t) {
    double side1 = distanceBetweenPoints(t.vertex1, t.vertex2);
    double side2 = distanceBetweenPoints(t.vertex2, t.vertex3);
    double side3 = distanceBetweenPoints(t.vertex3, t.vertex1);
    return side1 + side2 + side3;
}

// Calculate area of triangle using Heron's formula
double areaOfTriangle(TRIANGLE t) {
    double side1 = distanceBetweenPoints(t.vertex1, t.vertex2);
    double side2 = distanceBetweenPoints(t.vertex2, t.vertex3);
    double side3 = distanceBetweenPoints(t.vertex3, t.vertex1);
    double s = (side1 + side2 + side3) / 2; // semi-perimeter
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// Main function for testing
int main() {
    // Input triangle
    TRIANGLE t = inputTriangle();
    printf("\n");

    // Output triangle vertices
    printf("Triangle: \n");
    outputTriangle(t);
    printf("\n");

    // Calculate and output perimeter
    double perimeter = perimeterOfTriangle(t);
    printf("Perimeter of Triangle: %.2f\n", perimeter);

    // Calculate and output area
    double area = areaOfTriangle(t);
    printf("Area of Triangle: %.2f\n", area);

    return 0;
}
