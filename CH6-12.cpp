#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class BoxOfProduce {
private:
    vector<string> items;

public:
    // Constructor
    BoxOfProduce() {
        items.resize(3);
    }

    // Accessor function to get the contents of the box
    vector<string> getContents() const {
        return items;
    }

    // Mutator function to set the contents of the box
    void setContents(const vector<string>& newItems) {
        if (newItems.size() == 3) {
            items = newItems;
        }
        else {
            cout << "Error: Box must contain exactly three items." << endl;
        }
    }

    // Output function to display the contents of the box
    void displayContents() const {
        cout << "Box Contents:" << endl;
        for (const string& item : items) {
            cout << "- " << item << endl;
        }
    }
};

// Function to read produce items from a file
vector<string> readProduceFromFile(const string& input_file) {
    vector<string> produceList;
    ifstream file(input_file);
    if (file.is_open()) {
        string item;
        while (getline(file, item)) {
            produceList.push_back(item);
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
    return produceList;
}

// Function to randomly select items from a list
vector<string> selectRandomItems(const vector<string>& produceList, int count) {
    vector<string> selectedItems;
    int totalItems = produceList.size();
    for (int i = 0; i < count; ++i) {
        int randomIndex = rand() % totalItems;
        selectedItems.push_back(produceList[randomIndex]);
    }
    return selectedItems;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Read produce items from file
    vector<string> produceList = readProduceFromFile("produce.txt");

    // Create a BoxOfProduce with three random items
    BoxOfProduce box;
    vector<string> randomItems = selectRandomItems(produceList, 3);
    box.setContents(randomItems);

    // Display the initial contents of the box
    cout << "Initial Box Contents:" << endl;
    box.displayContents();

    // Allow the user to substitute items
    cout << "\nSubstitute any one of the following items:" << endl;
    for (int i = 0; i < produceList.size(); ++i) {
        cout << i + 1 << ". " << produceList[i] << endl;
    }

    int substituteIndex;
    cout << "Enter the index of the item to substitute (1-3): ";
    cin >> substituteIndex;
    if (substituteIndex >= 1 && substituteIndex <= 3) {
        int selectedItemIndex;
        cout << "Enter the index of the new item (1-5): ";
        cin >> selectedItemIndex;
        if (selectedItemIndex >= 1 && selectedItemIndex <= 5) {
            // Perform substitution
            box.setContents(randomItems);
            randomItems[substituteIndex - 1] = produceList[selectedItemIndex - 1];
            box.setContents(randomItems);

            // Display the final contents of the box
            cout << "\nFinal Box Contents:" << endl;
            box.displayContents();
        }
        else {
            cout << "Invalid input for new item index." << endl;
        }
    }
    else {
        cout << "Invalid input for substitution index." << endl;
    }

    return 0;
}
