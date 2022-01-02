#pragma once
using namespace std;
#include <iostream>
#include <map>
#include <string>

//map中所有元素都是pair
//第一个是key，第二个是value
//根据key进行排序
void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}
	cout << endl;
}
//初始化和赋值
void test51(void)
{
	//初始化
	map<int, int> m1;//默认构造
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	m1.insert(pair<int, int>(3, 50));//重复则不插入
	PrintMap(m1);
	map<int, int> m2(m1);//拷贝构造
	PrintMap(m2);
	//赋值
	map<int, int> m3;
	m3 = m2;
	PrintMap(m3);
}
//大小和交换
void test52(void)
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	PrintMap(m1);
	if (m1.empty())//判空
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << m1.size() << endl;//大小
	}
	//交换
	map<int, int> m2;
	m2.insert(pair<int, int>(5, 100));
	m2.insert(pair<int, int>(2, 600));
	PrintMap(m1);
	PrintMap(m2);
	m1.swap(m2);
	PrintMap(m1);
	PrintMap(m2);
}
//增删
void test53(void)
{
	//增加
	map<int, int> m1;
	//第一种
	m1.insert(pair<int, int>(1, 10));
	//第二种，推荐
	m1.insert(make_pair(2, 20));
	//第三种，极不推荐
	m1.insert(map<int, int>::value_type(3, 30));
	//第四种，不建议用其插入（会导致不存在的key被加入map），通常用其进行访问
	m1[4] = 40;
	//cout << m1[5] << endl;
	PrintMap(m1);
	//删除
	m1.erase(m1.begin());//按迭代器删除
	PrintMap(m1);
	m1.erase(4);//按key进行删除
	//m1.erase(30);不能按value进行删除
	PrintMap(m1);
	m1.clear();//注意等价的区间形式
	PrintMap(m1);
}
//查找和统计，与set相同
void test54(void)
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	m1.insert(pair<int, int>(3, 50));//重复则不插入
	//查找，同样返回迭代器
	map<int, int>::iterator pos = m1.find(3);
	if (pos == m1.end())
	{
		cout << "fail" << endl;
	}
	else
	{
		cout << pos->second << endl;
	}
	//统计
	int count = m1.count(3);
	cout << count << endl;//输出1
	count = m1.count(5);
	cout << count << endl;//输出0
	//multimap不再测试
}
//排序
class Comp11
{
public:
	bool operator()(int v1, int v2) const//不能以引用方式传递？
	{
		return v1 > v2;
	}
};
void test55(void)
{
	map<int, int, Comp11> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	m1.insert(pair<int, int>(3, 50));
	for (map<int, int, Comp11>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}
	cout << endl;
}
//自定义数据类型的自定义排序
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
class Comp12
{
public:
	bool operator()(Peo p1, Peo p2) const//不能以引用方式传递？
	{
		return p1.m_age > p2.m_age;
	}
};
void test56(void)
{
	map<Peo, int, Comp12> m1;
	Peo p1("刘备", 35);
	Peo p2("曹操", 45);
	Peo p3("孙权", 40);
	Peo p4("赵云", 25);
	Peo p5("张飞", 36);
	Peo p6("关羽", 35);
	m1.insert(make_pair(p1, 170));
	m1.insert(make_pair(p2, 175));
	m1.insert(make_pair(p3, 160));
	m1.insert(make_pair(p4, 185));
	m1.insert(make_pair(p5, 190));
	m1.insert(make_pair(p6, 180));
	for (map<Peo, int, Comp12>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << it->first.m_name << "  " << it->first.m_age << "  " << it->second << endl;
	}
}

//int main(void)
//{
//	//test51();
//	//test52();
//	//test53();
//	//test54();
//	//test55();
//	test56();
//	return 0;
//}