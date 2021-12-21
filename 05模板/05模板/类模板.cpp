#pragma once
using namespace std;
#include <iostream>
#include <string>
//#include "C的头文件.h"不能直接包含头文件
//普通函数会在预编译阶段将函数定义与声明链接到一起，调用时可以找到定义并调用
//而类模板方法在预编译不会进行声明与定义的链接，调用时找不到定义，调用会失败（即创建晚于调用）

//#include "C的定义.cpp"//这种方法也不好，会暴露源码

#include "类的通常实现.hpp"//将类模板与类模板的方法同时放入hpp后缀的文件（hpp是约定俗成的后缀）

#include "Array.hpp"

//类模板
//类模板无法使用自动类型推导
//类模板可以使用默认参数

//template<class NameType,class AgeType = int>//默认类型
//class Peo
//{
//public:
//	Peo(NameType name, AgeType age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	void Show()
//	{
//		cout << "name: " << m_name << "   age: " << m_age << endl;
//	}
//	NameType m_name;
//	AgeType m_age;
//};
//int main(void)
//{
//	Peo<string, int> p("jack", 21);
//	//Peo p("zhangsan", 22);无法自动类型推导
//	p.Show();
//
//	Peo<string> p1("bob", 22);//有默认类型且实际类型与其相同时可不指定类型
//	p1.Show();
//
//	return 0;
//}

//类模板的方法的创建时机，类模板的方法是调用后创建的，因此错误不能在编写时表现出来

//class Stu1
//{
//public:
//	void Show1()
//	{
//		cout << "Stu1" << endl;
//	}
//};
//class Stu2
//{
//public:
//	void Show2()
//	{
//		cout << "Stu2" << endl;
//	}
//};
//template<class T>
//class C
//{
//public:
//	T obj;
//	void func1()
//	{
//		obj.Show1();
//	}
//	void func2()
//	{
//		obj.Show2();
//	}
//};
//int main(void)
//{
//	C<Stu1> c1;
//	c1.func1();
//	//c1.func2();由于c1是Stu1类型的，因此不可以通过func2调用Show2
//	return 0;
//}

//类模板对象作为函数参数
//1指定传入类型，实际使用最多
//2单参模板化
//3总参模板化

//template<class T1,class T2>
//class Peo
//{
//public:
//	Peo(T1 name, T2 age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	void Show(void)
//	{
//		cout << m_name << "    " << m_age << endl;
//	}
//	T1 m_name;
//	T2 m_age;
//};
////指定传参类型
//void Print1(Peo<string, int>& p)
//{
//	p.Show();
//}
//void test1(void)
//{
//	Peo<string, int> p1("jack", 21);
//	Print1(p1);
//}
////单参模板化（函数模板加类模板）
//template<class T1,class T2>
//void Print2(Peo<T1, T2>& p)
//{
//	p.Show();
//	cout << typeid(T1).name() << endl;
//	cout << typeid(T2).name() << endl;
//}
//void test2(void)
//{
//	Peo<string, int> p1("bob", 20);
//	Print2(p1);
//}
////总参模板化（函数模板加类模板）
//template<class T>
//void Print3(T& p)
//{
//	p.Show();
//	cout << typeid(T).name() << endl;
//}
//void test3(void)
//{
//	Peo<string, int> p1("jane", 18);
//	Print3(p1);
//}
//int main(void)
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}

//类模板的继承
//父类为模板时子类必须指定父类参数类型才能继承
//若想灵活指定父类参数类型则子类也需变为类模板

//template<class T>
//class Base
//{
//public:
//	Base()
//	{
//		cout << "base T: " << typeid(T).name() << endl;
//
//	}
//	T bt;
//};
//class Son1 :public Base<int>//指定父类模板类型
//{
//
//};
//template<class T1,class T2>//子类变为类模板
//class Son2 :public Base<T2>
//{
//public:
//	Son2()
//	{
//		cout << "son T1: "<<typeid(T1).name() << endl;
//		cout << "son T2: " << typeid(T2).name() << endl;
//	}
//	T1 st;
//};
//int main(void)
//{
//	//Son1 s1;
//	Son2<char,int> s2;
//	return 0;
//}

//类模板方法（构造函数）的类外实现
//不仅要再次声明类参数列表还要在作用域后加上参数列表

