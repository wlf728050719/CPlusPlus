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
			cout << "Ա��������" << this->name << "���䣺" << this->age << "������" << this->workName << endl;
			//cout << this->money; ���ܷ��ʻ����˽�г�Ա
		}

};

