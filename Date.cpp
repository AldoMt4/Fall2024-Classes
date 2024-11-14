#include <stdio.h>
#include <stdbool.h>

// Define the DATE structure
typedef struct {
    int day;
    int month;
    int year;
} DATE;

// Check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Days in each month
int daysInMonth(int month, int year) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

// Import date
DATE inputDate() {
    DATE date;
    printf("Enter day, month, and year: ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);
    return date;
}

// Export date
void outputDate(DATE date) {
    printf("%02d/%02d/%04d\n", date.day, date.month, date.year);
}

// Calculate day number in the year
int dayOfYear(DATE date) {
    int dayNum = 0;
    for (int month = 1; month < date.month; month++) {
        dayNum += daysInMonth(month, date.year);
    }
    dayNum += date.day;
    return dayNum;
}

// Calculate day number from 01/01/01
int dayFromStart(DATE date) {
    int totalDays = 0;
    for (int year = 1; year < date.year; year++) {
        totalDays += isLeapYear(year) ? 366 : 365;
    }
    totalDays += dayOfYear(date);
    return totalDays;
}

// Find date k days after the given date
DATE dateAfterDays(DATE date, int k) {
    while (k > 0) {
        int daysRemainingInMonth = daysInMonth(date.month, date.year) - date.day;
        if (k <= daysRemainingInMonth) {
            date.day += k;
            break;
        } else {
            k -= daysRemainingInMonth + 1;
            date.day = 1;
            date.month++;
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
    }
    return date;
}

// Find date k days before the given date
DATE dateBeforeDays(DATE date, int k) {
    while (k > 0) {
        if (k < date.day) {
            date.day -= k;
            break;
        } else {
            k -= date.day;
            date.month--;
            if (date.month < 1) {
                date.month = 12;
                date.year--;
            }
            date.day = daysInMonth(date.month, date.year);
        }
    }
    return date;
}

// Calculate the distance in days between two dates
int dateDifference(DATE date1, DATE date2) {
    int days1 = dayFromStart(date1);
    int days2 = dayFromStart(date2);
    return (days1 - days2);
}

// Compare two dates (-1 if date1 < date2, 0 if equal, 1 if date1 > date2)
int compareDates(DATE date1, DATE date2) {
    if (date1.year < date2.year || 
       (date1.year == date2.year && date1.month < date2.month) ||
       (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)) {
        return -1;
    }
    else if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        return 0;
    }
    return 1;
}

// Main function for testing
int main() {
    DATE date1, date2;
    int k;

    printf("Input Date 1:\n");
    date1 = inputDate();
    printf("Date 1: ");
    outputDate(date1);

    printf("\nInput Date 2:\n");
    date2 = inputDate();
    printf("Date 2: ");
    outputDate(date2);

    // Check if year is leap year
    printf("\nIs year of Date 1 a leap year? %s\n", isLeapYear(date1.year) ? "Yes" : "No");

    // Calculate day number in the year
    printf("Day of the year for Date 1: %d\n", dayOfYear(date1));

    // Calculate day number from 01/01/01
    printf("Day number from 01/01/01 for Date 1: %d\n", dayFromStart(date1));

    // Find date k days after Date 1
    printf("\nEnter number of days to add to Date 1: ");
    scanf("%d", &k);
    DATE afterDate = dateAfterDays(date1, k);
    printf("Date after %d days: ", k);
    outputDate(afterDate);

    // Find date k days before Date 1
    printf("\nEnter number of days to subtract from Date 1: ");
    scanf("%d", &k);
    DATE beforeDate = dateBeforeDays(date1, k);
    printf("Date before %d days: ", k);
    outputDate(beforeDate);

    // Calculate distance between Date 1 and Date 2
    printf("\nDistance between Date 1 and Date 2: %d days\n", dateDifference(date1, date2));

    // Compare Date 1 and Date 2
    int comparison = compareDates(date1, date2);
    if (comparison == -1) {
        printf("Date 1 is earlier than Date 2\n");
    } else if (comparison == 1) {
        printf("Date 1 is later than Date 2\n");
    } else {
        printf("Date 1 is the same as Date 2\n");
    }

    return 0;
}
