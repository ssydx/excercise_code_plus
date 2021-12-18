#pragma once
#include "circle.h"
using namespace std;


void Circle:: setcenter(Point center)
{
	m_center = center;
}
Point Circle:: getcenter(void)
{
	return m_center;
}
void Circle:: setr(int r)
{
	m_r = r;
}
int Circle:: getr(void)
{
	return m_r;
}