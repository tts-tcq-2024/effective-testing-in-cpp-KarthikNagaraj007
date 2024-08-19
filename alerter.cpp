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

void testAlertInCelcius() {
    alertFailureCount = 0;
    
    alertInCelcius(400.5);
    assert(alertFailureCount == 1);

    alertInCelcius(303.6);
    assert(alertFailureCount == 2);

    alertInCelcius(404.8);
    assert(alertFailureCount == 3);

}

int main() {
    testAlertInCelcius();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
