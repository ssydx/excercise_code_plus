#include <iostream>
using namespace std;
#include <string>
#define PI 3.14
#include "point.h"
#include "circle.h"
//类有属性和行为，合称成员
//属性又称成员属性，成员变量
//行为又称成员方法，成员函数

////类的创建
//class Circle
//{
//	//访问权限
//public:
//	//属性
//	int m_r;
//	//行为
//	double calc_len()
//	{
//		return 2 * PI * m_r;
//	}
//};
//int main(void)
//{
//	//实例化
//	Circle c1;
//	//初始化属性
//	c1.m_r = 10;
//	//使用方法
//	cout << c1.calc_len() << endl;
//	return 0;
//}

//class Stu
//{
//public:
//	string m_name;
//	string m_id;
//	//显示学生信息
//	void showStu()
//	{
//		cout << m_name << endl;
//		cout << m_id << endl;
//	}
//	//设置学生姓名
//	void setname(string name)
//	{
//		m_name = name;
//	}
//};
//int main(void)
//{
//	//Stu s1 = { "zhangsan","202100021" };
//	Stu s1;
//	s1.setname("zhangsan");
//	s1.m_id = "202100032";
//	s1.showStu();
//	return 0;
//}

//权限
//公共权限public（类内类外都可访问）
//保护权限protected（类内可访问，子可以访问）
//私有权限private（类内可访问，子不可以访问）

//class Peo
//{
//	//类内类外都可访问
//public:
//	string name="zhangsan";
//	//仅类内可访问
//protected:
//	string car="jieda";
//private:
//	//仅类内可访问
//	int password = 123456;
//};
//int main()
//{
//	Peo p1;
//	//类外可修改
//	p1.name = "lisi";
//	//类外不可修改
//	//p1.car = "bieke";
//	//p1.password = 123123;
//	return 0;
//}

//struct与class
//struct的默认权限为公共，class的默认权限为私有

//typedef class
//{
//	int ca;
//}C;
//typedef struct
//{
//	int sa;
//}S;
//int main(void)
//{
//	C c;
//	//c.ca = 100;//不可访问
//	S s;
//	s.sa = 100;
//	return 0;
//}

//成员属性私有化，设置另外的接口进行修改
//可以自己控制读写权限，可以检测写数据的有效性

//typedef class Peo
//{
//public:
//	//姓名
//	void setname(string tmp)
//	{
//		name = tmp;
//	}
//	string getname(void)
//	{
//		return name;
//	}
//	//年龄
//	void setage(int tmp)
//	{
//		//有效性检测
//		if (tmp < 0 || tmp>150)
//		{
//			cout << "年龄无效\n";
//		}
//		else
//		{
//			age = tmp;
//		}
//	}
//	int getage()
//	{
//		return age;
//	}
//	//恋人
//	void setlover(string tmp)
//	{
//		lover = tmp;
//	}
//	string getlover()
//	{
//		return lover;
//	}
//private:
//	string name;
//	int age = 0;
//	string lover;
//}Peo;
//int main(void)
//{
//	Peo p;
//	p.setname("zhangsan");
//	cout << p.getname() << endl;//输出姓名
//	p.setage(30);
//	cout << p.getage() << endl;//输出年龄
//	p.setlover("cangjingkong");
//	cout << p.getlover() << endl;//输出恋人
//	return 0;
//}

//立方体类
//typedef class Cube
//{
//	//通过公开接口进行属性修改或获得等操作
//public:
//	void setL(int l)
//	{
//		m_l = l;
//	}
//	int getL()
//	{
//		return m_l;
//	}
//	void setW(int w)
//	{
//		m_w = w;
//	}
//	int getW()
//	{
//		return m_w;
//	}
//	void setH(int h)
//	{
//		m_h = h;
//	}
//	int getH()
//	{
//		return m_h;
//	}
//	int calcS()
//	{
//		return 2 * (m_l * m_w + m_w * m_h + m_h * m_l);
//	}
//	int calcV()
//	{
//		return m_l * m_w * m_h;
//	}
//	bool isequalbyclass(Cube& c)
//	{
//		if (m_h == c.getH() && m_l == c.getL() && m_h == c.getW())
//		{
//			return true;
//		}
//		return false;
//	}
//	//属性应保持私有
//private:
//	int m_l;
//	int m_w;
//	int m_h;
//}Cube;
//bool isequal(Cube& c1, Cube& c2)
//{
//	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	Cube c1;
//	c1.setL(10);
//	c1.setW(10);
//	c1.setH(10);
//	cout << c1.calcS() << endl;
//	cout << c1.calcV() << endl;
//
//	Cube c2;
//	c2.setL(10);
//	c2.setW(10);
//	c2.setH(10);
//	//利用外部函数判断
//	bool ret = isequal(c1, c2);
//	if (ret)
//	{
//		cout << "相等" << endl;
//	}
//	else
//	{
//		cout << "不等" << endl;
//	}
//	//利用成员函数判断
//	ret = c1.isequalbyclass(c2);
//	if (ret)
//	{
//		cout << "相等" << endl;
//	}
//	else
//	{
//		cout << "不等" << endl;
//	}
//	return 0;
//}

//点和圆
//void check(Circle& c, Point& p)
//{
//	int dis =
//		(c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx())
//		+ (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
//	int rdis = c.getr() * c.getr();
//	if (dis == 0)
//	{
//		cout << "on circle center" << endl;
//	}
//	else if(dis < rdis)
//	{
//		cout << "in circle" << endl;
//	}
//	else if (dis == rdis)
//	{
//		cout << "on circle" << endl;
//	}
//	else
//	{
//		cout << "out of circle" << endl;
//	}
//}
//int main(void)
//{
//	//设置点
//	Point p;
//	p.setx(10);
//	p.sety(10);
//	//设置圆心点
//	Point pc;
//	pc.setx(16);
//	pc.sety(10);
//	Circle c;
//	c.setcenter(pc);
//	//设置半径
//	c.setr(5);
//	check(c, p);
//
//	return 0;
//}

