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
//��ʼ��
void test11(void)
{
	vector<int> v1;//Ĭ�Ϲ���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	PrintVector(v1);

	vector<int> v2(v1.begin(), v1.end());//���䷽ʽ
	PrintVector(v2);

	vector<int> v3(10, 5);//n��elem
	PrintVector(v3);

	vector<int> v4(v3);//��������
	PrintVector(v4);
}
//��ֵ
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
	v3.assign(v1.begin(), v1.end());//���ұ�
	PrintVector(v3);
	vector<int> v4;
	v4.assign(10, 5);
	PrintVector(v4);
}
//�����ʹ�С
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
		cout << v1.capacity() << endl;//���13���Զ���չ��ֵ���̶�
		cout << v1.size() << endl;//���10
	}
	v1.resize(5);//����
	PrintVector(v1);
	v1.resize(10);//������Ĭ����0���
	PrintVector(v1);
	v1.resize(15, 3);//��ָ������ʱ�����ֵ
	PrintVector(v1);
}
//��ɾ
void test14(void)
{
	//β��
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	PrintVector(v1);
	//βɾ
	v1.pop_back();
	PrintVector(v1);
	//���õ������������
	v1.insert(v1.begin(), 100);//ָ��λ�ò���ָ��ֵ
	PrintVector(v1);
	v1.insert(v1.begin() + 1, 2, 1000);//ָ��λ�ò���ָ��������ָ��ֵ
	PrintVector(v1);
	//���õ��������ɾ��
	v1.erase(v1.begin());
	PrintVector(v1);
	v1.erase(v1.begin(), v1.end());//�ȼ���v1.clear()
	PrintVector(v1);
}
//�������ݵķ���
void test15(void)
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	//����
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
//��������
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
	v1.swap(v2);//����
	PrintVector(v1);
	PrintVector(v2);

	//ʵ����;
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << v.capacity() << endl;//����100000
	cout << v.size() << endl;//100000
	v.resize(3);
	cout << v.capacity() << endl;//����100000
	cout << v.size() << endl;//3������ڴ��˷�
	vector<int>(v).swap(v);//�����ڴ�	
	//vector<int>(v)�Ǵ���һ�����������������ÿ������츴������v��Ԫ�ص�������������������Ĵ�С��������ͬ������ΪԪ�ظ�����
	//.swap(v)�򽻻���������������v���Ӷ�ʹv�ڴ�����
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}
//Ԥ���ڴ�
void test17(void)
{
	//����֪����Ԫ�ظ���������ʱ����Ԥ���ڴ棬��������ڴ�λ����ɵĿ���
	vector<int> v;
	//Ԥ���ڴ�
	v.reserve(100000);
	int count = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//��������ڴ�λ�õĴ���
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