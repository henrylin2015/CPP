#include <iostream>
#include <string>
using namespace std;
int main() {
	//�Ƚ������ַ����Ĵ�С

}
int main04() {
	// strcat ���������ַ��� 
	string s1, s2;
	cout << "Please input two strings:" << endl;
	cin >> s1 >> s2;
	cout << s1 + s2 << endl;
	system("pause");
	return 0;
}
int main03() {
	string str = "Hello c++!";
	cout << str << endl;
	str[7] = '-';
	str[8] = '-';
	cout << str << endl;
	system("pause");
	return 0;
}
int main02() {
	int num1, num2;
	cin >> num1 >> num2;
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	system("pause");
	return 0;
}
int main01() {
	cout << "Hello world!" << endl;
	system("pause");
	return  0;
}