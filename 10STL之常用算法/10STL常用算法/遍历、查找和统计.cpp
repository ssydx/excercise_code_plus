#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//遍历for_each
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
	for_each(v1.begin(), v1.end(), Print_0);//普通函数直接放入函数名即可
	cout << endl;
	for_each(v1.begin(), v1.end(), Print_a());
	cout << endl;
}
//遍历(搬运)transform
class Transform_a1//直接搬运
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
	vdest.resize(vsrc.size());//提前开辟空间
	transform(vsrc.begin(), vsrc.end(), vdest.begin(), Transform_a1());//直接搬运也必须使用仿函数
	for_each(vdest.begin(), vdest.end(), Print_a());
	cout << endl;
	transform(vsrc.begin(), vsrc.end(), vdest.begin(), Transform_a2());//搬运同时进行元素的平方
	for_each(vdest.begin(), vdest.end(), Print_a());
	cout << endl;
}
//查找find，返回值为迭代器（自定义类型需要重载==）
class Peo_a1
{
public:
	Peo_a1(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Peo_a1& p)//必须加const
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
	//内置数据
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	vector<int>::iterator pos_i = find(v1.begin(), v1.end(), 5);//返回值为迭代器
	if (pos_i == v1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *pos_i << endl;
	}
	//自定义数据要重载==
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
//查找find_if，必须自定义条件
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
	//内置数据
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	vector<int>::iterator pos_i = find_if(v1.begin(), v1.end(), Greater5_a());//返回值为首个满足条件的迭代器
	if (pos_i == v1.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << *pos_i << endl;
	}

	//自定义数据
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
	//找年龄大于25的
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
//查找adjacent_find，查找相邻重复元素，返回相邻元素中首个元素的地址（面试题可能出现）
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
//查找binary_search，元素要求有序，无序查询结果会错误，注意返回值为bool
void test_al6(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	v.push_back(9);
	v.push_back(10);
	v.push_back(3);//无序往往会查询不到
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
//统计count（自定义类型需要重载==）
class Peo_a3
{
public:
	Peo_a3(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	bool operator==(const Peo_a3& p)//必须加const，何时加？
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
	//内置数据
	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(50);
	int num_i = count(v.begin(), v.end(), 50);
	cout << num_i << endl;

	//自定义数据
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
//统计count_if，必须自定义条件
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
	//内置数据
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	int num_i = count_if(v.begin(), v.end(), Greater20());
	cout << num_i << endl;

	//自定义数据
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
	int num_p = count_if(vp.begin(), vp.end(), p);//类内重载，直接传入待比较的对象，灵活性更高
	//int num_p = count_if(vp.begin(), vp.end(), Greater30());//类外重载，传入一元谓词（仿函数），但灵活性低
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

