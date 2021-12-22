#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//�º�����������һ��ʹ�ã����������е�����()�������������

//�ӷ��º���
class Add_f
{
public:
	int operator()(int v1, int v2)//�����в��������з���ֵ
	{
		return v1 + v2;
	}
};
//��ӡ�º���
void test_f1(void)
{
	Add_f myadd;
	int ret = myadd(10, 20);//������add.operator()(10,20)
	cout << ret << endl;
}
class Print_f
{
public:
	Print_f()
	{
		m_count = 0;
	}
	void operator()(const string& text)
	{
		cout << text << endl;
		m_count++;
	}
	int m_count;//�����������Լ�¼�ڲ�״̬
};
void test_f2(void)
{
	Print_f myprint;
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	cout << myprint.m_count << endl;
}
//�ص�����
void DoPrint(Print_f& p, string text)//�����������Ϊ��������
{
	p(text);
}
void test_f3(void)
{
	Print_f myprint;
	DoPrint(myprint, "hello world");
}
//ν�ʣ�����ֵΪbool�ķº���
//һԪν�ʣ��º���һ������
class Greater5
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};
void test_f4(void)
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	Greater5 mygreater5;
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), mygreater5);
	if (it == v1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}
//��Ԫν�ʣ��º�����������
class Comp_f
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test_f5(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(50);
	Comp_f mycomp;
	//sort(v1.begin(), v1.end(), Comp_f());//Ĭ�������Զ�������ע������ʱ�������()
	sort(v1.begin(), v1.end(), mycomp);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//�ڽ��º���ģ��
//����,negate plus minus divides modulus multiplies
void test_f6(void)
{
	//ȡ����һԪν��
	negate<int> n1;
	cout << n1(50) << endl;
	//�ӷ�����Ԫν��
	plus<int> p1;
	cout << p1(20, 10) << endl;
}
//��ϵ,equal_to not_equal_to greater greater_equal less less_equal
void test_f7(void)
{
	//����
	greater<int> g1;
	cout << g1(20, 10) << endl;//ǰ�ߴ��ں��߷���1
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(4);
	v1.push_back(2);
	sort(v1.begin(), v1.end(), g1);
	for (int i = 0; i < 5; i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}
//�߼�,logical_and logical_or logical_not
void test_f8(void)
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(0);
	v1.push_back(1);
	for (int i = 0; i < 4; i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	vector<int> v2;
	v2.resize(v1.size());//ע�����ǰ�����ȿ����㹻��Ŀռ�
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());//���˵�ͬʱ��ÿ��Ԫ�ؽ����߼���
	for (int i = 0; i < 4; i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
}

//int main(void)
//{
//	//test_f1();
//	//test_f2();
//	//test_f3();
//	//test_f4();
//	//test_f5();
//	//test_f6();
//	//test_f7();
//	test_f8();
//	return 0;
//}