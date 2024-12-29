#pragma once
#include<iostream>
#include<string>
#include"People.h"
using namespace std;
class Employee:People
{
	public :
		string workName;
		Employee(string name,int age,string workName) :People(name,age)
		{
			this->workName = workName;
			cout << "员工姓名：" << this->name << "年龄：" << this->age << "工作：" << this->workName << endl;
			//cout << this->money; 不能访问基类的私有成员
		}

};

