#include "People.h"

People::People(string name,int age):country("China"),money(1000)
{
	this->name = name;	//C++ this��ʾ��ǰ�����ָ�룬�����������ԣ�����C++���Ա����ʵ��.��Ա��  �� ��ʵ��ִ��->��Ա��
	(*this).age = age;
}

void People::showInfo()
{
	cout <<"����: "<< this->age <<"����: "<< this->name <<"���"<<+this->money<< endl;
}

void People::falseBorrowMoneyTo(People other,int amount)
{
	cout << this->name << "�������" << other.name << amount<<endl;
	this->money -= amount;
	other.money += amount;//otherΪcopy�Ķ����ں�������ʱ�������������Զ�����
}

void People::TrueBorrowMoneyTo1(People &other,int amount)
{
	cout << this->name << "��ȷ����" << other.name << amount<<endl;
	this->money -= amount;
	other.money += amount;
}

void People::TrueBorrowMoneyTo2(People* other, int amount)
{
	cout << this->name << "��ȷ����" << other->name << amount << endl;
	this->money -= amount;
	other->money += amount;
}

void People::operator+(int money)
{
	cout << this->name << "���" << money << "Ԫ" << endl;
	this->money += money;
}

void People::walk()
{
	cout << "����������" << endl;
}

People::~People()
{
	cout << "Goodbye" << this->name << endl;
}
