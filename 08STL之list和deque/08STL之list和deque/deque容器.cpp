#pragma once
using namespace std;
#include <iostream>
#include <deque>
#include <algorithm>

//˫������
//vector ����ͷ���Ĳ���ɾ��Ч�ʽϵ�
//deque ���ʽ����������п������м�¼��

void PrintDeque(const deque<int>& d)//��const
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//������ҲҪ��Ϊconst��
	{
		//*it = 100;�����޸�
		cout << *it << " ";
	}
	cout << endl;
}
//��ʼ��
void test21(void)
{
	deque<int> d1;//Ĭ�Ϲ���
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	PrintDeque(d1);

	deque<int> d2(d1.begin(), d1.end());//���䷽ʽ
	PrintDeque(d2);

	deque<int> d3(10, 100);//n��elem
	PrintDeque(d3);

	deque<int> d4(d3);//��������
	PrintDeque(d4);
}
//��ֵ
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
//��С��û�������ĸ��
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
	//ͬ��
	d1.resize(5);
	PrintDeque(d1);
	d1.resize(10);
	PrintDeque(d1);
}
//��ɾ
void test24(void)
{
	deque<int> d1;
	//����
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	PrintDeque(d1);
	//ɾ��
	d1.pop_back();
	PrintDeque(d1);
	d1.pop_front();
	PrintDeque(d1);
	//�������
	d1.insert(d1.begin(), 1000);//ָ��λ�ò���ָ��ֵ
	PrintDeque(d1);
	d1.insert(d1.begin(), 2, 2000);//ָ��λ�ò���ָ��������ָ��ֵ
	PrintDeque(d1);
	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());//ָ��λ�ò�����һ����ָ�������ֵ
	PrintDeque(d1);
	//���ɾ��
	d1.erase(++d1.begin());
	PrintDeque(d1);
	d1.erase(d1.begin(), d1.end());//�ȼ���d1.clear()
	PrintDeque(d1);
}
//����Ԫ�صķ���
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
	//��β
	cout << d1.front() << endl;
	cout << d1.back() << endl;
}
//����
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
	sort(d1.begin(), d1.end());//Ĭ������
	//֧��������ʵ���������������ʹ��sort�㷨������deque��vector
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