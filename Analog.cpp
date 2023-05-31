#include <iostream>
#include <ctime>
#include <cmath>

int main() {
    // Get the current time
    time_t currentTime = time(0);
    tm *timePtr = localtime(&currentTime);

    int hour = timePtr->tm_hour;
    int minute = timePtr->tm_min;
    int second = timePtr->tm_sec;

    // Calculate the angles for hour, minute, and second hands
    float hourAngle = (hour % 12 + minute / 60.0) * 30;
    float minuteAngle = (minute + second / 60.0) * 6;
    float secondAngle = second * 6;

    // Convert angles to radians
    hourAngle = hourAngle * M_PI / 180;
    minuteAngle = minuteAngle * M_PI / 180;
    secondAngle = secondAngle * M_PI / 180;

    // Calculate the coordinates for hour, minute, and second hands
    int centerX = 40;   // X-coordinate of the clock center
    int centerY = 12;   // Y-coordinate of the clock center
    int hourX = static_cast<int>(centerX + 8 * sin(hourAngle));
    int hourY = static_cast<int>(centerY - 8 * cos(hourAngle));
    int minuteX = static_cast<int>(centerX + 10 * sin(minuteAngle));
    int minuteY = static_cast<int>(centerY - 10 * cos(minuteAngle));
    int secondX = static_cast<int>(centerX + 12 * sin(secondAngle));
    int secondY = static_cast<int>(centerY - 12 * cos(secondAngle));

    // Draw the clock using ASCII characters
    for (int y = 0; y < 24; ++y) {
        for (int x = 0; x < 80; ++x) {
            if (x == centerX && y == centerY) {
                std::cout << 'O';   // Clock center
            } else if (x == hourX && y == hourY) {
                std::cout << 'H';   // Hour hand
            } else if (x == minuteX && y == minuteY) {
                std::cout << 'M';   // Minute hand
            } else if (x == secondX && y == secondY) {
                std::cout << 'S';   // Second hand
            } else {
                std::cout << ' ';   // Empty space
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

