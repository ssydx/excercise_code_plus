#pragma once
using namespace std;
#include <iostream>
#include <set>
#include <string>

//只能insert,不能resize

void PrintSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//初始化和赋值
void test41(void)
{
	set<int> s1;//默认构造
	//没有push_back/front
	//关联式容器会自动按照升序排列
	//不允许插入重复数据（不报错但也不插入）
	s1.insert(50);
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(40);
	PrintSet(s1);
	set<int> s2(s1);//拷贝构造
	PrintSet(s2);
	set<int> s3 = s2;
	PrintSet(s3);//赋值
}
//大小和交换
void test42(void)
{
	set<int> s1;
	s1.insert(50);
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(40);
	PrintSet(s1);
	//判空
	if (s1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << s1.size() << endl;//计算大小，不支持resize
	}
	//交换
	set<int> s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	s2.insert(500);
	PrintSet(s1);
	PrintSet(s2);
	s1.swap(s2);
	PrintSet(s1);
	PrintSet(s2);
}
//增删
void test43(void)
{
	set<int> s1;
	s1.insert(500);//插入
	s1.insert(200);
	s1.insert(300);
	s1.insert(400);
	s1.insert(100);
	PrintSet(s1);
	s1.erase(s1.begin());//删除，注意删除的是100
	PrintSet(s1);
	s1.erase(300);//删除指定元素
	PrintSet(s1);
	s1.clear();//等价于	s1.erase(s1.begin(), s1.end())
	PrintSet(s1);
}
//查找和统计
void test44(void)
{
	set<int> s1;
	s1.insert(500);
	s1.insert(200);
	s1.insert(300);
	s1.insert(400);
	s1.insert(100);
	s1.insert(100);
	PrintSet(s1);
	//查找，返回迭代器（查找不到返回s1.end()）
	set<int> ::iterator pos = s1.find(900);
	if (pos == s1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *pos << endl;
	}
	//统计，对于set只有0和1，对于multiset则不同
	int count = s1.count(100);
	cout << count << endl;//输出1
	count = s1.count(900);
	cout << count << endl;//输出0
	multiset<int> ms1;
	ms1.insert(10);//可重复，仍按升序排列
	ms1.insert(20);
	ms1.insert(20);
	ms1.insert(20);
	ms1.insert(10);
	for (multiset<int>::iterator mit = ms1.begin(); mit != ms1.end(); mit++)
	{
		cout << *mit << " ";
	}
	cout << endl;
	int mcount = ms1.count(10);
	cout << mcount << endl;//输出2
	mcount = ms1.count(5);
	cout << mcount << endl;
}
//set和multiset
void test45(void)
{
	//set
	set<int> s1;
	s1.insert(100);//返回值是pair<迭代器,bool>，使用时采用变量.second
	pair<set<int>::iterator, bool> ret = s1.insert(200);
	if (ret.second)
	{
		cout << "success 1" << endl;//成功
	}
	else
	{
		cout << "fail 1" << endl;
	}
	ret = s1.insert(200);
	if (ret.second)
	{
		cout << "success 1" << endl;
	}
	else
	{
		cout << "fail 1" << endl;//失败
	}
	//multiset
	multiset<int> ms1;
	ms1.insert(10);//可重复，仍按升序排列
	ms1.insert(20);//返回值是迭代器
	ms1.insert(20);
	ms1.insert(20);
	ms1.insert(10);
}
//pair对组，无头文件
void test46(void)
{
	//初始化
	pair<string, int> p1;//默认构造
	pair<string, int> p2("lisi", 20);//有参构造
	cout << p2.first << "  " << p2.second << endl;
	pair<string, int> p3(p2);//拷贝构造
	cout << p3.first << "  " << p3.second << endl;
	//赋值
	pair<string, int> p4;
	p4 = make_pair("wangwu", 18);//推荐
	cout << p4.first << "  " << p4.second << endl;
	pair<string, int> p5;
	p5.first = "zhangsan";
	p5.second = 16;
	cout << p5.first << "  " << p5.second << endl;
	pair<string, int> p6;
	p6 = p5;
	cout << p6.first << "  " << p6.second << endl;
}
//排序
class Comp1
{
public:
	bool operator()(const int& v1, const int& v2) const//VS必须使用const修饰，const本质修饰的是this指针
	{
		return v1 > v2;
	}
};
void test47(void)
{
	//插入数据前指定排序规则（利用仿函数）
	set<int, Comp1> s1;
	s1.insert(500);
	s1.insert(200);
	s1.insert(300);
	s1.insert(400);
	s1.insert(100);
	//s1.insert(100);
	for (set<int, Comp1>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//自定义类型数据的自定义排序
class Peo
{
public:
	Peo(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
class Comp2
{
public:
	bool operator()(const Peo& p1, const Peo& p2) const
	{
		return p1.m_age > p2.m_age;
	}
};
void test48(void)
{
	set<Peo, Comp2> s1;
	Peo p1("刘备", 35);
	Peo p2("曹操", 45);
	Peo p3("孙权", 40);
	Peo p4("赵云", 25);
	Peo p5("张飞", 36);
	Peo p6("关羽", 35);//注意即使是年龄相同名字不同也算重复数据
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	s1.insert(p6);
	for (set<Peo, Comp2>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << it->m_name << "  " << it->m_age << endl;
	}
}

//int main(void)
//{
//	//test41();
//	//test42();
//	//test43();
//	//test44();
//	//test45();
//	//test46();
//	//test47();
//	test48();
//	return 0;
//}