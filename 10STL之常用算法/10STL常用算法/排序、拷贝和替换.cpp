#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>//内置仿函数模板
#include <ctime>
#include <numeric>//accumulate

void Print_a(int i)
{
	cout << i << " ";
}
//排序sort，极其重要
class Greater
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test_al9(void)
{
	vector<int> v;
	v.push_back(9);
	v.push_back(5);
	v.push_back(2);
	v.push_back(10);
	v.push_back(7);
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	sort(v.begin(), v.end());//默认升序
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	sort(v.begin(), v.end(), Greater());//利用自定义仿函数降序
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	sort(v.begin(), v.end(), less<int>());//利用内建仿函数模板升序
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//乱序random_shuffle
void test_al10(void)
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}
	srand((unsigned int)time(NULL));//记得加种子
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//合并merge，将升序的两个容器合并为一个升序的容器
void test_al11()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	vtar.resize(v1.size() + v2.size());//必须提前开辟足够的内存
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());//必须传入升序的vector合并后依然升序
	for_each(vtar.begin(), vtar.end(), Print_a);
	cout << endl;
}
//反转reverse
void test_al12(void)
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	reverse(v.begin(), v.end());//反转
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//拷贝copy，内置数据可直接用=或assgin，自定义数据才需考虑
void test_al13(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(30);
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), Print_a);
	cout << endl;
}
//替换replace
void test_al14(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(20);
	replace(v1.begin(), v1.end(), 20, 100);//将指定范围的指定数据全部替换为新的数据
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
}
//替换replace_if
class Less30
{
public:
	bool operator()(int v)
	{
		return v < 23;
	}
};
void test_al15(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(20);
	replace_if(v1.begin(), v1.end(), Less30(), 100);
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
}
//交换swap，替换同类型容器
void test_al16(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 10);
	}
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
	for_each(v2.begin(), v2.end(), Print_a);
	cout << endl;
	swap(v1, v2);//交换
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
	for_each(v2.begin(), v2.end(), Print_a);
	cout << endl;
}
//accumulate累加
void test_al17(void)
{
	vector<int> v;
	for (int i = 1; i <= 100; i++)
	{
		v.push_back(i);
	}
	int sum = accumulate(v.begin(), v.end(), 0);//第三个参数是额外加上该数
	cout << sum << endl;
}
//fill填充
void test_al18(void)
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.resize(10);//默认新开辟的空间填入0
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	v.resize(15, 20);//注意只有重新开辟的空间才被填入指定值
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	fill(v.begin(), v.end(), 100);//指定返回填入指定值
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//交集set_intersection
void test_al19(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	//vtar.resize(min(v1.size(), v2.size()));//交集取原集中较小的大小，使用到了min()内置算法
	vtar.resize(v1.size() > v2.size() ? v2.size() : v1.size());
	vector<int>::iterator pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());
	for_each(vtar.begin(), pos, Print_a);//注意应该使用最终返回的迭代器，不然可能打印出resize的默认值0
}
//并集set_union
void test_al20(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	vtar.resize(v1.size() + v2.size());//取原集大小之和
	vector<int>::iterator pos = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());
	for_each(vtar.begin(), pos, Print_a);//注意应该使用最终返回的迭代器，不然可能打印出resize的默认值0
	cout << endl;
}
//差集set_difference
void test_al21(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	vtar.resize(v1.size());//取被差集的大小
	vector<int>::iterator pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());
	//前者为被差集，此例被差集为v1，最终目标集vtar不可能大于v1，也可以直接指定为原集中的较大者（因为有时可能互相求差集）
	for_each(vtar.begin(), pos, Print_a);//注意应该使用最终返回的迭代器，不然可能打印出resize的默认值0
	cout << endl;
}


//int main(void)
//{
//	//test_al9();
//	//test_al10();
//	//test_al11();
//	//test_al12();
//	//test_al13();
//	//test_al14();
//	//test_al15();
//	//test_al16();
//	//test_al17();
//	//test_al18();
//	test_al19();
//	//test_al20();
//	//test_al21();
//	return 0;
//}


void test_al(void)
{

}
class Peo_a
{
public:
	Peo_a(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};