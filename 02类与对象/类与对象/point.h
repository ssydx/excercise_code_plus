#pragma once
using namespace std;

typedef class Point
{
public:
	void setx(int x);

	int getx(void);

	void sety(int y);

	int gety(void);

private:
	int m_x;
	int m_y;
}Point;