#pragma once
using namespace std;
#include <iostream>
#include <string>

//泛型编程

//函数模板，不指定具体形参类型和返回值类型，用虚拟类型替代
//自动类型推导必须推导出一致的类型
//模板必须确定出虚拟的数据类型才能使用

////void Swap(int& a, int& b)//交换变量，仅能交换整型
////{
////	int tmp = a;
////	a = b;
////	b = tmp;
////}
//template<typename T>//声明一个模板
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//template<typename T>
//void func()
//{
//	cout << "func" << endl;
//}
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//	//Swap(a, b);//自动类型推导
//	Swap<int>(a, b);//显式指定类型
//	cout << "a = " << a << " b = " << b << endl;
//	double c = 1.1;
//	double d = 2.2;
//	Swap(c, d);
//	cout << "c = " << c << " d = " << d << endl;
//	char e = 'w';
//	//Swap(c, e);类型不一致
//	//func();无法推导
//	func<int>();//虽然函数没有使用虚拟参数也必须指定（随意指定即可）
//
//	return 0;
//}


//数组排序(下标版本)

//template<class T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//template<typename T>
//void Sort(T arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int max = i;//从第一个元素开始，第一轮使首元素变为最大值，以此类推
//		bool flag = true;
//		for (int j = i + 1; j < sz; j++)
//		{
//			if (arr[max] < arr[j])//记录最大值的下标
//			{
//				max = j;
//				flag = false;
//			}
//		}
//		if (flag)
//		{
//			break;
//		}
//		if (max != i)
//		{
//			Swap(arr[i], arr[max]);//使首元素变为最大值，以此类推
//		}
//	}
//}
//template<class T>
//void Print(T arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//int main(void)
//{
//	char carr[] = "dfecba";
//	int size = sizeof(carr) / sizeof(carr[0]);
//	Sort(carr, size);
//	Print(carr, size);
//
//	int iarr[] = { 1,2,3,5,3,6,9,7 };
//	int size1 = sizeof(iarr) / sizeof(iarr[0]);
//	Sort(iarr, size1);
//	Print(iarr, size1);
//
//	return 0;
//}

//普通函数与函数模板的区别
//普通函数可以发生隐式类型转换
//自动类型推导不能发生隐式类型转换，显式指定类型时可以

//int Add(int a, int b)
//{
//	return a + b;
//}
//template<class T>
//T tAdd(T a, T b)
//{
//	return a + b;
//}
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';
//	cout << Add(a, b) << endl;
//	cout << Add(a, c) << endl;//产生隐式类型转换
//
//	cout << tAdd(a, b) << endl;
//	cout << tAdd<int>(a, b) << endl;
//
//	//cout << tAdd(a, c) << endl;//无法推导出一致类型，无法产生隐式类型转换
//	cout << tAdd<int>(a, c) << endl;
//
//	return 0;
//}

//普通函数和函数模板的调用区别
//如果同时可以使用两者，优先使用普通函数(即使普通函数只有声明而没有定义)
//可以强制使用函数模板(使用空模板参数列表)
//函数模板可以发生重载
//若函数模板可以产生更好的效果则先调用函数模板

//int Add(int a, int b)
//{
//	cout << "normal func" << endl;
//	return a + b;
//}
//template<class T>
//T Add(T a, T b)
//{
//	cout << "template func" << endl;
//	return a + b;
//}
////函数模板的重载
//template<class T>
//T Add(T a, T b, T c)
//{
//	cout << "template refunc" << endl;
//	return a + b + c;
//}
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//	cout << Add(a, b) << endl;//调用普通函数
//	cout << Add<>(a, b) << endl;//调用函数模板
//	cout << Add(a, b, 100) << endl;//调用重载的函数模板
//
//	char c1 = 'A';
//	char c2 = 'B';
//	cout << (int)Add(c1, c2) << endl;//调用函数模板（虽然普通函数可以进行隐式类型转换）
//
//	return 0;
//}

//模板的局限性
//模板不能满足自定义数据类型，此时可通过重载进行模板具体化

//class Stu
//{
//public:
//	Stu(string name,int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//
//	string m_name;
//	int m_age;
//};
//template<class T>
//bool Cmp(const T& a,const T& b)
//{
//	if (a == b)
//	{
//		return true;
//	}
//	return false;
//}
////具体化
//template<> bool Cmp(const Stu& s1,const Stu& s2)//注意具体化的格式
//{
//	if ((s1.m_age == s2.m_age) && (s1.m_name == s2.m_name))
//	{
//		return true;
//	}
//	return false;
//}
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//	if (Cmp(a, b))
//	{
//		cout << "equal" << endl;
//	}
//	else
//	{
//		cout << "unequal" << endl;
//	}
//
//	Stu s("zhangsan", 21);
//	Stu s1("zhangsan", 21);
//	if (Cmp(s, s1))
//	{
//		cout << "equal" << endl;
//	}
//	else
//	{
//		cout << "unequal" << endl;
//	}
//
//	return 0;
//}