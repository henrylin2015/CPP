#include <iostream>
#include<string>
using namespace std;
class Animal {
public:
	void set_weight(int w){
		this->m_weight = w;
	}
	int get_weight(void) {
		return this->m_weight;
	}
	void set_age(int age) {
		this->m_age = age;
	}
protected:
	int m_age;
private:
	int m_weight;
};
class Cat :public Animal {
public:
	Cat(string m):m_name(m){}
	void set_print_age() {
		this->set_age(8);
		cout << "Animal age=" << this->m_age << endl;
	}
	void set_name(string m) {
		this->m_name = m;
	}
	string get_name(void) {
		return this->m_name;
	}
private:
	string m_name;
};
int main02() {
	Cat cat("Cat");
	cat.set_print_age();
	cat.set_weight(10);
	cout << "cat weight:" << cat.get_weight() << endl;
	system("pause");
	return 0;
}