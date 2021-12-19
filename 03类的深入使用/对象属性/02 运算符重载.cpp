#pragma once
using namespace std;
#include <iostream>
#include <string>
//运算符重载
//内置数据类型编译器知道如何计算，不要尝试修改
//类或结构体需要进行运算符重载，但应做到清楚易懂

//+的重载

//class C
//{
//public:
//	//运算符+的重载（方法）
//	//C operator+(C& c)
//	//{
//	//	C tmp;
//	//	tmp.m_a = this->m_a + c.m_a;
//	//	tmp.m_b = this->m_b + c.m_b;
//	//	return tmp;
//	//}
//public:
//	int m_a;
//	int m_b;
//};
////运算符+的重载（函数）
//C operator+(C& c1,C& c2)
//{
//	C tmp;
//	tmp.m_a = c1.m_a + c2.m_a;
//	tmp.m_b = c1.m_b + c2.m_b;
//	return tmp;
//}
//C operator+(C& c1, int x)
//{
//	C tmp;
//	tmp.m_a = c1.m_a + x;
//	tmp.m_b = c1.m_b + x;
//	return tmp;
//}
//void test1(void)
//{
//	C c1;
//	c1.m_a = 10;
//	c1.m_b = 5;
//	C c2;
//	c2.m_a = 15;
//	c2.m_b = 25;
//	C c3 = c1 + c2;//本质是c1.operator+(c2)或operator+(c1,c2)
//	c3 = c3 + 10;//运算符重载的函数重载
//	cout << c3.m_a << " " << c3.m_b << endl;
//}
//int main(void)
//{
//	test1();
//	return 0;
//}



//<<的重载

//class C
//{
//	friend ostream& operator<<(ostream& out, C& c);
//public:
//	C(int a, int b)
//	{
//		m_a = a;
//		m_b = b;
//	}
//private:
//	int m_a;
//	int m_b;
//};
////通常采用函数重载而不是方法重载
////cout的数据类型为ostream，返回值设为ostream&则能达到链式调用的目的
//ostream& operator<<(ostream &out,C& c)
//{
//	out << c.m_a << " " << c.m_b;
//	return out;
//}
//void test1(void)
//{
//	C c1(10,10);
//	cout << c1 << endl;//本质是operator<<(cout,c1)
//}
//int main(void)
//{
//	test1();
//	return 0;
//}



//++的重载

//class MyInt
//{
//	friend ostream& operator<<(ostream& cout, MyInt i);
//public:
//	MyInt()
//	{
//		m_a = 0;
//	}
//	//前置
//	MyInt& operator++()
//	{
//		m_a++;
//		return *this;
//	}
//	//后置，注意如何实现
//	MyInt operator++(int)//利用int占位参数区分，返回局部变量为值而不是引用
//	{
//		MyInt tmp = *this;
//		m_a++;
//		return tmp;
//	}
//private:
//	int m_a;
//};
//ostream& operator<<(ostream& cout, MyInt i)
//{
//	cout << i.m_a;
//	return cout;
//}
//void test1(void)
//{
//	MyInt i;
//
//	cout << ++i << endl;//输出1
//	cout << i++ << endl;//输出1
//	cout << i << endl;//输出2
//}
//int main(void)
//{
//	test1();
//	return 0;
//}



//=的重载

//class Peo
//{
//public:
//	Peo& operator=(Peo& p)
//	{
//		//m_age = p.m_age;默认重载
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//		m_age = new int(*p.m_age);
//		return *this;
//	}
//	Peo(int age)
//	{
//		m_age = new int(age);
//	}
//	~Peo()
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//	}
//	int* m_age;
//};
//void test1(void)
//{
//	Peo p(18);
//	cout << *p.m_age << endl;
//	Peo p1(20);
//	//p1 = p;//默认赋值，相当于默认拷贝构造函数
//	Peo p2(30);
//	p2 = p1 = p;//链式赋值
//	cout << *p2.m_age << endl;
//}
//int main(void)
//{
//	test1();
//	return 0;
//}



//==的重载

//class Peo
//{
//public:
//	Peo(string name,int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	bool operator==(Peo& p)
//	{
//		if (m_name == p.m_name && m_age == p.m_age)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool operator!=(Peo& p)
//	{
//		if (m_name == p.m_name && m_age == p.m_age)
//		{
//			return false;
//		}
//		return true;
//	}
//	string m_name;
//	int m_age;
//};
//void test1(void)
//{
//	Peo p1("tom", 20);
//	Peo p2("tom", 20);
//	if (p1 == p2)
//	{
//		cout << "equal" << endl;
//	}
//	else
//	{
//		cout << "unequal" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "unequal" << endl;
//	}
//	else
//	{
//		cout << "equal" << endl;
//	}
//}
//int main(void)
//{
//	test1();
//	return 0;
//}



//()的重载，仿函数常用

//class MyPrint
//{
//public:
//	void operator()(string text)
//	{
//		cout << text << endl;
//	}
//};
//void test1(void)
//{
//	MyPrint myprint;
//	myprint("hello world");//又称仿函数
//
//}
//class MyAdd
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//void test2(void)
//{
//	MyAdd myadd;
//	int ret = myadd(10, 20);
//	cout << ret << endl;
//	cout << MyAdd()(100, 200) << endl;//匿名对象
//}
//int main(void)
//{
//	test1();
//	test2();
//	return 0;
//}
