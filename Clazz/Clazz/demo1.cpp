#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	Car(string carName,int seats);
	~Car();
	void setSeats(int seats);
	int getSeats(void);
	void setCarName(string carName);
	string getCarName(void);
	void show();
private:
	string m_carName;
	int m_seats;
};

Car::Car(string carName, int seats)
{
	cout << "Car()" << endl;
	this->m_carName = carName;
	this->m_seats = seats;
}
Car::~Car()
{
	cout << "~Car()" << endl;
}
void Car::setSeats(int seats) {
	this->m_seats = seats;
}
int Car::getSeats(void) {
	return this->m_seats;
}
void Car::setCarName(string carName) {
	this->m_carName = carName;
}
string Car::getCarName(void) {
	return this->m_carName;
}
void Car::show() {
	cout << "name:" << this->getCarName() << "   ,seats:" << this->getSeats() << endl;
}

class Date {
public:
	Date(int y, int m, int d);
	void show();
private:
	int m_year;
	int m_month;
	int m_day;
};
Date::Date(int y, int m, int d) {
	this->m_year = y;
	this->m_month = m;
	this->m_day = d;
}
void Date::show() {
	cout << this->m_year << "-" << this->m_month << "-" << this->m_day <<endl;
}
class Student {
public:
	Student(string name, int glade,int y,int m,int d);
	void showInfo();
	Date m_date;
private:
	string m_name;
	int m_glade;
};
Student::Student(string name, int glade, int y, int m, int d):m_date(y,m,d) {
	cout << "Student()" << endl;
	this->m_name = name;
	this->m_glade = glade;
}
void Student::showInfo() {
	cout << "name:" << this->m_name << ",glade:" << this->m_glade << ",date:";
	this->m_date.show();
}
int main() {
	Student stu("henry", 1, 2013, 9, 1);
	stu.showInfo();
	system("pause");
	return 0;
}
int main01() {
	Car car("big car",4);
	car.show();
	system("pause");
	return 0;
}