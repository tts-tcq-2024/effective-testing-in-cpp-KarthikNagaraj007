#include <iostream>
#include <assert.h>
#include <string>

int alertFailureCount = 0;

std::string networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return (celcius < 200)? "ok" : "not ok";
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    std::string returnCode = networkAlertStub(celcius);
    if (returnCode != "ok") {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

void testTemperature(){
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(102.5);
    assert(alertFailureCount == 2);
    std::cout << alertFailureCount << " alerts failed.\n";
}

int main() {
    testTemperature();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
