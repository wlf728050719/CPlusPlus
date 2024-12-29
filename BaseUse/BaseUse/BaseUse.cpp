#include<iostream>
#include<sstream>
#include<string>
#include"People.h" //.h文件用引号导入
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define inputIndex 0
using namespace std;
//默认实参
int add(int a, int b = 0)
{
	return a + b;
}
//不允许再定义int add(int a)否则add(1)时程序无法确定调用哪个函数

//C++模板 类似C# java泛型
template<class T,class U>
void judgeType(T t, U u)
{
	cout << typeid(t).name() << endl;
	cout << typeid(u).name() << endl;
}

int main()
{	
	cout << add(1) << endl;
	judgeType(1, '1');
	//类型转换
	{
		int a = 1;
		float b = 2.0;
		string str_a = to_string(a);//数字转字符串
		string str_b = to_string(b);

		string str_c = "3";
		string str_d = "4.0";
		int c = stoi(str_c);//字符串转数字
		float d = stof(str_d);

		char e = 'e';
		string str_e(1, e);//字符转字符串

		string str_f= "f";
		char f = str_f[0];//字符串转字符

		char array[] = { 'a','b','c' ,'\0'};//字符数组转string 需要加结束符号
		string str_array = array;

		for (int i = 0; i < str_array.length(); i++)//字符串长度不包括结束符
		{
			cout << str_array[i] << " ";
		}
		cout << endl;

		cout << a << " " << b << " " << c << " " << d <<" "<<e<<" "<<f<< endl;
		cout << str_a << " " << str_b << " " << str_c << " " << str_d <<" "<<str_e<<" "<<str_f<<" "<<str_array<<endl;

	}
	#if inputIndex==1
	//一次换行对应一次cin
	{//输入两个数据，一个数字，一个字符串
		cout << "输入两个数据，一个数字，一个字符串换行或空格分割" << endl;
		int a;
		string b;
		cin >> a >> b;
		cout << a << " " << b << endl;
	}
	#endif 

	#if inputIndex==2
	{//处理一行空格分割的输入
		cout << "输入一行空格分割的数据（数字类型）" << endl;
		string input;
		getline(cin, input);
		stringstream ss(input);
		int num;
		int sum = 0;
		while (ss >> num)
		{
			sum += num;
		}
		cout << sum <<endl;
	}
	#endif 

	#if inputIndex==3
	{
		//处理一行逗号分割的输入
		cout << "输入一行逗号分割的数据（数字类型）" << endl;
		string input;
		getline(cin, input);
		stringstream ss(input);
		string num;
		int sum = 0;
		while (getline(ss, num, ','))
		{
			sum += stoi(num);
		}
		cout << sum << endl;
	}
	#endif 

	#if inputIndex==4
	{
		//处理多行输入以end结尾数据
		cout << "输入若干行数据（数字类型)以end结尾" << endl;
		string input;
		int sum = 0;
		while (cin >> input)
		{
			if (input == "end")
				break;
			sum += stoi(input);
		}
		cout << sum << endl;
	}
	#endif 
	
	//类对象使用
	People xyw("xyw", 22);	//获取对象 存储栈上
	People lfc("lfc", 22);
	People* mmc = new People("mmc", 22);//通过new获取对象指针 存储堆上
	cout << "初始状态" << endl;
	xyw.showInfo();
	lfc.showInfo();
	mmc->showInfo();
	xyw.falseBorrowMoneyTo(lfc, 100);//传递值导致错误
	xyw.showInfo();
	lfc.showInfo();
	xyw.TrueBorrowMoneyTo1(lfc, 100);//引用传递正确
	xyw.showInfo();
	lfc.showInfo();
	xyw.TrueBorrowMoneyTo2(mmc, 100);//指针传递正确
	xyw.showInfo();
	mmc->showInfo();
	xyw + 100;
	xyw.showInfo();
	xyw.walk();
	if (xyw.isHunman())
	{
		cout << xyw.name<<"是人" << endl;
	}
	else
	{
		cout << xyw.name << "诗人握持" << endl;
	}

	//Vector
	{
		//数组向量
		vector<int> numbers = { 1,2,3,4,5,6,7};
		numbers.pop_back();//没有返回值，区分java stack.pop
		numbers.push_back(8);
		//迭代器访问删除满足条件元素固定写法
		for (vector<int>::iterator i = numbers.begin(); i != numbers.end();)
		{
			cout <<"迭代器访问"<< *i <<endl;
			if (*i > 5)//删除大于5的元素
			{
				i = numbers.erase(i);//更新迭代器 erase返回删除元素后面一个的迭代器
			}
			else
				i++;
		}
		cout << "末尾数字" << numbers.back() <<" "<< numbers[numbers.size() - 1] << endl; //通过下标直接随机访问
		cout << "开头数字" << numbers.front() << " "<<numbers[0] << endl;
		for (int i : numbers)
			cout << i << " ";
		cout << endl;
		//同理迭代器插入元素
		for (vector<int>::iterator i = numbers.begin(); i != numbers.end();i++)
		{
			cout << "迭代器访问" << *i << endl;
			if (*i > 0)//在大于0的元素前插99
			{
				i=numbers.insert(i,99)+1;   //insert返回指向插入新元素的迭代器
			}

		}
		for (int i : numbers)
			cout << i << " ";
		cout << endl;
		int findnumber = 10;
		vector<int>::iterator it = find(numbers.begin(),numbers.end(), findnumber);//find返回指向找到元素的迭代器
		if (it != numbers.end())
			cout << "找到元素" << findnumber<<endl;
		else
			cout << "找不到元素" << findnumber << endl;
		
		//对象向量
		vector<People> peopleList = {xyw,lfc,*mmc };//值传递，而非引用区分java C#的List，用指针数组实现List效果
		for (int i = 0; i < peopleList.size(); i++)
		{
			peopleList[i].name = "xxx";
		}
		xyw.showInfo();//不会影响原对象
		lfc.showInfo();
		(*mmc).showInfo();

		for (People p : peopleList)//类似java，C# foreach，但同样是值传递
		{
			p.name = "yyy";
		}
		for (People p : peopleList)
		{
			p.showInfo();
		}

	}
	//List 常用函数和vector一致，list底层双向链表，随机访问慢o(n)，插删快o(1)，vector底层动态数组，随机访问快o(1)，插删慢o(n)
	//Queue 不能使用迭代器访问
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.pop();
		cout <<"开头"<< q.front() << " 结尾:" << q.back() << endl;
		if (!q.empty())
			cout << "队列非空" << endl;
		int findnumber = 10;
	}
	//Stack 不能使用迭代器访问
	{
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.pop();
		cout << "栈顶" << s.top() << endl;
		if (!s.empty())
			cout << "栈非空" << endl;
	}
	//Set
	{
		set<int> mySet = {1,2,3,4,5,5};//即使初始化时有重复元素实际也会保证元素唯一
		mySet.insert(6);//增
		mySet.insert(6);//增相同不会报错
		mySet.erase(3);//删
		mySet.erase(-1);//删不存在不会报错
		for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) { //虽然能通过迭代器遍历，但不能下标随机访问
			cout << *it << " ";
		}
		cout << endl;
		int findnumber = 5;
		set<int>::iterator it = mySet.find(findnumber);//与vector区分
		if (it != mySet.end())
			cout << "存在元素" << findnumber << endl;
		else
			cout << "不存在元素" << findnumber << endl;
		cout << mySet.count(findnumber) << endl;//只会输出0或1判断元素是否在其中最简单方法
	}
	//Map
	{
		map<string, int> m;
		m["1"] = 1;	//增
		m["2"] = 2;
		m["temp"] = -1;
		m["temp"] = 0;//改
		m.erase("2");//删
		
		for (auto& pair : m)//隐式遍历 注意是引用
		{
			cout << "key:" << pair.first << endl;
			pair.second++;
		}
		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)//显示遍历
		{
			cout << "key:" << it->first << "value:" << it->second << endl;
		}

	}

	delete(mmc);//手动销毁对象
}
     