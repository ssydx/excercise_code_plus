#pragma once
using namespace std;
#include <iostream>
#include <string>

template<class T>
class Array
{
public:
	//有参构造
	Array(int capacity)
	{
		m_capacity = capacity;
		m_size = 0;
		paddr = new T[m_capacity];
		//cout << "有参构造" << endl;
	}
	//析构
	~Array()
	{
		if (paddr != NULL)
		{
			delete[]paddr;
			paddr = NULL;
		}
		//cout << "析构" << endl;
	}
	//拷贝构造
	Array(const Array& arr)
	{
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		paddr = new T[arr.m_capacity];
		for (int i = 0; i < arr.m_size; i++)
		{
			paddr[i] = arr.paddr[i];
		}
		//cout << "拷贝构造" << endl;
	}
	//operator=
	Array& operator=(const Array& arr)
	{
		if (paddr != NULL)
		{
			delete[]paddr;
			paddr = NULL;
			m_capacity = 0;
			m_size = 0;
		}
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		paddr = new T[arr.m_capacity];
		for (int i = 0; i < arr.m_size; i++)
		{
			paddr[i] = arr.paddr[i];
		}
		//cout << "operator=" << endl;
		return *this;
	}
	//访问(重载[])
	T& operator[](int index)
	{
		return paddr[index];
	}
	//增加
	void Push(const T& val)
	{
		if (m_capacity == m_size)
		{
			cout << "数组已满" << endl;
			return;
		}
		paddr[m_size] = val;
		m_size++;
	}
	//删除
	void Pop()
	{
		if (m_size == 0)
		{
			return;
		}
		m_size--;
	}
	//信息
	int GetSize()
	{
		return m_size;
	}
	int GetCapacity()
	{
		return m_capacity;
	}
private:

	//数组
	T* paddr;
	//容量
	int m_capacity;
	//大小
	int m_size;
};

