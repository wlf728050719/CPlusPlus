#pragma once
#include<iostream>
#include"Animal.h"
using namespace std;
//����ö������
enum Fruits
{
	Apple = 0,
	Banana = 1,
	Watermelon = 2
};
class People:Animal
{
	private:
		int money;
		Fruits favotiteFruit=Apple;//ö����Ϊ��Ա,ʹ�ò���Fruits.Apple����java
	public:
		string name;
		string country;
		int age;
		People(string name,int age);//����ʱ��д��������Ҫ��cpp�ļ�����д
		People(string name, int age, int money,string country)//���캯������
		{
			this->name = name;
			this->age = age;
			this->country = country;
			this->money = money;
		}
		void showInfo();
		void falseBorrowMoneyTo(People other,int amount);
		void TrueBorrowMoneyTo1(People &other,int amount);
		void TrueBorrowMoneyTo2(People* other, int amount);
		void operator+(int money);//�����������
		void walk()override;//�������»����鷽�����ɲ��ӹؼ���override
		bool isHunman() { return true; }//�������»���һ�㷽��
		~People();


};


