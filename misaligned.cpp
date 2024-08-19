#include <iostream>
#include <iomanip>
#include <sstream>
#include <assert.h>

std::string printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::ostringstream oss;
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            oss << std::setw(2) << i * 5 + j << " | " << std::setw(6) << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    std::string result = oss.str();
    std::cout << result;
    return result;
}

void test_printColorMap() {
    std::string result = printColorMap();
    std::string expectedLine1 = " 0 | White  | Blue\n";
    std::string expectedLine2 = " 1 | White  | Orange\n";
    std::string expectedLine3 = " 2 | White  | Green\n";
    std::string expectedLine4 = " 3 | White  | Brown\n";
    std::string expectedLine5 = " 4 | White  | Slate\n";

    // Check if the first five lines are as expected
    assert(result.substr(0, expectedLine1.length()) == expectedLine1);
    assert(result.substr(expectedLine1.length(), expectedLine2.length()) == expectedLine2);
    assert(result.substr(expectedLine1.length() + expectedLine2.length(), expectedLine3.length()) == expectedLine3);
    assert(result.substr(expectedLine1.length() + expectedLine2.length() + expectedLine3.length(), expectedLine4.length()) == expectedLine4);
    assert(result.substr(expectedLine1.length() + expectedLine2.length() + expectedLine3.length() + expectedLine4.length(), expectedLine5.length()) == expectedLine5);
}

int main() {
    test_printColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
