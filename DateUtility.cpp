#include "DateUtility.h"
#include <cctype>
#include <string>

// Updated implementation
bool DateUtility::isSixMonthsApart(const std::string& date1, const std::string& date2) {
    
    // Validate both dates: MM/DD/YYYY
    auto isValidDate = [](const std::string& date) -> bool {
        // Check for correct length and slashes
        if (date.length() != 10 || date[2] != '/' || date[5] != '/') return false;

        // Split into parts
        std::string mm = date.substr(0, 2);
        std::string dd = date.substr(3, 2);
        std::string yyyy = date.substr(6, 4);

        // Ensure all characters are digits
        for (char c : mm + dd + yyyy)
            if (!isdigit(c)) return false;

        int m = std::stoi(mm);
        int d = std::stoi(dd);
        int y = std::stoi(yyyy);

        return m >= 1 && m <= 12 && d >= 1 && d <= 31 && y >= 1900 && y <= 2100;
    };

    if (!isValidDate(date1) || !isValidDate(date2))
        return false;  // invalid date format

    // extracting the month, day, + year
    
    // Index:   0 1 2 3 4 5 6 7 8 9
    // String:  M M / D D / Y Y Y Y

    // stoi converts the string to integers
    int m1 = std::stoi(date1.substr(0,2));  // this is for month (MM)
    int d1 = std::stoi(date1.substr(3,2));  // this is for day (DD)
    int y1 = std::stoi(date1.substr(6,4));  // this is for year (YYYY)
    
    // now do the same for the second date
    int m2 = std::stoi(date2.substr(0,2));  // this is for month (MM)
    int d2 = std::stoi(date2.substr(3,2));  // this is for day (DD)
    int y2 = std::stoi(date2.substr(6,4));  // this is for year (YYYY)

    // ensure date1 is earlier than date2
    if (y1 > y2 ||
        (y1 == y2 && m1 > m2) ||
        (y1 == y2 && m1 == m2 && d1 > d2)) {
        std::swap(y1, y2);
        std::swap(m1, m2);
        std::swap(d1, d2);
    }

    int yearDiff = y2 - y1;
    int monthDiff = m2 - m1 + yearDiff * 12;

    if (monthDiff > 6)
        return true;  // if the dates are more than 6 months apart, return true

    if (monthDiff < 6)
        return false; // if the dates are less than 6 months apart, return false

    return d2 >= d1;  // If the second day is the same or later than the first, it's valid
}

bool DateUtility::isSameDay(const std::string& d1, const std::string& d2) {
    return d1 == d2;
}
