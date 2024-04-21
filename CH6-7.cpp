#include<iostream>
#include<cstdlib>
using namespace std;

class Pizza
{
public:
	void outputDescription();     // ��X���Ĵy�z��T
	double computePrice();        // �p����Ļ���

	int gettype();               // �����������
	int getsize();               // ������Ĥؤo

	int gettopping();            // ����t������
	int gettoppingNumber();      // ����t�Ƽƶq
	void set(int t, int s, int p, int n);    // �]�m�����ݩ�

private:
	int type;             // ��������
	int size;             // ���Ĥؤo
	int topping;          // �t������
	int toppingNumber;    // �t�Ƽƶq

};


int main(void)
{
	Pizza customer;
	cout << "*****Pizza*****\n";
	customer.outputDescription();       // ��X���Ĵy�z
	cout << "Your pizza is " << customer.computePrice() << " dollars.\n";      // ��ܩ��Ļ���



	system("pause");
	return 0;
}
void Pizza::outputDescription()              // ��X���Ī��y�z��T
{
	cout << "**Type:\n";
	cout << "1:deep dish   2:hand tossed   3:pan\n";
	cout << "**Size:\n";
	cout << "1:small       2:medium        3.large\n";
	cout << "**Topping:\n";
	cout << "1:pepperoni   2:cheese\n";
	cout << "--------------------------------------\n";
}

double Pizza::computePrice()                  // �p����Ī�����
{
	int value1;
	cout << "Choose the type of your pizza>";
	cin >> type;
	cout << "Choose the size of your pizza>";
	cin >> size;
	if (size == 1)                           // �ھڤؤo�]�m�򥻻���
	{
		value1 = 10;
	}
	else if (size == 2)
	{
		value1 = 14;
	}
	else if (size == 3)
	{
		value1 = 17;
	}
	// ��ܰt��
	cout << "Choose a type of topping that you want>";
	cin >> topping;
	cout << "How many toppings that you want>";
	cin >> toppingNumber;

	return(value1 += (2 * toppingNumber));   // �p���`����]�򥻻���[�W�t�ƻ���^
	if (type > 3 || type < 1 || size>3 || size < 1 || topping>2 || topping < 1 || toppingNumber < 0)       // �ˬd�Τ��J�O�_�X�k
	{
		cout << "Your input is wrong!\n";
		exit(1);
	}
}
int Pizza::gettype()           // �����������
{
	return type;
}
int Pizza::getsize()           // ������Ĥؤo
{
	return size;
}
int Pizza::gettopping()        // ������İt������
{
	return topping;
}
int Pizza::gettoppingNumber()  // ������İt�Ƽƶq
{
	return toppingNumber;
}
void Pizza::set(int t, int s, int p, int n)    // �]�m�����ݩ�
{
	if (t <= 3 && t >= 1)
		type = t;
	else {
		cout << "Your input is wrong!\n";
		exit(1);
	}
	if (s <= 3 && s >= 1)
		size = s;
	else {
		cout << "Your input is wrong!\n";
		exit(1);
	}
	if (p <= 2 && p >= 1)
		topping = p;
	else {
		cout << "Your input is wrong!\n";
		exit(1);
	}
	if (n > 0)
		toppingNumber = n;
	else {
		cout << "Your input is wrong!\n";
		exit(1);
	}
}