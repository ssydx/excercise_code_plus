#pragma once//�����ΰ���
#include "point.h"
using namespace std;

typedef class Circle
{
public:
	void setcenter(Point center);//ֻ������������

	Point getcenter(void);

	void setr(int r);

	int getr(void);

private:
	Point m_center;//��������
	int m_r;
}Circle;