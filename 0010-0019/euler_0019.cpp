#include <iostream>

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main(int argc, char **argv) {
    int day = 366, total = 0;
    for (int year = 1901; year <= 2000; year++) {
        for (int month = 0; month < 12; month++) {
            if (day % 7 == 0) total++;

            day += days_in_month[month];
            if (is_leap_year(year) && month == 1) day++;
        }
    }

    std::cout << total << std::endl;
}