#pragma once
using namespace std;
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

//链表（STL中是双向循环链表）
//可在任意位置快速增删
//访问速度慢，不可随机存取
//动态分配内存不会造成内存浪费和溢出
//占用空间较大
//双向迭代器，不是随机迭代器
//注意，除非在表头进行增删，否则不会影响迭代器（vector每次内存不足都会在新位置开辟内存，迭代器也将改变）

void PrintList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//初始化
void test31(void)
{
	list<int> l1;//默认构造
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);

	list<int>l2(l1.begin(), l1.end());//区间方式
	PrintList(l2);

	list<int> l3(10, 5);//n个elem
	PrintList(l3);

	list<int> l4(l3);//拷贝构造
	PrintList(l4);
}
//赋值
void test32(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);
	//=
	list<int> l2 = l1;
	PrintList(l2);
	//assign
	list<int> l3;
	l3.assign(10, 5);
	PrintList(l3);
	list<int> l4;
	l4.assign(l3.begin(), l3.end());
	PrintList(l4);
}
//交换
void test33(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	list<int> l2;
	l2.assign(10, 5);
	PrintList(l1);
	PrintList(l2);
	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);
}
//大小
void test34(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);
	cout << l1.size() << endl;
	l1.resize(5);
	PrintList(l1);
	l1.resize(10);
	PrintList(l1);
	if (l1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << l1.size() << endl;
	}
}
//增删
void test35(void)
{
	list<int> l1;
	l1.push_back(10);//尾增
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	l1.push_front(100);//头增
	l1.push_front(200);
	l1.push_front(300);
	l1.push_front(400);
	l1.push_front(500);
	PrintList(l1);
	l1.pop_back();//尾删
	PrintList(l1);
	l1.pop_front();//头删
	PrintList(l1);
	//注意list的迭代器只能使用++和--进行偏移
	l1.insert(++l1.begin(), 1000);
	PrintList(l1);
	l1.erase(----l1.end());
	PrintList(l1);
	//删除指定元素（重复则全部删除）
	l1.insert(++l1.begin(), 1000);
	PrintList(l1);
	l1.remove(1000);
	PrintList(l1);
	l1.clear();//等价于l1.erase(l1.begin(), l1.end())
	PrintList(l1);
}
//单个元素访问（没有[]和at，只能直接访问首元素和尾元素）
void test36(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	cout << l1.front() << endl;
	cout << l1.back() << endl;
	//cout << *(l1.begin() + 1) << endl;不允许
}
//反转和排序
bool smaller(int v1, int v2)
{
	return v1 > v2;//降序，可记作指向右侧变小
}
void test37(void)
{
	//反转
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);
	l1.reverse();
	PrintList(l1);
	//排序
	list<int> l2;
	l2.push_back(10);
	l2.push_back(40);
	l2.push_back(30);
	l2.push_back(20);
	l2.push_back(50);
	PrintList(l2);
	//sort(l2.begin(),l2.end());
	//不支持随机访问的迭代器都不能使用标准算法
	//这种迭代器会提供内部算法（方法）
	l2.sort();//默认升序
	PrintList(l2);
	l2.sort(smaller);//降序（回调函数）
	PrintList(l2);
}

//int main(void)
//{
//	//test31();
//	//test32();
//	//test33();
//	//test34();
//	//test35();
//	//test36();
//	test37();
//	return 0;
//}