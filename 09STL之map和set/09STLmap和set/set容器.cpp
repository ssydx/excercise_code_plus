#pragma once
using namespace std;
#include <iostream>
#include <set>
#include <string>

//ֻ��insert,����resize

void PrintSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//��ʼ���͸�ֵ
void test41(void)
{
	set<int> s1;//Ĭ�Ϲ���
	//û��push_back/front
	//����ʽ�������Զ�������������
	//����������ظ����ݣ�������Ҳ�����룩
	s1.insert(50);
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(40);
	PrintSet(s1);
	set<int> s2(s1);//��������
	PrintSet(s2);
	set<int> s3 = s2;
	PrintSet(s3);//��ֵ
}
//��С�ͽ���
void test42(void)
{
	set<int> s1;
	s1.insert(50);
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(40);
	PrintSet(s1);
	//�п�
	if (s1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << s1.size() << endl;//�����С����֧��resize
	}
	//����
	set<int> s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);
	s2.insert(500);
	PrintSet(s1);
	PrintSet(s2);
	s1.swap(s2);
	PrintSet(s1);
	PrintSet(s2);
}
//��ɾ
void test43(void)
{
	set<int> s1;
	s1.insert(500);//����
	s1.insert(200);
	s1.insert(300);
	s1.insert(400);
	s1.insert(100);
	PrintSet(s1);
	s1.erase(s1.begin());//ɾ����ע��ɾ������100
	PrintSet(s1);
	s1.erase(300);//ɾ��ָ��Ԫ��
	PrintSet(s1);
	s1.clear();//�ȼ���	s1.erase(s1.begin(), s1.end())
	PrintSet(s1);
}
//���Һ�ͳ��
void test44(void)
{
	set<int> s1;
	s1.insert(500);
	s1.insert(200);
	s1.insert(300);
	s1.insert(400);
	s1.insert(100);
	s1.insert(100);
	PrintSet(s1);
	//���ң����ص����������Ҳ�������s1.end()��
	set<int> ::iterator pos = s1.find(900);
	if (pos == s1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *pos << endl;
	}
	//ͳ�ƣ�����setֻ��0��1������multiset��ͬ
	int count = s1.count(100);
	cout << count << endl;//���1
	count = s1.count(900);
	cout << count << endl;//���0
	multiset<int> ms1;
	ms1.insert(10);//���ظ����԰���������
	ms1.insert(20);
	ms1.insert(20);
	ms1.insert(20);
	ms1.insert(10);
	for (multiset<int>::iterator mit = ms1.begin(); mit != ms1.end(); mit++)
	{
		cout << *mit << " ";
	}
	cout << endl;
	int mcount = ms1.count(10);
	cout << mcount << endl;//���2
	mcount = ms1.count(5);
	cout << mcount << endl;
}
//set��multiset
void test45(void)
{
	//set
	set<int> s1;
	s1.insert(100);//����ֵ��pair<������,bool>��ʹ��ʱ���ñ���.second
	pair<set<int>::iterator, bool> ret = s1.insert(200);
	if (ret.second)
	{
		cout << "success 1" << endl;//�ɹ�
	}
	else
	{
		cout << "fail 1" << endl;
	}
	ret = s1.insert(200);
	if (ret.second)
	{
		cout << "success 1" << endl;
	}
	else
	{
		cout << "fail 1" << endl;//ʧ��
	}
	//multiset
	multiset<int> ms1;
	ms1.insert(10);//���ظ����԰���������
	ms1.insert(20);//����ֵ�ǵ�����
	ms1.insert(20);
	ms1.insert(20);
	ms1.insert(10);
}
//pair���飬��ͷ�ļ�
void test46(void)
{
	//��ʼ��
	pair<string, int> p1;//Ĭ�Ϲ���
	pair<string, int> p2("lisi", 20);//�вι���
	cout << p2.first << "  " << p2.second << endl;
	pair<string, int> p3(p2);//��������
	cout << p3.first << "  " << p3.second << endl;
	//��ֵ
	pair<string, int> p4;
	p4 = make_pair("wangwu", 18);//�Ƽ�
	cout << p4.first << "  " << p4.second << endl;
	pair<string, int> p5;
	p5.first = "zhangsan";
	p5.second = 16;
	cout << p5.first << "  " << p5.second << endl;
	pair<string, int> p6;
	p6 = p5;
	cout << p6.first << "  " << p6.second << endl;
}
//����
class Comp1
{
public:
	bool operator()(const int& v1, const int& v2) const//VS����ʹ��const���Σ�const�������ε���thisָ��
	{
		return v1 > v2;
	}
};
void test47(void)
{
	//��������ǰָ������������÷º�����
	set<int, Comp1> s1;
	s1.insert(500);
	s1.insert(200);
	s1.insert(300);
	s1.insert(400);
	s1.insert(100);
	//s1.insert(100);
	for (set<int, Comp1>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//�Զ����������ݵ��Զ�������
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
class Comp2
{
public:
	bool operator()(const Peo& p1, const Peo& p2) const
	{
		return p1.m_age > p2.m_age;
	}
};
void test48(void)
{
	set<Peo, Comp2> s1;
	Peo p1("����", 35);
	Peo p2("�ܲ�", 45);
	Peo p3("��Ȩ", 40);
	Peo p4("����", 25);
	Peo p5("�ŷ�", 36);
	Peo p6("����", 35);//ע�⼴ʹ��������ͬ���ֲ�ͬҲ���ظ�����
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	s1.insert(p6);
	for (set<Peo, Comp2>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << it->m_name << "  " << it->m_age << endl;
	}
}

//int main(void)
//{
//	//test41();
//	//test42();
//	//test43();
//	//test44();
//	//test45();
//	//test46();
//	//test47();
//	test48();
//	return 0;
//}