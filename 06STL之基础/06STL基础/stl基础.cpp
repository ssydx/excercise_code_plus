#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//STL(standard template library)��׼ģ���
//������󣨷�װ�̳ж�̬���ͷ��ͱ����Ϊ����ߴ���ĸ�����
//STL�����������㷨�͵�����
//�������㷨ͨ������������
//STLͨ��ģ�庯������ģ��ʵ��
//STLϸ��Ϊ���� �㷨 ������ �º��� ��������������� �ռ�������
//�������ڴ�����ݣ�vector string deque stack queue list set map�ȣ�
//�㷨�����ܶೣ���㷨
//�������������ͺ����Ľ��ϼ�
//�º�������Ϊ�㷨��ĳ�ֲ���
//��������ռ���������������

//������Ϊ����ʽ������ǿ��ֵ������Ԫ�ؾ��й̶�λ�ã�������ʽ������Ԫ��û���ϸ������˳��
//�㷨��Ϊ�ʱ��㷨���ı�Ԫ�ص����ݣ��翽��ɾ���滻���򣩣����ʱ��㷨�����ı�Ԫ�����ݣ�����ұ���������
//��������ÿ������������ר�����������㷨ͨ�����������ܷ������������ݣ����롢�������ǰ��˫�������


//vector��for_each
//void Print(int val)
//{
//	cout << val << endl;
//}
//void test1(void)
//{
//	//��������
//	vector<int> v;
//	//��������
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	//ͨ�����������������е�����
//	vector<int>::iterator itbegin = v.begin();//ָ����Ԫ��
//	vector<int>::iterator itend = v.end();//ָ�����һ��Ԫ����һ��λ��
//	//��һ��
//	//while (itbegin != itend)
//	//{
//	//	cout << *itbegin << endl;
//	//	itbegin++;
//	//}
//	//�ڶ���
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;//it������ָ��
//		itbegin++;
//	}
//	//������
//	//for_each(v.begin(),v.end(),Print);//�ص�������Ҫ�Զ���һ����ӡ��Ӧ�������͵ĺ���
//}
////�Զ�����������
//class Peo
//{
//public:
//	Peo(string name, int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	string m_name;
//	int m_age;
//};
////��
//void test2(void)
//{
//	vector<Peo> v;
//	Peo p1("aaa", 22);
//	Peo p2("bbb", 23);
//	Peo p3("ccc", 24);
//	Peo p4("ddd", 25);
//	Peo p5("eee", 26);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	for (vector<Peo>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << it->m_name << "   " << it->m_age << endl;
//	}
//
//}
////ָ��
//void test3(void)
//{
//	vector<Peo*> v;
//	Peo p1("aaa", 22);
//	Peo p2("bbb", 23);
//	Peo p3("ccc", 24);
//	Peo p4("ddd", 25);
//	Peo p5("eee", 26);
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//	for (vector<Peo*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << (*it)->m_name << "   " << (*it)->m_age << endl;
//	}
//
//}
////����Ƕ������
//void test4(void)
//{
//	vector<vector<int>> v;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//	vector<int> v5;
//	for (int i = 0; i < 5; i++)
//	{
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//		v5.push_back(i + 5);
//	}
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//	v.push_back(v5);
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
//		{
//			cout << *vit << " ";
//		}
//		cout << endl;
//	}
//}
//int main(void)
//{
//	//test1();
//	//test2();
//	//test3();
//	test4();
//	return 0;
//}