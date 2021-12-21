#pragma once
using namespace std;
#include <iostream>
#include <string>

template<class T1, class T2>
class C
{
public:
	C(T1 name, T2 age);
	void Show();
	T1 m_name;
	T2 m_age;
};