//template<class T1,class T2>
//class Peo
//{
//public:
//	Peo(T1 name, T2 age);
//	//{
//	//	m_name = name;
//	//	m_age = age;
//	//}
//	void Show();
//	//{
//	//	cout << m_name << "   " << m_age << endl;
//	//}
//	T1 m_name;
//	T2 m_age;
//};
////构造函数的类外实现
//template<class T1,class T2>
//Peo<T1,T2>::Peo(T1 name, T2 age)
//{
//	m_name = name;
//	m_age = age;
//}
////方法的类外实现
//template<class T1, class T2>
//void Peo<T1, T2>::Show()
//{
//	cout << m_name << "   " << m_age << endl;
//}
//int main(void)
//{
//	Peo<string, int> p1("tom", 35);
//	p1.Show();
//	return 0;
//}

//类模板的分文件编写

////template<class T1,class T2>
////class C
////{
////public:
////	C(T1 name, T2 age);
////	void Show();
////	T1 m_name;
////	T2 m_age;
////};
////template<class T1, class T2>
////C<T1, T2>:: C(T1 name, T2 age)
////{
////	m_name = name;
////	m_age = age;
////}
////template<class T1, class T2>
////void C<T1, T2>:: Show()
////{
////	cout << m_name << "    " << m_age << endl;
////}
//int main(void)
//{
//	C<string, int> c1("max",21);
//	c1.Show();
//	return 0;
//}

//类模板与友元函数（类外定义的友元函数十分复杂，尽量在类内定义）

//template<class T1,class T2>
//class Peo;//事先声明类模板
//template<class T1, class T2>//类外定义的友元全局函数
//void wShow(Peo<T1, T2> p)
//{
//	cout << p.m_name << "   " << p.m_age << endl;
//}
//
//template<class T1,class T2>
//class Peo
//{
//	friend void Show(Peo<T1, T2> p)//friend不可省略，这是友元函数的类内定义（不需要在public下）
//	{
//		cout << p.m_name << "   " << p.m_age << endl;
//	}
//	friend void wShow<>(Peo<T1, T2> p);//声明必须加空列表
//public:
//	Peo(T1 name, T2 age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	void Show()//类方法（类外调用则必须在public下)
//	{
//		cout << m_name << "   " << m_age << endl;
//	}
//private:
//	T1 m_name;
//	T2 m_age;
//};
//int main(void)
//{
//	Peo<string, int> p1("zhangsan", 21);
//	Show(p1);//类内定义的友元全局函数
//	wShow(p1);//类外定义的友元全局函数
//	p1.Show();//类方法
//	return 0;
//}




//实现一个通用的数组类
//可以存储内置数据类型和自定义数据类型
//数据存储到堆区
//构造函数可传入数组容量
//提供对应的拷贝构造函数及operator=
//提供尾插法和尾删法进行增删
//可通过下标访问数组元素
//可获得当前数组的元素个数与容量

//class Peo
//{
//public:
//	Peo() {};
//	Peo(string name, int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	string m_name;
//	int m_age;
//};
//void Print1(Array<int>& arr)
//{
//	for (int i = 0; i < arr.GetSize(); i++)//大小
//	{
//		cout << arr[i] << " ";//下标访问
//	}
//	cout << endl;
//}
//void Print2(Array<Peo>& arr)
//{
//	for (int i = 0; i < arr.GetSize(); i++)//大小
//	{
//		cout << arr[i].m_name << "  " << arr[i].m_age << endl;//下标访问
//	}
//}
//int main(void)
//{
//	//Array<int> arr1(5);
//	////Array<int> arr2(arr1);
//	////Array<int> arr3(100);
//	////arr3 = arr2;
//	//for (int i = 0; i < arr1.GetCapacity(); i++)//容量
//	//{
//	//	arr1.Push(i);//插入
//	//}
//	//arr1.Pop();//删除
//	//arr1.Pop();
//	//arr1.Push(-1);//删除
//	//Print1(arr1);
//
//
//	Array<Peo> arr2(5);
//	Peo p1("zhangsan", 21);
//	Peo p2("lisi", 20);
//	Peo p3("wangwu", 25);
//	arr2.Push(p1);
//	arr2.Push(p2);
//	arr2.Push(p3);
//	arr2.Pop();
//	Print2(arr2);
//
//	return 0;
//}