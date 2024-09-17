#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year);
void addDaysToDate(int* dd, int* mm, int* yyyy, int days);
char* getDayOfWeek(int dd, int mm, int yyyy);
void printReadableDate(int dd, int mm, int yyyy);

int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthKeyValue[] = {0, 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
char* daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
char* monthNames[] = {"", "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"}; 

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    bool leapYear = isLeapYear(year);
    printf(leapYear ? "It is a leap year.\n" : "It is not a leap year.\n");
    
    int dd, mm, yyyy;
    printf("Enter a date (dd mm yyyy): ");
    scanf("%d %d %d", &dd, &mm, &yyyy);

    int days;
    printf("Enter a number of days to add: ");
    scanf("%d", &days);

    addDaysToDate(&dd, &mm, &yyyy, days);
    printf("The new date is: %d %d %d\n", dd, mm, yyyy);

    char* dayOfWeek = getDayOfWeek(dd, mm, yyyy);
    printf("The day of the week is: %s\n", dayOfWeek);

    printf("The readable date is: "); 
    printReadableDate(dd, mm, yyyy);

    return 0;
}

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

void addDaysToDate(int* dd, int* mm, int* yyyy, int days) {
    int daysLeftInMonth;

    if (days == 0) {
        return;
    }
    
    while (days > 0) {
        daysLeftInMonth = daysInMonth[*mm] - *dd;
        if (*mm == 2 && isLeapYear(*yyyy)) {
            daysLeftInMonth++;
        }
        if (days > daysLeftInMonth) {
            days -= daysLeftInMonth;
            days--;
            *dd = 1;
            if (*mm == 12) {
                *mm = 1;
                (*yyyy)++;
            } else {
                (*mm)++;
            }
        } else {
            *dd += days;
            days = 0;
        }
    }
}

char* getDayOfWeek(int dd, int mm, int yyyy) {
    // https://stackoverflow.com/questions/6054016/c-program-to-find-day-of-week-given-date
    // https://www.shiksha.com/online-courses/articles/find-day-of-given-date-using-c/
    int weekdayIdx = (dd + (13 * (mm + 1) / 5) + (yyyy % 100) + ((yyyy % 100) / 4) + ((yyyy / 100) / 4) + 5 * (yyyy / 100)) % 7;
    printf("weekdayIdx: %d\n", weekdayIdx);
    return daysOfWeek[weekdayIdx];
}

void printReadableDate(int dd, int mm, int yyyy) {
    printf("%d %s, %d", dd, monthNames[mm], yyyy);
}
