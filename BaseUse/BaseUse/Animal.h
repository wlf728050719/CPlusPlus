#pragma once
class Animal//C++ʹ�ó�����ʵ��java,C#�ӿ�Ч����û��abstract�ؼ��֣���virtual�ؼ��֣���=0���治д�������ʾ�������麯��
{
public:
	virtual void walk() = 0;//���麯��
	bool isHunman() {//���Ա���������д
		return false;
	}
};

