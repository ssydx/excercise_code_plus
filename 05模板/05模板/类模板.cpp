#pragma once
using namespace std;
#include <iostream>
#include <string>
//#include "C��ͷ�ļ�.h"����ֱ�Ӱ���ͷ�ļ�
//��ͨ��������Ԥ����׶ν������������������ӵ�һ�𣬵���ʱ�����ҵ����岢����
//����ģ�巽����Ԥ���벻����������붨������ӣ�����ʱ�Ҳ������壬���û�ʧ�ܣ����������ڵ��ã�

//#include "C�Ķ���.cpp"//���ַ���Ҳ���ã��ᱩ¶Դ��

#include "���ͨ��ʵ��.hpp"//����ģ������ģ��ķ���ͬʱ����hpp��׺���ļ���hpp��Լ���׳ɵĺ�׺��

#include "Array.hpp"

//��ģ��
//��ģ���޷�ʹ���Զ������Ƶ�
//��ģ�����ʹ��Ĭ�ϲ���

//template<class NameType,class AgeType = int>//Ĭ������
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
//	//Peo p("zhangsan", 22);�޷��Զ������Ƶ�
//	p.Show();
//
//	Peo<string> p1("bob", 22);//��Ĭ��������ʵ������������ͬʱ�ɲ�ָ������
//	p1.Show();
//
//	return 0;
//}

//��ģ��ķ����Ĵ���ʱ������ģ��ķ����ǵ��ú󴴽��ģ���˴������ڱ�дʱ���ֳ���

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
//	//c1.func2();����c1��Stu1���͵ģ���˲�����ͨ��func2����Show2
//	return 0;
//}

//��ģ�������Ϊ��������
//1ָ���������ͣ�ʵ��ʹ�����
//2����ģ�廯
//3�ܲ�ģ�廯

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
////ָ����������
//void Print1(Peo<string, int>& p)
//{
//	p.Show();
//}
//void test1(void)
//{
//	Peo<string, int> p1("jack", 21);
//	Print1(p1);
//}
////����ģ�廯������ģ�����ģ�壩
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
////�ܲ�ģ�廯������ģ�����ģ�壩
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

//��ģ��ļ̳�
//����Ϊģ��ʱ�������ָ������������Ͳ��ܼ̳�
//�������ָ�������������������Ҳ���Ϊ��ģ��

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
//class Son1 :public Base<int>//ָ������ģ������
//{
//
//};
//template<class T1,class T2>//�����Ϊ��ģ��
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

//��ģ�巽�������캯����������ʵ��
//����Ҫ�ٴ�����������б�Ҫ�����������ϲ����б�

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
////���캯��������ʵ��
//template<class T1,class T2>
//Peo<T1,T2>::Peo(T1 name, T2 age)
//{
//	m_name = name;
//	m_age = age;
//}
////����������ʵ��
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

//��ģ��ķ��ļ���д

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

//��ģ������Ԫ���������ⶨ�����Ԫ����ʮ�ָ��ӣ����������ڶ��壩

//template<class T1,class T2>
//class Peo;//����������ģ��
//template<class T1, class T2>//���ⶨ�����Ԫȫ�ֺ���
//void wShow(Peo<T1, T2> p)
//{
//	cout << p.m_name << "   " << p.m_age << endl;
//}
//
//template<class T1,class T2>
//class Peo
//{
//	friend void Show(Peo<T1, T2> p)//friend����ʡ�ԣ�������Ԫ���������ڶ��壨����Ҫ��public�£�
//	{
//		cout << p.m_name << "   " << p.m_age << endl;
//	}
//	friend void wShow<>(Peo<T1, T2> p);//��������ӿ��б�
//public:
//	Peo(T1 name, T2 age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	void Show()//�෽������������������public��)
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
//	Show(p1);//���ڶ������Ԫȫ�ֺ���
//	wShow(p1);//���ⶨ�����Ԫȫ�ֺ���
//	p1.Show();//�෽��
//	return 0;
//}




//ʵ��һ��ͨ�õ�������
//���Դ洢�����������ͺ��Զ�����������
//���ݴ洢������
//���캯���ɴ�����������
//�ṩ��Ӧ�Ŀ������캯����operator=
//�ṩβ�巨��βɾ��������ɾ
//��ͨ���±��������Ԫ��
//�ɻ�õ�ǰ�����Ԫ�ظ���������

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
//	for (int i = 0; i < arr.GetSize(); i++)//��С
//	{
//		cout << arr[i] << " ";//�±����
//	}
//	cout << endl;
//}
//void Print2(Array<Peo>& arr)
//{
//	for (int i = 0; i < arr.GetSize(); i++)//��С
//	{
//		cout << arr[i].m_name << "  " << arr[i].m_age << endl;//�±����
//	}
//}
//int main(void)
//{
//	//Array<int> arr1(5);
//	////Array<int> arr2(arr1);
//	////Array<int> arr3(100);
//	////arr3 = arr2;
//	//for (int i = 0; i < arr1.GetCapacity(); i++)//����
//	//{
//	//	arr1.Push(i);//����
//	//}
//	//arr1.Pop();//ɾ��
//	//arr1.Pop();
//	//arr1.Push(-1);//ɾ��
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