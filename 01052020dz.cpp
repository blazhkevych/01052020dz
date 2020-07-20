/*
Домашнее задание № 18
Курс «Язык программирования C»
Встреча №36
Тема : Структуры Домашнее задание

Задание 1 :
	Создайте структуру, описывающую комплексное число.Реализуйте арифметические операции с комплексными числами : сумму, разность, умножение, деление.
#include <iostream>
#include <Windows.h>
	using namespace std;
//Создайте структуру, описывающую комплексное число.
//Реализуйте арифметические операции с комплексными числами: сумму, разность, умножение, деление.
struct ComplexNumber {
public:
	ComplexNumber();
	ComplexNumber(double a, double b);
	ComplexNumber plus(ComplexNumber&);
	ComplexNumber minus(ComplexNumber&);
	ComplexNumber multiply(ComplexNumber&);
	ComplexNumber divide(ComplexNumber&);
	void print();
	void setA(double a);
	void setB(double b);
	void read();
private:
	double a, b;
};
ComplexNumber::ComplexNumber() {
	a = 0;
	b = 0;
}
ComplexNumber::ComplexNumber(double a, double b) {
	this->a = a;
	this->b = b;
}
void ComplexNumber::setA(double a) {
	this->a = a;
}
void ComplexNumber::setB(double b) {
	this->b = b;
}
void ComplexNumber::read() {
	cout << "Введите вещественную часть: ";
	cin >> a;
	cout << "Введите мнимую часть: ";
	cin >> b;
}
void ComplexNumber::print() {
	cout << a << (b > 0 ? "+" : "") << b << "*i\n";
}
ComplexNumber ComplexNumber::plus(ComplexNumber& right) {
	return ComplexNumber(this->a + right.a, this->b + right.b);
}
ComplexNumber ComplexNumber::minus(ComplexNumber& right) {
	return ComplexNumber(this->a - right.a, this->b - right.b);
}
ComplexNumber ComplexNumber::multiply(ComplexNumber& right) {
	double a = this->a,
		b = this->b,
		c = right.a,
		d = right.b;
	return ComplexNumber(a * c - b * d, b * c + a * d);
}
ComplexNumber ComplexNumber::divide(ComplexNumber& right) {
	double a = this->a,
		b = this->b,
		c = right.a,
		d = right.b;
	double resultA = (a * c + b * d) / (c * c + d * d),
		resultB = (b * c - a * d) / (c * c + d * d);
	return ComplexNumber(resultA, resultB);
}
int menu() {
	SetConsoleOutputCP(1251);
	int answer;
	cout << "\n1 - Сложить\n"
		<< "2 - Вычесть\n"
		<< "3 - Умножить\n"
		<< "4 - Разделить\n"
		<< "0 - Выход из программы\n"
		<< "> ";
	cin >> answer;
	cout << endl;
	return answer;
}
int main() {
	ComplexNumber a, b, result;
	int answer;
	do {
		answer = menu();
		if (answer != 0) {
			cout << "Число А\n";
			a.read();
			cout << "Число B\n";
			b.read();
		}
		switch (answer) {
		case 0:
			break;
		case 1:
			result = a.plus(b);
			break;
		case 2:
			result = a.minus(b);
			break;
		case 3:
			result = a.multiply(b);
			break;
		case 4:
			result = a.divide(b);
			break;
		}
		if (answer != 0) {
			cout << "Результат: ";
			result.print();
		}
	} while (answer != 0);
}
*/
/*
Задание 2:
Реализовать структуру «Автомобиль»(длина, клиренс(высота посадки), объем двигателя, мощность двигателя, диаметр колес, цвет, тип коробки передач).Создайте функции для задания значений, отображения значений, поиска значений.
#include <iostream>
#include <string.h>
using namespace std;
//Реализовать структуру «Автомобиль» (длина, клиренс (высота посадки), объем двигателя,
//мощность двигателя, диаметр колес, цвет, тип коробки передач).
//Создайте функции для задания значений, отображения значений, поиска значений.
struct Car {
	char Name[50]; //название
	int Length; //длина
	int Clearance; //клиренс (высота посадки)
	double EngineVolume; //объем двигателя
	int EnginePower; //мощность двигателя
	int WheelDiameter; //диаметр колес
	char Colour[50]; //цвет
	char GearType[50]; //тип коробки передач
};
void Input(Car& automobile) { //функция для задания значений
	cout << "Input Name: ";		 cin >> automobile.Name;
	cout << "Input Length(0): ";		 cin >> automobile.Length;
	cout << "Input Clearance(0): ";	 cin >> automobile.Clearance;
	cout << "Input EngineVolume(0.0): ";  cin >> automobile.EngineVolume;
	cout << "Input EnginePower(0): ";	 cin >> automobile.EnginePower;
	cout << "Input WheelDiameter(0): "; cin >> automobile.WheelDiameter;
	cout << "Input Colour: ";		 cin >> automobile.Colour;
	cout << "Input GearType: ";		 cin >> automobile.GearType;
}
void Print(Car& automobile) { //функция отображения значений
	printf_s("|%-25s|%5d mm|%5d mm|%5.2lf L|%4d hp|%3d inches|%-18s|%-30s|\n",
		automobile.Name, automobile.Length, automobile.Clearance,
		automobile.EngineVolume, automobile.EnginePower,
		automobile.WheelDiameter, automobile.Colour, automobile.GearType);
}
void InputGroup(Car* gr, int n) { //функция обьединения в группу
	for (size_t i = 0; i < n; i++)
	{
		Input(gr[i]);
		cout << "-----------------------------------------------" << endl;
	}
}
void PrintGroup(Car* gr, int n) { //функция вывода группы
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < n; i++)
		Print(gr[i]);
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
}
void FindByName(Car* gr, int n, const char* name) { //функция поиска значений.
	for (size_t i = 0; i < n; i++)
		if (strstr(strlwr(strdup(gr[i].Name)), strlwr(strdup(name))))
			Print(gr[i]);
}
int main() {
	const int countautomobile = 3;
	Car group[countautomobile]{
		{"Dodge Challenger 1", 4859, 115, 7.2, 425, 18, "Black", "5-speed manual transmission"},
		{"Ford Mustang Boss 429", 4760, 115, 7.0, 375, 16, "Medium dark blue", "4-Speed Manual" },
		{"Chevrolet COPO Camaro", 4724, 115, 8.0, 500, 14, "Red", "Muncie 4-Speed Manual" }
	};
	//InputGroup(group, countautomobile);
	PrintGroup(group, countautomobile);
	cout << "------------------------------------------------------------f-------------------------------------------------------------" << endl;
	FindByName(group, countautomobile, "d");
	cout << "------------------------------------------------------------f-------------------------------------------------------------" << endl;
}
*/

