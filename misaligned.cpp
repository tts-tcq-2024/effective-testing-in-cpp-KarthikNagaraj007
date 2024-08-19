#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << std::endl;
        }
    }
    return i * j;
}

void testColorPairs() {
    // Buffer to capture the output of printColorMap
    std::ostringstream oss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    // Generate the color map output
    int result = printColorMap();

    // Restore the original stdout
    std::cout.rdbuf(oldCoutStreamBuf);

    // Define expected major and minor colors
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    // Split the captured output into lines and verify each one
    std::istringstream iss(oss.str());
    std::string line;
    int lineCount = 0;

    while (std::getline(iss, line)) {
        std::ostringstream expectedOutput;
        expectedOutput << lineCount << " | " << majorColor[lineCount / 5] << " | " << minorColor[lineCount % 5];

        // Compare the captured line with the expected output
        assert(line == expectedOutput.str() && "Mismatch in color pair output");

        lineCount++;
    }

    assert(result == 25 && "Result should be 25");
}

int main() {
    int result = printColorMap();
    testColorPairs();
    assert(result == 25 && "Result should be 25");
    std::cout << "All is well (maybe!)\n";
    return 0;
}
