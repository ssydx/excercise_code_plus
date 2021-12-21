#pragma once
using namespace std;
#include <iostream>
#include <string>

template<class T1,class T2>
class C
{
public:
	C(T1 name, T2 age);
	void Show();
	T1 m_name;
	T2 m_age;
};
template<class T1, class T2>
C<T1, T2>:: C(T1 name, T2 age)
{
	m_name = name;
	m_age = age;
}
template<class T1, class T2>
void C<T1, T2>:: Show()
{
	cout << m_name << "    " << m_age << endl;
}