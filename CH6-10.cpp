#include <iostream>
using namespace std;

class Weight {
private:
    double pounds;

public:
    // Constructor
    Weight(double lbs = 0.0) : pounds(lbs) {}

    // Function to set weight in pounds
    void setWeightPounds(double lbs) {
        pounds = lbs;
    }

    // Function to set weight in kilograms
    void setWeightKilograms(double kg) {
        pounds = kg * 2.21; // 1 kilogram = 2.21 pounds
    }

    // Function to set weight in ounces
    void setWeightOunces(double oz) {
        pounds = oz / 16.0; // 1 ounce = 1/16 pounds
    }

    // Function to get weight in pounds
    double getWeightPounds() const {
        return pounds;
    }

    // Function to get weight in kilograms
    double getWeightKilograms() const {
        return pounds / 2.21; 
    }

    // Function to get weight in ounces
    double getWeightOunces() const {
        return pounds * 16.0; // 1 pound = 16 ounces
    }
};

int main() {
    Weight weight;
    weight.setWeightPounds(150.0);

    cout << "Weight in pounds: " << weight.getWeightPounds() << " lbs" << endl;
    cout << "Weight in kilograms: " << weight.getWeightKilograms() << " kg" << endl;
    cout << "Weight in ounces: " << weight.getWeightOunces() << " oz" << endl;

    return 0;
}
