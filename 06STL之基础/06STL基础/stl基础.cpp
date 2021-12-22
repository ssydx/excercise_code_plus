#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//STL(standard template library)标准模板库
//面向对象（封装继承多态）和泛型编程是为了提高代码的复用性
//STL核心是容器算法和迭代器
//容器和算法通过迭代器连接
//STL通过模板函数和类模板实现
//STL细分为容器 算法 迭代器 仿函数 适配器（配接器） 空间配置器
//容器用于存放数据（vector string deque stack queue list set map等）
//算法包括很多常用算法
//迭代器是容器和函数的胶合剂
//仿函数可作为算法的某种策略
//适配器与空间配置器不做介绍

//容器分为序列式容器（强调值的排序，元素具有固定位置），关联式容器（元素没有严格的物理顺序）
//算法分为质变算法（改变元素的内容，如拷贝删除替换排序），非质变算法（不改变元素内容，如查找遍历计数）
//迭代器：每个容器都有其专属迭代器，算法通过迭代器才能访问容器的内容（输入、输出、向前、双向、随机）


//vector与for_each
//void Print(int val)
//{
//	cout << val << endl;
//}
//void test1(void)
//{
//	//创建容器
//	vector<int> v;
//	//插入数据
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	//通过迭代器访问容器中的数据
//	vector<int>::iterator itbegin = v.begin();//指向首元素
//	vector<int>::iterator itend = v.end();//指向最后一个元素下一个位置
//	//第一种
//	//while (itbegin != itend)
//	//{
//	//	cout << *itbegin << endl;
//	//	itbegin++;
//	//}
//	//第二种
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;//it本质是指针
//		itbegin++;
//	}
//	//第三种
//	//for_each(v.begin(),v.end(),Print);//回调函数需要自定义一个打印对应数据类型的函数
//}
////自定义数据类型
//class Peo
//{
//public:
//	Peo(string name, int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	string m_name;
//	int m_age;
//};
////类
//void test2(void)
//{
//	vector<Peo> v;
//	Peo p1("aaa", 22);
//	Peo p2("bbb", 23);
//	Peo p3("ccc", 24);
//	Peo p4("ddd", 25);
//	Peo p5("eee", 26);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	for (vector<Peo>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << it->m_name << "   " << it->m_age << endl;
//	}
//
//}
////指针
//void test3(void)
//{
//	vector<Peo*> v;
//	Peo p1("aaa", 22);
//	Peo p2("bbb", 23);
//	Peo p3("ccc", 24);
//	Peo p4("ddd", 25);
//	Peo p5("eee", 26);
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//	for (vector<Peo*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << (*it)->m_name << "   " << (*it)->m_age << endl;
//	}
//
//}
////容器嵌套容器
//void test4(void)
//{
//	vector<vector<int>> v;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//	vector<int> v5;
//	for (int i = 0; i < 5; i++)
//	{
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//		v5.push_back(i + 5);
//	}
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//	v.push_back(v5);
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
//		{
//			cout << *vit << " ";
//		}
//		cout << endl;
//	}
//}
//int main(void)
//{
//	//test1();
//	//test2();
//	//test3();
//	test4();
//	return 0;
//}