#pragma once
using namespace std;
#include <iostream>
#include <string>

//���ͱ��

//����ģ�壬��ָ�������β����ͺͷ���ֵ���ͣ��������������
//�Զ������Ƶ������Ƶ���һ�µ�����
//ģ�����ȷ����������������Ͳ���ʹ��

////void Swap(int& a, int& b)//�������������ܽ�������
////{
////	int tmp = a;
////	a = b;
////	b = tmp;
////}
//template<typename T>//����һ��ģ��
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
//	//Swap(a, b);//�Զ������Ƶ�
//	Swap<int>(a, b);//��ʽָ������
//	cout << "a = " << a << " b = " << b << endl;
//	double c = 1.1;
//	double d = 2.2;
//	Swap(c, d);
//	cout << "c = " << c << " d = " << d << endl;
//	char e = 'w';
//	//Swap(c, e);���Ͳ�һ��
//	//func();�޷��Ƶ�
//	func<int>();//��Ȼ����û��ʹ���������Ҳ����ָ��������ָ�����ɣ�
//
//	return 0;
//}


//��������(�±�汾)

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
//		int max = i;//�ӵ�һ��Ԫ�ؿ�ʼ����һ��ʹ��Ԫ�ر�Ϊ���ֵ���Դ�����
//		bool flag = true;
//		for (int j = i + 1; j < sz; j++)
//		{
//			if (arr[max] < arr[j])//��¼���ֵ���±�
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
//			Swap(arr[i], arr[max]);//ʹ��Ԫ�ر�Ϊ���ֵ���Դ�����
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

//��ͨ�����뺯��ģ�������
//��ͨ�������Է�����ʽ����ת��
//�Զ������Ƶ����ܷ�����ʽ����ת������ʽָ������ʱ����

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
//	cout << Add(a, c) << endl;//������ʽ����ת��
//
//	cout << tAdd(a, b) << endl;
//	cout << tAdd<int>(a, b) << endl;
//
//	//cout << tAdd(a, c) << endl;//�޷��Ƶ���һ�����ͣ��޷�������ʽ����ת��
//	cout << tAdd<int>(a, c) << endl;
//
//	return 0;
//}

//��ͨ�����ͺ���ģ��ĵ�������
//���ͬʱ����ʹ�����ߣ�����ʹ����ͨ����(��ʹ��ͨ����ֻ��������û�ж���)
//����ǿ��ʹ�ú���ģ��(ʹ�ÿ�ģ������б�)
//����ģ����Է�������
//������ģ����Բ������õ�Ч�����ȵ��ú���ģ��

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
////����ģ�������
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
//	cout << Add(a, b) << endl;//������ͨ����
//	cout << Add<>(a, b) << endl;//���ú���ģ��
//	cout << Add(a, b, 100) << endl;//�������صĺ���ģ��
//
//	char c1 = 'A';
//	char c2 = 'B';
//	cout << (int)Add(c1, c2) << endl;//���ú���ģ�壨��Ȼ��ͨ�������Խ�����ʽ����ת����
//
//	return 0;
//}

//ģ��ľ�����
//ģ�岻�������Զ����������ͣ���ʱ��ͨ�����ؽ���ģ����廯

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
////���廯
//template<> bool Cmp(const Stu& s1,const Stu& s2)//ע����廯�ĸ�ʽ
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