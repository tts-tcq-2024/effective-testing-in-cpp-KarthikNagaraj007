#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celsius) {
    if (celsius > 200) 
    {
        return 500; // Return for not-ok
    }
    return 200; // Return 200 for ok
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

void test_alertInCelcius() {
    assert(alertInCelsius(400.5) == 1); 
    assert(alertInCelsius(303.6) == 1);
    assert(alertInCelsius(404.8) == 1);

}

int main() {
    test_alertInCelcius();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
