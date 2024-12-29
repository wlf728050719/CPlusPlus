#pragma once
class Animal//C++使用抽象类实现java,C#接口效果，没有abstract关键字，有virtual关键字，用=0代替不写方法体表示函数纯虚函数
{
public:
	virtual void walk() = 0;//纯虚函数
	bool isHunman() {//可以被派生类重写
		return false;
	}
};

