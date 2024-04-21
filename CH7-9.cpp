#include <iostream>
#include <string>
using namespace std;

// Class declaration for handling zip codes
class zipCode {
public:
    // Constructor to initialize zip code with a string
    zipCode(string a) {
        zipcode = a;
    }
    // Constructor to initialize zip code with an integer
    zipCode(int a) {
        value = a;
    };

    // Function to get the zip code as an integer
    int getzipCodeIninteger() {
        convertFromstring();
        return value;
    }
    // Function to get the zip code as a string
    string getzipCodeInstring() const {
        return zipcode;
    }

private:
    // Function to split the string representation of the zip code into a 5x5 array
    void split(int arr[][5]) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (zipcode[i * 5 + j] == '1') {
                    arr[i][j] = 1;
                }
                else if (zipcode[i * 5 + j] == '0') {
                    arr[i][j] = 0;
                }
                else {
                    cout << "Invalid" << endl; // Notify if an invalid character is encountered
                }
            }
        }
    }

    // Function to convert the string representation of the zip code to an integer
    void convertFromstring() {
        value = 0;
        int correspondValue[]{ 7,4,2,1,0 }, count, arr[5][5], record[5], temp;

        split(arr); // Split the string representation into a 5x5 array
        for (int i = 0; i < 5; i++) {
            count = 0;
            temp = 0;
            for (int j = 0; j < 5; j++) {
                if (arr[i][j] == 1) {
                    temp += correspondValue[j];
                    count++;
                }
            }
            if (count > 2) { // If more than 2 '1's are found in a group, it's invalid
                cout << "Invalid" << endl;
                exit(1);
            }
            record[i] = temp;
            if (record[i] == 11) { // If the sum equals 11, set it to 0
                record[i] = 0;
            }
        }
        for (int i = 0; i < 5; i++) {
            value += record[i]; // Sum up the individual digits to get the final integer zip code
        }
    }

    string zipcode; // Stores the string representation of the zip code
    int value;      // Stores the integer representation of the zip code
};

int main(void) {
    string str;

    // Prompt the user to input the zip code as a string
    cout << "Enter a string consist of 0's or 1's, and in total it suppose to be 25 digits(first and last also should be 1,each 5 digits in one group should only contains two 1)" << endl;
    cin >> str;

    // Create an instance of zipCode class with the provided string
    zipCode zipCode1(str);

    // Display the zip code as an integer
    cout << "Zip code for integer" << endl;
    cout << zipCode1.getzipCodeIninteger() << endl;

    // Display the zip code as a string
    cout << "Zip code for string" << endl;
    cout << zipCode1.getzipCodeInstring() << endl;

    return 0;
}
