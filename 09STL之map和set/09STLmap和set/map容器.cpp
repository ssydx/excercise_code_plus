#pragma once
using namespace std;
#include <iostream>
#include <map>
#include <string>

//map������Ԫ�ض���pair
//��һ����key���ڶ�����value
//����key��������
void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}
	cout << endl;
}
//��ʼ���͸�ֵ
void test51(void)
{
	//��ʼ��
	map<int, int> m1;//Ĭ�Ϲ���
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	m1.insert(pair<int, int>(3, 50));//�ظ��򲻲���
	PrintMap(m1);
	map<int, int> m2(m1);//��������
	PrintMap(m2);
	//��ֵ
	map<int, int> m3;
	m3 = m2;
	PrintMap(m3);
}
//��С�ͽ���
void test52(void)
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	PrintMap(m1);
	if (m1.empty())//�п�
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << m1.size() << endl;//��С
	}
	//����
	map<int, int> m2;
	m2.insert(pair<int, int>(5, 100));
	m2.insert(pair<int, int>(2, 600));
	PrintMap(m1);
	PrintMap(m2);
	m1.swap(m2);
	PrintMap(m1);
	PrintMap(m2);
}
//��ɾ
void test53(void)
{
	//����
	map<int, int> m1;
	//��һ��
	m1.insert(pair<int, int>(1, 10));
	//�ڶ��֣��Ƽ�
	m1.insert(make_pair(2, 20));
	//�����֣������Ƽ�
	m1.insert(map<int, int>::value_type(3, 30));
	//�����֣�������������루�ᵼ�²����ڵ�key������map����ͨ��������з���
	m1[4] = 40;
	//cout << m1[5] << endl;
	PrintMap(m1);
	//ɾ��
	m1.erase(m1.begin());//��������ɾ��
	PrintMap(m1);
	m1.erase(4);//��key����ɾ��
	//m1.erase(30);���ܰ�value����ɾ��
	PrintMap(m1);
	m1.clear();//ע��ȼ۵�������ʽ
	PrintMap(m1);
}
//���Һ�ͳ�ƣ���set��ͬ
void test54(void)
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	m1.insert(pair<int, int>(3, 50));//�ظ��򲻲���
	//���ң�ͬ�����ص�����
	map<int, int>::iterator pos = m1.find(3);
	if (pos == m1.end())
	{
		cout << "fail" << endl;
	}
	else
	{
		cout << pos->second << endl;
	}
	//ͳ��
	int count = m1.count(3);
	cout << count << endl;//���1
	count = m1.count(5);
	cout << count << endl;//���0
	//multimap���ٲ���
}
//����
class Comp11
{
public:
	bool operator()(int v1, int v2) const//���������÷�ʽ���ݣ�
	{
		return v1 > v2;
	}
};
void test55(void)
{
	map<int, int, Comp11> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 50));
	m1.insert(pair<int, int>(3, 50));
	for (map<int, int, Comp11>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}
	cout << endl;
}
//�Զ����������͵��Զ�������
class Peo
{
public:
	Peo(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
class Comp12
{
public:
	bool operator()(Peo p1, Peo p2) const//���������÷�ʽ���ݣ�
	{
		return p1.m_age > p2.m_age;
	}
};
void test56(void)
{
	map<Peo, int, Comp12> m1;
	Peo p1("����", 35);
	Peo p2("�ܲ�", 45);
	Peo p3("��Ȩ", 40);
	Peo p4("����", 25);
	Peo p5("�ŷ�", 36);
	Peo p6("����", 35);
	m1.insert(make_pair(p1, 170));
	m1.insert(make_pair(p2, 175));
	m1.insert(make_pair(p3, 160));
	m1.insert(make_pair(p4, 185));
	m1.insert(make_pair(p5, 190));
	m1.insert(make_pair(p6, 180));
	for (map<Peo, int, Comp12>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << it->first.m_name << "  " << it->first.m_age << "  " << it->second << endl;
	}
}

//int main(void)
//{
//	//test51();
//	//test52();
//	//test53();
//	//test54();
//	//test55();
//	test56();
//	return 0;
//}