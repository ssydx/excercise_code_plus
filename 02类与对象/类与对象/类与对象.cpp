#include <iostream>
using namespace std;
#include <string>
#define PI 3.14
#include "point.h"
#include "circle.h"
//�������Ժ���Ϊ���ϳƳ�Ա
//�����ֳƳ�Ա���ԣ���Ա����
//��Ϊ�ֳƳ�Ա��������Ա����

////��Ĵ���
//class Circle
//{
//	//����Ȩ��
//public:
//	//����
//	int m_r;
//	//��Ϊ
//	double calc_len()
//	{
//		return 2 * PI * m_r;
//	}
//};
//int main(void)
//{
//	//ʵ����
//	Circle c1;
//	//��ʼ������
//	c1.m_r = 10;
//	//ʹ�÷���
//	cout << c1.calc_len() << endl;
//	return 0;
//}

//class Stu
//{
//public:
//	string m_name;
//	string m_id;
//	//��ʾѧ����Ϣ
//	void showStu()
//	{
//		cout << m_name << endl;
//		cout << m_id << endl;
//	}
//	//����ѧ������
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

//Ȩ��
//����Ȩ��public���������ⶼ�ɷ��ʣ�
//����Ȩ��protected�����ڿɷ��ʣ��ӿ��Է��ʣ�
//˽��Ȩ��private�����ڿɷ��ʣ��Ӳ����Է��ʣ�

//class Peo
//{
//	//�������ⶼ�ɷ���
//public:
//	string name="zhangsan";
//	//�����ڿɷ���
//protected:
//	string car="jieda";
//private:
//	//�����ڿɷ���
//	int password = 123456;
//};
//int main()
//{
//	Peo p1;
//	//������޸�
//	p1.name = "lisi";
//	//���ⲻ���޸�
//	//p1.car = "bieke";
//	//p1.password = 123123;
//	return 0;
//}

//struct��class
//struct��Ĭ��Ȩ��Ϊ������class��Ĭ��Ȩ��Ϊ˽��

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
//	//c.ca = 100;//���ɷ���
//	S s;
//	s.sa = 100;
//	return 0;
//}

//��Ա����˽�л�����������Ľӿڽ����޸�
//�����Լ����ƶ�дȨ�ޣ����Լ��д���ݵ���Ч��

//typedef class Peo
//{
//public:
//	//����
//	void setname(string tmp)
//	{
//		name = tmp;
//	}
//	string getname(void)
//	{
//		return name;
//	}
//	//����
//	void setage(int tmp)
//	{
//		//��Ч�Լ��
//		if (tmp < 0 || tmp>150)
//		{
//			cout << "������Ч\n";
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
//	//����
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
//	cout << p.getname() << endl;//�������
//	p.setage(30);
//	cout << p.getage() << endl;//�������
//	p.setlover("cangjingkong");
//	cout << p.getlover() << endl;//�������
//	return 0;
//}

//��������
//typedef class Cube
//{
//	//ͨ�������ӿڽ��������޸Ļ��õȲ���
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
//	//����Ӧ����˽��
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
//	//�����ⲿ�����ж�
//	bool ret = isequal(c1, c2);
//	if (ret)
//	{
//		cout << "���" << endl;
//	}
//	else
//	{
//		cout << "����" << endl;
//	}
//	//���ó�Ա�����ж�
//	ret = c1.isequalbyclass(c2);
//	if (ret)
//	{
//		cout << "���" << endl;
//	}
//	else
//	{
//		cout << "����" << endl;
//	}
//	return 0;
//}

//���Բ
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
//	//���õ�
//	Point p;
//	p.setx(10);
//	p.sety(10);
//	//����Բ�ĵ�
//	Point pc;
//	pc.setx(16);
//	pc.sety(10);
//	Circle c;
//	c.setcenter(pc);
//	//���ð뾶
//	c.setr(5);
//	check(c, p);
//
//	return 0;
//}

