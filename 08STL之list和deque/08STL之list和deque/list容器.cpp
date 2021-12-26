#pragma once
using namespace std;
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

//����STL����˫��ѭ������
//��������λ�ÿ�����ɾ
//�����ٶ��������������ȡ
//��̬�����ڴ治������ڴ��˷Ѻ����
//ռ�ÿռ�ϴ�
//˫����������������������
//ע�⣬�����ڱ�ͷ������ɾ�����򲻻�Ӱ���������vectorÿ���ڴ治�㶼������λ�ÿ����ڴ棬������Ҳ���ı䣩

void PrintList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//��ʼ��
void test31(void)
{
	list<int> l1;//Ĭ�Ϲ���
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);

	list<int>l2(l1.begin(), l1.end());//���䷽ʽ
	PrintList(l2);

	list<int> l3(10, 5);//n��elem
	PrintList(l3);

	list<int> l4(l3);//��������
	PrintList(l4);
}
//��ֵ
void test32(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);
	//=
	list<int> l2 = l1;
	PrintList(l2);
	//assign
	list<int> l3;
	l3.assign(10, 5);
	PrintList(l3);
	list<int> l4;
	l4.assign(l3.begin(), l3.end());
	PrintList(l4);
}
//����
void test33(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	list<int> l2;
	l2.assign(10, 5);
	PrintList(l1);
	PrintList(l2);
	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);
}
//��С
void test34(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);
	cout << l1.size() << endl;
	l1.resize(5);
	PrintList(l1);
	l1.resize(10);
	PrintList(l1);
	if (l1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << l1.size() << endl;
	}
}
//��ɾ
void test35(void)
{
	list<int> l1;
	l1.push_back(10);//β��
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	l1.push_front(100);//ͷ��
	l1.push_front(200);
	l1.push_front(300);
	l1.push_front(400);
	l1.push_front(500);
	PrintList(l1);
	l1.pop_back();//βɾ
	PrintList(l1);
	l1.pop_front();//ͷɾ
	PrintList(l1);
	//ע��list�ĵ�����ֻ��ʹ��++��--����ƫ��
	l1.insert(++l1.begin(), 1000);
	PrintList(l1);
	l1.erase(----l1.end());
	PrintList(l1);
	//ɾ��ָ��Ԫ�أ��ظ���ȫ��ɾ����
	l1.insert(++l1.begin(), 1000);
	PrintList(l1);
	l1.remove(1000);
	PrintList(l1);
	l1.clear();//�ȼ���l1.erase(l1.begin(), l1.end())
	PrintList(l1);
}
//����Ԫ�ط��ʣ�û��[]��at��ֻ��ֱ�ӷ�����Ԫ�غ�βԪ�أ�
void test36(void)
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	cout << l1.front() << endl;
	cout << l1.back() << endl;
	//cout << *(l1.begin() + 1) << endl;������
}
//��ת������
bool smaller(int v1, int v2)
{
	return v1 > v2;//���򣬿ɼ���ָ���Ҳ��С
}
void test37(void)
{
	//��ת
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);
	l1.reverse();
	PrintList(l1);
	//����
	list<int> l2;
	l2.push_back(10);
	l2.push_back(40);
	l2.push_back(30);
	l2.push_back(20);
	l2.push_back(50);
	PrintList(l2);
	//sort(l2.begin(),l2.end());
	//��֧��������ʵĵ�����������ʹ�ñ�׼�㷨
	//���ֵ��������ṩ�ڲ��㷨��������
	l2.sort();//Ĭ������
	PrintList(l2);
	l2.sort(smaller);//���򣨻ص�������
	PrintList(l2);
}

//int main(void)
//{
//	//test31();
//	//test32();
//	//test33();
//	//test34();
//	//test35();
//	//test36();
//	test37();
//	return 0;
//}