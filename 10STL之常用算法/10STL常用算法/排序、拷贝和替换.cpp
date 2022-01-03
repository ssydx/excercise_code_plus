#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>//���÷º���ģ��
#include <ctime>
#include <numeric>//accumulate

void Print_a(int i)
{
	cout << i << " ";
}
//����sort��������Ҫ
class Greater
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test_al9(void)
{
	vector<int> v;
	v.push_back(9);
	v.push_back(5);
	v.push_back(2);
	v.push_back(10);
	v.push_back(7);
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	sort(v.begin(), v.end());//Ĭ������
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	sort(v.begin(), v.end(), Greater());//�����Զ���º�������
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	sort(v.begin(), v.end(), less<int>());//�����ڽ��º���ģ������
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//����random_shuffle
void test_al10(void)
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}
	srand((unsigned int)time(NULL));//�ǵü�����
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//�ϲ�merge������������������ϲ�Ϊһ�����������
void test_al11()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	vtar.resize(v1.size() + v2.size());//������ǰ�����㹻���ڴ�
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());//���봫�������vector�ϲ�����Ȼ����
	for_each(vtar.begin(), vtar.end(), Print_a);
	cout << endl;
}
//��תreverse
void test_al12(void)
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	reverse(v.begin(), v.end());//��ת
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//����copy���������ݿ�ֱ����=��assgin���Զ������ݲ��迼��
void test_al13(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(30);
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), Print_a);
	cout << endl;
}
//�滻replace
void test_al14(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(20);
	replace(v1.begin(), v1.end(), 20, 100);//��ָ����Χ��ָ������ȫ���滻Ϊ�µ�����
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
}
//�滻replace_if
class Less30
{
public:
	bool operator()(int v)
	{
		return v < 23;
	}
};
void test_al15(void)
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(20);
	replace_if(v1.begin(), v1.end(), Less30(), 100);
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
}
//����swap���滻ͬ��������
void test_al16(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 10);
	}
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
	for_each(v2.begin(), v2.end(), Print_a);
	cout << endl;
	swap(v1, v2);//����
	for_each(v1.begin(), v1.end(), Print_a);
	cout << endl;
	for_each(v2.begin(), v2.end(), Print_a);
	cout << endl;
}
//accumulate�ۼ�
void test_al17(void)
{
	vector<int> v;
	for (int i = 1; i <= 100; i++)
	{
		v.push_back(i);
	}
	int sum = accumulate(v.begin(), v.end(), 0);//�����������Ƕ�����ϸ���
	cout << sum << endl;
}
//fill���
void test_al18(void)
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.resize(10);//Ĭ���¿��ٵĿռ�����0
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	v.resize(15, 20);//ע��ֻ�����¿��ٵĿռ�ű�����ָ��ֵ
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
	fill(v.begin(), v.end(), 100);//ָ����������ָ��ֵ
	for_each(v.begin(), v.end(), Print_a);
	cout << endl;
}
//����set_intersection
void test_al19(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	//vtar.resize(min(v1.size(), v2.size()));//����ȡԭ���н�С�Ĵ�С��ʹ�õ���min()�����㷨
	vtar.resize(v1.size() > v2.size() ? v2.size() : v1.size());
	vector<int>::iterator pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());
	for_each(vtar.begin(), pos, Print_a);//ע��Ӧ��ʹ�����շ��صĵ���������Ȼ���ܴ�ӡ��resize��Ĭ��ֵ0
}
//����set_union
void test_al20(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	vtar.resize(v1.size() + v2.size());//ȡԭ����С֮��
	vector<int>::iterator pos = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());
	for_each(vtar.begin(), pos, Print_a);//ע��Ӧ��ʹ�����շ��صĵ���������Ȼ���ܴ�ӡ��resize��Ĭ��ֵ0
	cout << endl;
}
//�set_difference
void test_al21(void)
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 5);
	}
	vector<int> vtar;
	vtar.resize(v1.size());//ȡ����Ĵ�С
	vector<int>::iterator pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vtar.begin());
	//ǰ��Ϊ������������Ϊv1������Ŀ�꼯vtar�����ܴ���v1��Ҳ����ֱ��ָ��Ϊԭ���еĽϴ��ߣ���Ϊ��ʱ���ܻ�������
	for_each(vtar.begin(), pos, Print_a);//ע��Ӧ��ʹ�����շ��صĵ���������Ȼ���ܴ�ӡ��resize��Ĭ��ֵ0
	cout << endl;
}


//int main(void)
//{
//	//test_al9();
//	//test_al10();
//	//test_al11();
//	//test_al12();
//	//test_al13();
//	//test_al14();
//	//test_al15();
//	//test_al16();
//	//test_al17();
//	//test_al18();
//	test_al19();
//	//test_al20();
//	//test_al21();
//	return 0;
//}


void test_al(void)
{

}
class Peo_a
{
public:
	Peo_a(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};