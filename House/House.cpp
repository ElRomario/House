/*Создайте программу, имитирующую многоквартирный 
дом. Необходимо иметь классы “Человек”, “Квартира”, 
“Дом”. Класс “Квартира” содержит динамический массив 
объектов класса “Человек”. Класс “Дом” содержит массив 
объектов класса “Квартира”. 
Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области 
класса. Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для 
ФИО в классе “Человек”. Не забывайте обеспечить классы 
различными конструкторами (конструктор копирования 
обязателен), деструкторами. В main протестировать работу полученного набора классов*/

#include <iostream>
#include <vector>
using namespace std;
class Human
{
private:
	string name;
public:
	Human(string name) : name(name) {};
	void printHuman()
	{
		cout << "Name: " << name<<endl;
	}
	Human(const Human &human)
	{
		name = human.name;
	}
	friend class Apartment;
	~Human() {};
};
class Apartment
{
private:
	int aprtNum;
	vector <Human> humanVector;
public:
	Apartment(int aprtNum, vector<Human>humanVector)
	{
		this->aprtNum = aprtNum;
		this->humanVector = humanVector;
	}
	void apartPrint()
	{
		cout << "================Apartment #" << aprtNum<<"==================" << endl;
		cout << "======Residents=========" << endl;
		for (int i = 0; i < humanVector.size(); i++)
		{
			humanVector[i].printHuman();
		}
	}
	Apartment(const Apartment& apartment)
	{
		aprtNum = apartment.aprtNum;
		humanVector = apartment.humanVector;
	}
	friend class House;
	~Apartment() {};
	
};
class House
{
private:
	int houseNum;
	vector <Apartment> apartmentVector;
public:
	House(int houseNum, vector<Apartment> apartmentVector)
	{
		this->houseNum = houseNum;
		this->apartmentVector = apartmentVector;
	}
	House(const House& house)
	{
		houseNum = house.houseNum;
		apartmentVector = house.apartmentVector;
	}
	void houseApartmentPrint()
	{
		cout << "========================House #" << houseNum <<"========================" << endl;
		for (int i = 0; i < apartmentVector.size(); i++)
		{
			apartmentVector[i].apartPrint();
		}
		cout << "=========================================================" << endl;

	}
	~House() {};
};
int main()
{
	string peter = "Peter";
	string andrew = "Andrew";
	string steven = "Steven";
	string fred = "Fred";

	Human Peter(peter);
	Human Andrew(andrew);
	Human Steven(steven);
	Human Fred(fred);
	vector <Human> people{ peter, andrew };
	vector <Human> people2{ Steven, Fred };
	Apartment ap1(12, people);
	Apartment ap2(13, people2);
	vector <Apartment> aps{ap1, ap2};
	House house1(31, aps);

	house1.houseApartmentPrint();


	string stefan = "stefan";
	string liberty = "liberty";
	string nigger = "nigger";
	string quanty = "quanty";

	Human Stefan(stefan);
	Human Liberty(liberty);
	Human Nigger(nigger);
	Human Quanty(quanty);
	vector <Human> people3{ Stefan, Liberty };
	vector <Human> people4{ Quanty, Nigger };
	Apartment ap3(14, people3);
	Apartment ap4(15, people4);
	vector <Apartment> aps1{ ap3, ap4 };
	House house2(45, aps1);

	house2.houseApartmentPrint();
}

