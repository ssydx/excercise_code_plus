#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "C的头文件.h"

template<class T1, class T2>
C<T1, T2>::C(T1 name, T2 age)
{
	m_name = name;
	m_age = age;
}
template<class T1, class T2>
void C<T1, T2>::Show()
{
	cout << m_name << "    " << m_age << endl;
}