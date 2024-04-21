#include <iostream>
using namespace std;

class HotDogStand {
private:
    int standID;
    int hotDogsSold;
    static int totalHotDogsSold;

public:
    // Constructor
    HotDogStand(int id, int sold) : standID(id), hotDogsSold(sold) {}

    // Function to increment the number of hot dogs sold by one
    void JustSold() {
        hotDogsSold++;
        totalHotDogsSold++;
    }

    // Function to get the number of hot dogs sold by this stand
    int getHotDogsSold() const {
        return hotDogsSold;
    }

    // Static function to get the total number of hot dogs sold by all stands
    static int getTotalHotDogsSold() {
        return totalHotDogsSold;
    }
};

// Initialize static variable
int HotDogStand::totalHotDogsSold = 0;

int main() {
    // Create three hot dog stands
    HotDogStand stand1(1, 0);
    HotDogStand stand2(2, 0);
    HotDogStand stand3(3, 0);

    // Each stand sells some hot dogs
    stand1.JustSold();
    stand2.JustSold();
    stand2.JustSold();
    stand3.JustSold();
    stand3.JustSold();
    stand3.JustSold();

    // Display the number of hot dogs sold by each stand
    cout << "Hot Dog Stand 1 sold " << stand1.getHotDogsSold() << " hot dogs." << endl;
    cout << "Hot Dog Stand 2 sold " << stand2.getHotDogsSold() << " hot dogs." << endl;
    cout << "Hot Dog Stand 3 sold " << stand3.getHotDogsSold() << " hot dogs." << endl;

    // Display the total number of hot dogs sold by all stands
    cout << "Total hot dogs sold by all stands: " << HotDogStand::getTotalHotDogsSold() << endl;

    return 0;
}
