#include<iostream>
#include<cstdlib>
using namespace std;

class Pizza
{
public:
	void outputDescription();     // 輸出披薩描述資訊
	double computePrice();        // 計算披薩價格

	int gettype();               // 獲取披薩類型
	int getsize();               // 獲取披薩尺寸

	int gettopping();            // 獲取配料類型
	int gettoppingNumber();      // 獲取配料數量
	void set(int t, int s, int p, int n);    // 設置披薩屬性

private:
	int type;             // 披薩類型
	int size;             // 披薩尺寸
	int topping;          // 配料類型
	int toppingNumber;    // 配料數量

};


int main(void)
{
	Pizza customer;
	cout << "*****Pizza*****\n";
	customer.outputDescription();       // 輸出披薩描述
	cout << "Your pizza is " << customer.computePrice() << " dollars.\n";      // 顯示披薩價格



	system("pause");
	return 0;
}
void Pizza::outputDescription()              // 輸出披薩的描述資訊
{
	cout << "**Type:\n";
	cout << "1:deep dish   2:hand tossed   3:pan\n";
	cout << "**Size:\n";
	cout << "1:small       2:medium        3.large\n";
	cout << "**Topping:\n";
	cout << "1:pepperoni   2:cheese\n";
	cout << "--------------------------------------\n";
}

double Pizza::computePrice()                  // 計算披薩的價格
{
	int value1;
	cout << "Choose the type of your pizza>";
	cin >> type;
	cout << "Choose the size of your pizza>";
	cin >> size;
	if (size == 1)                           // 根據尺寸設置基本價格
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
	// 選擇配料
	cout << "Choose a type of topping that you want>";
	cin >> topping;
	cout << "How many toppings that you want>";
	cin >> toppingNumber;

	return(value1 += (2 * toppingNumber));   // 計算總價格（基本價格加上配料價格）
	if (type > 3 || type < 1 || size>3 || size < 1 || topping>2 || topping < 1 || toppingNumber < 0)       // 檢查用戶輸入是否合法
	{
		cout << "Your input is wrong!\n";
		exit(1);
	}
}
int Pizza::gettype()           // 獲取披薩類型
{
	return type;
}
int Pizza::getsize()           // 獲取披薩尺寸
{
	return size;
}
int Pizza::gettopping()        // 獲取披薩配料類型
{
	return topping;
}
int Pizza::gettoppingNumber()  // 獲取披薩配料數量
{
	return toppingNumber;
}
void Pizza::set(int t, int s, int p, int n)    // 設置披薩屬性
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