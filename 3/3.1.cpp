#include<iostream>
#include<string>
using namespace std;
class Animal {
public:
	void speak() {
		cout << "Animal language" << endl;
	}
};
class Cat :public Animal {
public:
	Cat(string name) :m_name(name){}
	void print_name() {
		cout << "cat name:" << this->m_name << endl;
	}
private:
	string m_name;
};
int main01() {
	Cat cat("Persian");
	cat.print_name();
	cat.speak();
	system("pause");
	return 0;
}