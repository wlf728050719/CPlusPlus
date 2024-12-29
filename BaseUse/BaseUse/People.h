#pragma once
#include<iostream>
#include"Animal.h"
using namespace std;
//定义枚举类型
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
		Fruits favotiteFruit=Apple;//枚举作为成员,使用不用Fruits.Apple区分java
	public:
		string name;
		string country;
		int age;
		People(string name,int age);//定义时不写函数体需要在cpp文件中填写
		People(string name, int age, int money,string country)//构造函数重载
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
		void operator+(int money);//类运算符重载
		void walk()override;//必须重新基类虚方法，可不加关键字override
		bool isHunman() { return true; }//可以重新基类一般方法
		~People();


};


