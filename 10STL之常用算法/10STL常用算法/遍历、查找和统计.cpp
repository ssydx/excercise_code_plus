#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//����for_each
void Print_0(int i)
{
	cout << i << " ";
}
class Print_a
{
public:
	void operator()(int i)
	{
		cout << i << " ";
	}
};
void test_al1(void)
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	for_each(v1.begin(), v1.end(), Print_0);//��ͨ����ֱ�ӷ��뺯��������
	cout << endl;
	for_each(v1.begin(), v1.end(), Print_a());
	cout << endl;
}
//����(����)transform
class Transform_a1//ֱ�Ӱ���
{
public:
	int operator()(int i)
	{
		return i;
	}
};
class Transform_a2
{
public:
	int operator()(int i)
	{
		return i * i;
	}
};
void test_al2(void)
{
	vector<int> vsrc;
	for (int i = 0; i < 10; i++)
	{
		vsrc.push_back(i + 1);
	}
	vector<int> vdest;
	vdest.resize(vsrc.size());//��ǰ���ٿռ�
	transform(vsrc.begin(), vsrc.end(), vdest.begin(), Transform_a1());//ֱ�Ӱ���Ҳ����ʹ�÷º���
	for_each(vdest.begin(), vdest.end(), Print_a());
	cout << endl;
	transform(vsrc.begin(), vsrc.end(), vdest.begin(), Transform_a2());//����ͬʱ����Ԫ�ص�ƽ��
	for_each(vdest.begin(), vdest.end(), Print_a());
	cout << endl;
}
//����find������ֵΪ���������Զ���������Ҫ����==��
class Peo_a1
{
public:
	Peo_a1(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Peo_a1& p)//�����const
	{
		if (m_name == p.m_name && m_age == p.m_age)
		{
			return true;
		}
		return false;
	}
	string m_name;
	int m_age;
};
void test_al3(void)
{
	//��������
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	vector<int>::iterator pos_i = find(v1.begin(), v1.end(), 5);//����ֵΪ������
	if (pos_i == v1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *pos_i << endl;
	}
	//�Զ�������Ҫ����==
	vector<Peo_a1> vp1;
	Peo_a1 p1("aaa", 10);
	Peo_a1 p2("bbb", 20);
	Peo_a1 p3("ccc", 30);
	Peo_a1 p4("ddd", 40);
	Peo_a1 p5("eee", 50);
	vp1.push_back(p1);
	vp1.push_back(p2);
	vp1.push_back(p3);
	vp1.push_back(p4);
	vp1.push_back(p5);
	Peo_a1 p("ddd", 40);
	vector<Peo_a1>::iterator pos_p = find(vp1.begin(), vp1.end(), p);
	if (pos_p == vp1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << pos_p->m_name << "  " << pos_p->m_age << endl;
	}
}
//����find_if�������Զ�������
class Greater5_a
{
public:
	bool operator()(int v)
	{
		return v > 5;
	}
};
class Peo_a2
{
public:
	Peo_a2(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
class Greater25_a
{
public:
	bool operator()(Peo_a2& p)
	{
		return p.m_age > 25;
	}
};
void test_al4(void)
{
	//��������
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	vector<int>::iterator pos_i = find_if(v1.begin(), v1.end(), Greater5_a());//����ֵΪ�׸����������ĵ�����
	if (pos_i == v1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *pos_i << endl;
	}

	//�Զ�������
	vector<Peo_a2> vp1;
	Peo_a2 p1("aaa", 10);
	Peo_a2 p2("bbb", 20);
	Peo_a2 p3("ccc", 30);
	Peo_a2 p4("ddd", 40);
	Peo_a2 p5("eee", 50);
	vp1.push_back(p1);
	vp1.push_back(p2);
	vp1.push_back(p3);
	vp1.push_back(p4);
	vp1.push_back(p5);
	//���������25��
	vector<Peo_a2>::iterator pos_p = find_if(vp1.begin(), vp1.end(), Greater25_a());
	if (pos_p == vp1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << pos_p->m_name << "  " << pos_p->m_age << endl;
	}
}
//����adjacent_find�����������ظ�Ԫ�أ���������Ԫ�����׸�Ԫ�صĵ�ַ����������ܳ��֣�
void test_al5(void)
{
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *pos << endl;
	}
}
//����binary_search��Ԫ��Ҫ�����������ѯ��������ע�ⷵ��ֵΪbool
void test_al6(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	v.push_back(9);
	v.push_back(10);
	v.push_back(3);//�����������ѯ����
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
}
//ͳ��count���Զ���������Ҫ����==��
class Peo_a3
{
public:
	Peo_a3(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Peo_a3& p)//�����const����ʱ�ӣ�
	{
		if (m_age == p.m_age)
		{
			return true;
		}
		return false;
	}
	string m_name;
	int m_age;
};
void test_al7(void)
{
	//��������
	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(50);
	int num_i = count(v.begin(), v.end(), 50);
	cout << num_i << endl;

	//�Զ�������
	vector<Peo_a3> vp;
	Peo_a3 p1("zhangsan", 24);
	Peo_a3 p2("lsi", 23);
	Peo_a3 p3("wangwu", 20);
	Peo_a3 p4("zs", 28);
	Peo_a3 p5("ls", 23);
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);
	Peo_a3 p("fanli", 23);
	int num_p = count(vp.begin(), vp.end(), p);
	cout << num_p << endl;
}
//ͳ��count_if�������Զ�������
class Greater20
{
public:
	bool operator()(int i)
	{
		return i > 20;
	}
};
class Peo_a4
{
public:
	Peo_a4(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator()(Peo_a4& p)
	{
		return m_age > p.m_age;
	}
	string m_name;
	int m_age;
};
class Greater30
{
public:
	bool  operator()(Peo_a4& p)
	{
		return p.m_age > 30;
	}
};
void test_al8(void)
{
	//��������
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	int num_i = count_if(v.begin(), v.end(), Greater20());
	cout << num_i << endl;

	//�Զ�������
	vector<Peo_a4> vp;
	Peo_a4 p1("liubei", 35);
	Peo_a4 p2("guanyu", 30);
	Peo_a4 p3("zhangfei", 40);
	Peo_a4 p4("zhaoyun", 20);
	Peo_a4 p5("caocao", 20);
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);
	Peo_a4 p("sunquan", 30);
	int num_p = count_if(vp.begin(), vp.end(), p);//�������أ�ֱ�Ӵ�����ȽϵĶ�������Ը���
	//int num_p = count_if(vp.begin(), vp.end(), Greater30());//�������أ�����һԪν�ʣ��º�������������Ե�
	cout << num_p << endl;
}

//int main(void)
//{
//	//test_al1();
//	//test_al2();
//	//test_al3();
//	//test_al4();
//	//test_al5();
//	//test_al6();
//	//test_al7();
//	test_al8();
//
//	return 0;
//}

