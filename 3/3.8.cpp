#include <iostream>
#include <string>
using namespace std;
// 派生类和基类中的析构函数执行的循序
class A1 {
public:
	A1(int age, int wei) {
		this->m_age = age;
		this->m_weight = wei;
		cout << "A1 A1" << endl;
	}
	~A1(){
		cout << "A1 ~A1" << endl;
		system("pause");
	}
	int get_age(void) {
		return this->m_age;
	}
private:
	int m_age;
	int m_weight;
};
class B1 :public A1 {
public:
	B1(string name, int age, int wei) :A1(age, wei) {
		this->m_name = name;
		cout << "B1 B1" << endl;
	}
	~B1() {
		cout << "B1 ~B1" << endl;
	}
private:
	string m_name;
};
int main() {
	B1 b1("bbb", 6, 7);
	cout << "B1 age = " << b1.get_age() << endl;
	system("pause");
	return 0;
}