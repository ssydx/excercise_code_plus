#pragma once
using namespace std;
#include <iostream>
#include <string>

template<class T>
class Array
{
public:
	//�вι���
	Array(int capacity)
	{
		m_capacity = capacity;
		m_size = 0;
		paddr = new T[m_capacity];
		//cout << "�вι���" << endl;
	}
	//����
	~Array()
	{
		if (paddr != NULL)
		{
			delete[]paddr;
			paddr = NULL;
		}
		//cout << "����" << endl;
	}
	//��������
	Array(const Array& arr)
	{
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		paddr = new T[arr.m_capacity];
		for (int i = 0; i < arr.m_size; i++)
		{
			paddr[i] = arr.paddr[i];
		}
		//cout << "��������" << endl;
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
	//����(����[])
	T& operator[](int index)
	{
		return paddr[index];
	}
	//����
	void Push(const T& val)
	{
		if (m_capacity == m_size)
		{
			cout << "��������" << endl;
			return;
		}
		paddr[m_size] = val;
		m_size++;
	}
	//ɾ��
	void Pop()
	{
		if (m_size == 0)
		{
			return;
		}
		m_size--;
	}
	//��Ϣ
	int GetSize()
	{
		return m_size;
	}
	int GetCapacity()
	{
		return m_capacity;
	}
private:

	//����
	T* paddr;
	//����
	int m_capacity;
	//��С
	int m_size;
};

