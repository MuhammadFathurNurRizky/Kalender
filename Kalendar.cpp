#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <time.h>

void printCalendar(int year) {
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    std::string monthList[] = { "Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember" };

    std::cout << "  --------------------------" << std::endl;
    std::cout << "           Calender - "<< year << std::endl;
    std::cout << "  ---------------------------" << std::endl;
    int days;
    int current;

    int y = year - 1;
    current = ( y + y/4 - y/100 + y/400 + t[0] + 1) % 7;

    for (int i = 0; i < 12; i++) {
        if (i == 1) {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                days = 29;
            } else {
                days = mDays[i];
            }
        } else {
            days = mDays[i];
        }

        std::cout << std::endl << "  -------------" << monthList[i] << "--------" << std::endl;
        std::cout << "  Sun Mon Tue Wed Thu Fri Sat" << std::endl;
        int k;
        for (k = 0; k < current; k++) {
            std::cout << "    ";
        }

        for (int j = 1; j <= days; j++) {
            k++;
            std::cout << std::setw(5) << j;
            if (k > 6) {
                k = 0;
                std::cout << std::endl;
            }
        }

        if (k) {
            std::cout << std::endl;
        }

        current = k;
    }
}



int main() {
    system("cls");

    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    int year = 1900 + local_time -> tm_year;
    char option;

    do {
        system("cls");
        printCalendar(year);

        std::cout << std::endl << std::endl;
        std::cout << "Press " << std::endl;
        std::cout << "- n  for next year" << std::endl;
        std::cout << "- p for previous year" << std::endl;
        std::cout << "- e for exit" << std::endl;
        option = getche();
        switch(option) {
            case 'n':
                year++;
                break;
            case 'p':
                year--;
                break;
        }
    }

    while(option != 'e' && option != 'E');
    
    return 0;
}