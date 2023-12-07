#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x1, y1, x2, y2, x, y, k;
    int gd, gm, i, val, r;

    cout << "Enter the radius of circle: ";
    cin >> r;

    // Set the window size based on the circle radius
    int windowSize = max(2 * r, 400); // Ensure a minimum size of 400x400
    initwindow(windowSize, windowSize, "Circle Drawing");

    x1 = r * cos(0);
    y1 = r * sin(0);
    x = x1;
    y = y1;
    i = 0;

    do {
        val = pow(2, i);
        i++;
    } while (val < r);

    k = 1 / pow(2, i - 1);

    do {
        x2 = x1 + y1 * k;
        y2 = y1 - k * x2;

        // Adjust the scaling factor for larger circles
        putpixel(windowSize / 2 + x2, windowSize / 2 + y2, 15);

        x1 = x2;
        y1 = y2;
    } while ((y1 - y) < k || (x - x1) > k);

    delay(7000);
    closegraph();
    return 0;
}
