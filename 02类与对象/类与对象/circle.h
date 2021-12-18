#pragma once//避免多次包含
#include "point.h"
using namespace std;

typedef class Circle
{
public:
	void setcenter(Point center);//只保留函数声明

	Point getcenter(void);

	void setr(int r);

	int getr(void);

private:
	Point m_center;//保留属性
	int m_r;
}Circle;