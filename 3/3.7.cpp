#include <iostream>
#include <string>
using namespace std;
class A {
public:
	A(int age, int wei);
private:
	int m_age;
	int m_weight;
};
A::A(int age, int wei) {
	this->m_age = age;
	this->m_weight = wei;
	cout << "A constructor with param!" << endl;
}
class B:public A{
public:
	B(string name, int age, int wei);
private:
	string m_name;
};
B::B(string name, int age, int wei) :A(age, wei) {
	this->m_name = name;
	cout << "B constructor with param!" << endl;
}
int main37() {
	B b("bb", 5, 7);
	system("pause");
	return 0;
}