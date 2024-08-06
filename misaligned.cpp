#include <iostream>
#include <assert.h>

int getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

void testColorMap() {
    assert(getColorMap() == 0);
}

int main() {
    testColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
