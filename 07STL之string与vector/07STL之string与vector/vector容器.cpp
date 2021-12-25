#pragma once
using namespace std;
#include <iostream>
#include <vector>


void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//初始化
void test11(void)
{
	vector<int> v1;//默认构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	PrintVector(v1);

	vector<int> v2(v1.begin(), v1.end());//区间方式
	PrintVector(v2);

	vector<int> v3(10, 5);//n个elem
	PrintVector(v3);

	vector<int> v4(v3);//拷贝构造
	PrintVector(v4);
}
//赋值
void test12(void)
{
	//=
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	PrintVector(v1);
	vector<int> v2;
	v2 = v1;
	PrintVector(v2);

	//assign
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());//左开右闭
	PrintVector(v3);
	vector<int> v4;
	v4.assign(10, 5);
	PrintVector(v4);
}
//容量和大小
void test13(void)
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	PrintVector(v1);
	if (v1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
		cout << v1.capacity() << endl;//输出13，自动扩展，值不固定
		cout << v1.size() << endl;//输出10
	}
	v1.resize(5);//缩减
	PrintVector(v1);
	v1.resize(10);//扩增后默认用0填充
	PrintVector(v1);
	v1.resize(15, 3);//可指定扩增时的填充值
	PrintVector(v1);
}
//增删
void test14(void)
{
	//尾插
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	PrintVector(v1);
	//尾删
	v1.pop_back();
	PrintVector(v1);
	//利用迭代器随机插入
	v1.insert(v1.begin(), 100);//指定位置插入指定值
	PrintVector(v1);
	v1.insert(v1.begin() + 1, 2, 1000);//指定位置插入指定个数的指定值
	PrintVector(v1);
	//利用迭代器随机删除
	v1.erase(v1.begin());
	PrintVector(v1);
	v1.erase(v1.begin(), v1.end());//等价于v1.clear()
	PrintVector(v1);
}
//单个数据的访问
void test15(void)
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	//访问
	//[]
	for (int j = 0; j < (int)v1.size(); j++)
	{
		cout << v1[j] << " ";
	}
	cout << endl;
	//at
	for (int k = 0; k < (int)v1.size(); k++)
	{
		cout << v1.at(k) << " ";
	}
	cout << endl;
	//front back
	cout << v1.front() << endl;
	cout << v1.back() << endl;
}
//容器交换
void test16(void)
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	PrintVector(v1);
	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	PrintVector(v2);
	v1.swap(v2);//交换
	PrintVector(v1);
	PrintVector(v2);

	//实际用途
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << v.capacity() << endl;//大于100000
	cout << v.size() << endl;//100000
	v.resize(3);
	cout << v.capacity() << endl;//大于100000
	cout << v.size() << endl;//3，造成内存浪费
	vector<int>(v).swap(v);//收缩内存	
	//vector<int>(v)是创建一个匿名容器并且利用拷贝构造复制容器v的元素到该匿名对象（匿名对象的大小于容量相同且正好为元素个数）
	//.swap(v)则交换匿名容器与容器v，从而使v内存收缩
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}
//预留内存
void test17(void)
{
	//当已知所需元素个数的上限时进行预留内存，避免更改内存位置造成的开销
	vector<int> v;
	//预留内存
	v.reserve(100000);
	int count = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//计算更改内存位置的次数
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}
	}
	cout << count << endl;
}
//int main(void)
//{
//	//test11();
//	//test12();
//	//test13();
//	//test14();
//	//test15();
//	//test16();
//	test17();
//	return 0;
//}