#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100 // Maximum number of points

// Define the POINT structure
typedef struct {
    double x;
    double y;
} POINT;

// Function to input a point
POINT inputPoint() {
    POINT p;
    printf("Enter x and y coordinates: ");
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

// Function to output a point
void outputPoint(POINT p) {
    printf("(%.2f, %.2f)", p.x, p.y);
}

// Function to count points with positive x-coordinate
int countPositiveX(POINT points[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].x > 0) {
            count++;
        }
    }
    return count;
}

// Function to count non-overlapping points
int countNonOverlappingPoints(POINT points[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int isOverlapping = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && points[i].x == points[j].x && points[i].y == points[j].y) {
                isOverlapping = 1;
                break;
            }
        }
        if (!isOverlapping) {
            count++;
        }
    }
    return count;
}

// Function to find the point with the largest x-coordinate
POINT findLargestX(POINT points[], int n) {
    POINT largest = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x > largest.x) {
            largest = points[i];
        }
    }
    return largest;
}

// Function to find the point with the smallest x-coordinate
POINT findSmallestX(POINT points[], int n) {
    POINT smallest = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x < smallest.x) {
            smallest = points[i];
        }
    }
    return smallest;
}

// Function to find the point closest to the origin
POINT findClosestToOrigin(POINT points[], int n) {
    POINT closest = points[0];
    double minDistance = sqrt(closest.x * closest.x + closest.y * closest.y);
    
    for (int i = 1; i < n; i++) {
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
        if (distance < minDistance) {
            minDistance = distance;
            closest = points[i];
        }
    }
    return closest;
}

// Main function
int main() {
    int n;
    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &n);
    
    if (n > MAX_POINTS) {
        printf("Number of points exceeds the maximum limit of %d.\n", MAX_POINTS);
        return 1;
    }

    POINT points[MAX_POINTS];

    // Input points
    for (int i = 0; i < n; i++) {
        printf("Point %d:\n", i + 1);
        points[i] = inputPoint();
    }

    // Output all points
    printf("\nAll points:\n");
    for (int i = 0; i < n; i++) {
        outputPoint(points[i]);
        printf("\n");
    }

    // Count points with positive x-coordinate
    int positiveXCount = countPositiveX(points, n);
    printf("\nNumber of points with positive x-coordinate: %d\n", positiveXCount);

    // Count non-overlapping points
    int nonOverlappingCount = countNonOverlappingPoints(points, n);
    printf("Number of non-overlapping points: %d\n", nonOverlappingCount);

    // Find the point with the largest x-coordinate
    POINT largestXPoint = findLargestX(points, n);
    printf("Point with the largest x-coordinate: ");
    outputPoint(largestXPoint);
    printf("\n");

    // Find the point with the smallest x-coordinate
    POINT smallestXPoint = findSmallestX(points, n);
    printf("Point with the smallest x-coordinate: ");
    outputPoint(smallestXPoint);
    printf("\n");

    // Find the point closest to the origin
    POINT closestPoint = findClosestToOrigin(points, n);
    printf("Point closest to the origin: ");
    outputPoint(closestPoint);
    printf("\n");

    return 0;
}
