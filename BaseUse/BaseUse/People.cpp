#include "People.h"

People::People(string name,int age):country("China"),money(1000)
{
	this->name = name;	//C++ this表示当前对象的指针，区分其他语言，访问C++类成员：类实例.成员名  或 类实例执政->成员名
	(*this).age = age;
}

void People::showInfo()
{
	cout <<"年龄: "<< this->age <<"姓名: "<< this->name <<"存款"<<+this->money<< endl;
}

void People::falseBorrowMoneyTo(People other,int amount)
{
	cout << this->name << "错误借了" << other.name << amount<<endl;
	this->money -= amount;
	other.money += amount;//other为copy的对象，在函数结束时调用析构函数自动销毁
}

void People::TrueBorrowMoneyTo1(People &other,int amount)
{
	cout << this->name << "正确借了" << other.name << amount<<endl;
	this->money -= amount;
	other.money += amount;
}

void People::TrueBorrowMoneyTo2(People* other, int amount)
{
	cout << this->name << "正确借了" << other->name << amount << endl;
	this->money -= amount;
	other->money += amount;
}

void People::operator+(int money)
{
	cout << this->name << "获得" << money << "元" << endl;
	this->money += money;
}

void People::walk()
{
	cout << "用两条腿走" << endl;
}

People::~People()
{
	cout << "Goodbye" << this->name << endl;
}
