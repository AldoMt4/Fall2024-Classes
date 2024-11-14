#include <stdio.h>

// Structure to hold health profile information
struct HealthProfile {
    char firstName[30];
    char lastName[30];
    char gender; // 'M' or 'F'
    int birthMonth;
    int birthDay;
    int birthYear;
    int height; // in inches
    int weight; // in pounds
};

// Function prototypes
void setHealthProfile(struct HealthProfile *profile);
int calculateAge(const struct HealthProfile *profile);
int calculateMaxHeartRate(const struct HealthProfile *profile);
void calculateTargetHeartRateRange(const struct HealthProfile *profile, int *min, int *max);
double calculateBMI(const struct HealthProfile *profile);
void displayBMIChart();
void displayHealthProfile(const struct HealthProfile *profile);

int main() {
    struct HealthProfile profile;

    setHealthProfile(&profile);
    displayHealthProfile(&profile);

    return 0;
}

// Function to set health profile data
void setHealthProfile(struct HealthProfile *profile) {
    printf("Enter first name: ");
    scanf("%s", profile->firstName);
    printf("Enter last name: ");
    scanf("%s", profile->lastName);
    printf("Enter gender (M/F): ");
    scanf(" %c", &profile->gender);
    printf("Enter birth month (1-12): ");
    scanf("%d", &profile->birthMonth);
    printf("Enter birth day (1-31): ");
    scanf("%d", &profile->birthDay);
    printf("Enter birth year (e.g., 1990): ");
    scanf("%d", &profile->birthYear);
    printf("Enter height (in inches): ");
    scanf("%d", &profile->height);
    printf("Enter weight (in pounds): ");
    scanf("%d", &profile->weight);
}

// Function to calculate age in years
int calculateAge(const struct HealthProfile *profile) {
    int currentYear = 2024; // Current year for calculation
    int currentMonth = 10;   // Current month for calculation
    int currentDay = 29;     // Current day for calculation

    int age = currentYear - profile->birthYear;
    if (profile->birthMonth > currentMonth || 
        (profile->birthMonth == currentMonth && profile->birthDay > currentDay)) {
        age--;
    }
    return age;
}

// Function to calculate maximum heart rate
int calculateMaxHeartRate(const struct HealthProfile *profile) {
    return 220 - calculateAge(profile);
}

// Function to calculate target heart rate range
void calculateTargetHeartRateRange(const struct HealthProfile *profile, int *min, int *max) {
    int maxHeartRate = calculateMaxHeartRate(profile);
    *min = (int)(maxHeartRate * 0.50);
    *max = (int)(maxHeartRate * 0.85);
}

// Function to calculate BMI
double calculateBMI(const struct HealthProfile *profile) {
    return (profile->weight / (double)(profile->height * profile->height)) * 703; // BMI formula
}

// Function to display BMI chart
void displayBMIChart() {
    printf("\nBMI Values:\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal weight: 18.5–24.9\n");
    printf("Overweight: 25–29.9\n");
    printf("Obesity: BMI of 30 or greater\n");
}

// Function to display health profile information
void displayHealthProfile(const struct HealthProfile *profile) {
    printf("\nHealth Profile:\n");
    printf("Name: %s %s\n", profile->firstName, profile->lastName);
    printf("Gender: %c\n", profile->gender);
    printf("Date of Birth: %02d/%02d/%04d\n", profile->birthMonth, profile->birthDay, profile->birthYear);
    printf("Height: %d inches\n", profile->height);
    printf("Weight: %d pounds\n", profile->weight);

    int age = calculateAge(profile);
    printf("Age: %d years\n", age);

    double bmi = calculateBMI(profile);
    printf("BMI: %.2f\n", bmi);

    int minTarget, maxTarget;
    calculateTargetHeartRateRange(profile, &minTarget, &maxTarget);
    printf("Maximum Heart Rate: %d bpm\n", calculateMaxHeartRate(profile));
    printf("Target Heart Rate Range: %d - %d bpm\n", minTarget, maxTarget);

    displayBMIChart();
}
