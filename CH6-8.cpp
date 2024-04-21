#include <iostream>
using namespace std;

class Money {
private:
    int dollars; // 纗じ俱计场だ
    int cents;   // 纗じ计场だだ虫

public:
    // 篶ㄧΑ
    Money(int d = 0, int c = 0) : dollars(d), cents(c) {}

    // 竟ㄧΑ
    int getDollars() const { return dollars; } // 眔じ俱计场だ
    int getCents() const { return cents; }     // 眔じ计场だ

    // 砞竚ㄧΑ
    void setDollars(int d) { dollars = d; } // 砞竚じ俱计场だ
    void setCents(int c) { cents = c; }     // 砞竚じ计场だ

    // ㄧΑ double Α肂
    double getAmount() const {
        return dollars + static_cast<double>(cents) / 100.0; // 盢じ㎝だ锣传 double
    }
};

int main() {
    // 承ㄢ Money ン
    Money money1(10, 50); // $10.50
    Money money2(5, 75);  // $5.75

    // 代刚竟ㄧΑ
    cout << "Money 1: $" << money1.getDollars() << "." << money1.getCents() << endl;
    cout << "Money 2: $" << money2.getDollars() << "." << money2.getCents() << endl;

    // 代刚砞竚ㄧΑ
    money1.setDollars(20);
    money1.setCents(30);
    cout << "Money 1 (Updated): $" << money1.getDollars() << "." << money1.getCents() << endl;

    // 代刚 getAmount ㄧΑ
    cout << "Money 1 Amount: $" << money1.getAmount() << endl;
    cout << "Money 2 Amount: $" << money2.getAmount() << endl;

    return 0;
}