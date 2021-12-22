#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//仿函数可以像函数一样使用，本质是类中的重载()，更加灵活自由

//加法仿函数
class Add_f
{
public:
	int operator()(int v1, int v2)//可以有参数可以有返回值
	{
		return v1 + v2;
	}
};
//打印仿函数
void test_f1(void)
{
	Add_f myadd;
	int ret = myadd(10, 20);//本质是add.operator()(10,20)
	cout << ret << endl;
}
class Print_f
{
public:
	Print_f()
	{
		m_count = 0;
	}
	void operator()(const string& text)
	{
		cout << text << endl;
		m_count++;
	}
	int m_count;//可以利用属性记录内部状态
};
void test_f2(void)
{
	Print_f myprint;
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	cout << myprint.m_count << endl;
}
//回调函数
void DoPrint(Print_f& p, string text)//函数对象可作为参数传递
{
	p(text);
}
void test_f3(void)
{
	Print_f myprint;
	DoPrint(myprint, "hello world");
}
//谓词，返回值为bool的仿函数
//一元谓词，仿函数一个参数
class Greater5
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};
void test_f4(void)
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	Greater5 mygreater5;
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), mygreater5);
	if (it == v1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}
//二元谓词，仿函数两个参数
class Comp_f
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test_f5(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(50);
	Comp_f mycomp;
	//sort(v1.begin(), v1.end(), Comp_f());//默认升序，自定义排序：注意匿名时必须包含()
	sort(v1.begin(), v1.end(), mycomp);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//内建仿函数模板
//算术,negate plus minus divides modulus multiplies
void test_f6(void)
{
	//取反，一元谓词
	negate<int> n1;
	cout << n1(50) << endl;
	//加法，二元谓词
	plus<int> p1;
	cout << p1(20, 10) << endl;
}
//关系,equal_to not_equal_to greater greater_equal less less_equal
void test_f7(void)
{
	//大于
	greater<int> g1;
	cout << g1(20, 10) << endl;//前者大于后者返回1
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(4);
	v1.push_back(2);
	sort(v1.begin(), v1.end(), g1);
	for (int i = 0; i < 5; i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}
//逻辑,logical_and logical_or logical_not
void test_f8(void)
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(0);
	v1.push_back(1);
	for (int i = 0; i < 4; i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	vector<int> v2;
	v2.resize(v1.size());//注意搬运前必须先开辟足够大的空间
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());//搬运的同时对每个元素进行逻辑非
	for (int i = 0; i < 4; i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
}

//int main(void)
//{
//	//test_f1();
//	//test_f2();
//	//test_f3();
//	//test_f4();
//	//test_f5();
//	//test_f6();
//	//test_f7();
//	test_f8();
//	return 0;
//}