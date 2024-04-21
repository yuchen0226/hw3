#include <iostream>
using namespace std;

class Money {
private:
    int dollars; // �x�s��������Ƴ���
    int cents;   // �x�s�������p�Ƴ����]�H�������^

public:
    // �غc�禡
    Money(int d = 0, int c = 0) : dollars(d), cents(c) {}

    // �s�����禡
    int getDollars() const { return dollars; } // ���o��������Ƴ���
    int getCents() const { return cents; }     // ���o�������p�Ƴ���

    // �]�m�禡
    void setDollars(int d) { dollars = d; } // �]�m��������Ƴ���
    void setCents(int c) { cents = c; }     // �]�m�������p�Ƴ���

    // �禡�H double �Φ���^���B
    double getAmount() const {
        return dollars + static_cast<double>(cents) / 100.0; // �N�����M���ഫ�� double
    }
};

int main() {
    // �Ыب�� Money ����
    Money money1(10, 50); // $10.50
    Money money2(5, 75);  // $5.75

    // ���զs�����禡
    cout << "Money 1: $" << money1.getDollars() << "." << money1.getCents() << endl;
    cout << "Money 2: $" << money2.getDollars() << "." << money2.getCents() << endl;

    // ���ճ]�m�禡
    money1.setDollars(20);
    money1.setCents(30);
    cout << "Money 1 (Updated): $" << money1.getDollars() << "." << money1.getCents() << endl;

    // ���� getAmount �禡
    cout << "Money 1 Amount: $" << money1.getAmount() << endl;
    cout << "Money 2 Amount: $" << money2.getAmount() << endl;

    return 0;
}