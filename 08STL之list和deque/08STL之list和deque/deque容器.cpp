#pragma once
using namespace std;
#include <iostream>
#include <deque>
#include <algorithm>

//双端数组
//vector 对于头部的插入删除效率较低
//deque 访问较慢（利用中控器进行记录）

void PrintDeque(const deque<int>& d)//加const
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//迭代器也要变为const版
	{
		//*it = 100;不可修改
		cout << *it << " ";
	}
	cout << endl;
}
//初始化
void test21(void)
{
	deque<int> d1;//默认构造
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	PrintDeque(d1);

	deque<int> d2(d1.begin(), d1.end());//区间方式
	PrintDeque(d2);

	deque<int> d3(10, 100);//n个elem
	PrintDeque(d3);

	deque<int> d4(d3);//拷贝构造
	PrintDeque(d4);
}
//赋值
void test22(void)
{
	//=
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	PrintDeque(d1);
	deque<int> d2;
	d2 = d1;
	PrintDeque(d2);

	//assign
	deque<int> d3;
	d3.assign(d2.begin(), d2.end());
	PrintDeque(d3);
	deque<int> d4;
	d4.assign(10, 5);
	PrintDeque(d4);
}
//大小（没有容量的概念）
void test23(void)
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	PrintDeque(d1);

	if (d1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << d1.size() << endl;
	}
	//同理
	d1.resize(5);
	PrintDeque(d1);
	d1.resize(10);
	PrintDeque(d1);
}
//增删
void test24(void)
{
	deque<int> d1;
	//插入
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	PrintDeque(d1);
	//删除
	d1.pop_back();
	PrintDeque(d1);
	d1.pop_front();
	PrintDeque(d1);
	//随机增加
	d1.insert(d1.begin(), 1000);//指定位置插入指定值
	PrintDeque(d1);
	d1.insert(d1.begin(), 2, 2000);//指定位置插入指定个数的指定值
	PrintDeque(d1);
	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());//指定位置插入另一容器指定区间的值
	PrintDeque(d1);
	//随机删除
	d1.erase(++d1.begin());
	PrintDeque(d1);
	d1.erase(d1.begin(), d1.end());//等价于d1.clear()
	PrintDeque(d1);
}
//单个元素的访问
void test25(void)
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	//[]
	for (int i = 0; i < (int)d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	//at
	for (int i = 0; i < (int)d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;
	//首尾
	cout << d1.front() << endl;
	cout << d1.back() << endl;
}
//排序
void test26(void)
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	PrintDeque(d1);
	sort(d1.begin(), d1.end());//默认升序
	//支持随机访问迭代器的容器都可使用sort算法，比如deque和vector
	PrintDeque(d1);
}
//int main(void)
//{
//	//test21();
//	//test22();
//	//test23();
//	//test24();
//	//test25();
//	test26();
//	return 0;
//}