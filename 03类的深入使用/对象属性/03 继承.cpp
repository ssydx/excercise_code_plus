#pragma once
using namespace std;
#include <iostream>

//�̳�
//�̳����������ͣ�������������˽��
//�̳��߽����ࣨ�����ࣩ�����̳��߽и��ࣨ���ࣩ
//�������Լ��ٴ�������



//class BasePage
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ" << endl;
//	}
//	void left()
//	{
//		cout << "JAVA��Python��C��CPP" << endl;
//	}
//};
//class C :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Cѧ����Ƶ" << endl;
//	}
//};
//class CPP :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "CPPѧ����Ƶ" << endl;
//	}
//};
//class JAVA :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "JAVAѧ����Ƶ" << endl;
//	}
//};
//class Python :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//};
//int main(void)
//{
//	JAVA ja;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//}

//class Base
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private://�����˽��Ȩ�����಻�ɷ���
//	int m_c;
//};
//class Son1:public Base//����Ĺ���������Ȩ��Ҳ���̳�
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;
//	}
//};
//class Son2 :protected Base//����Ĺ���Ȩ�ޱ���Ϊ����������Ȩ�ޱ��ֲ���
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;
//	}
//};
//class Son3 :private Base//����Ĺ���������Ȩ�ޱ���Ϊ˽��
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;
//	}
//};
//class Grandson1:public Son1
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;
//	}
//};
//class Grandson2 :protected Son2
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;
//	}
//};
//class Grandson3 :private Son3
//{
//public:
//	void func()
//	{
//		//m_a = 10;
//		//m_b = 10;
//		//m_c = 10;
//	}
//};
//void test1(void)
//{
//	Son1 s1;
//	s1.func();
//	cout << s1.m_a << endl;
//	//cout << s1.m_b << endl;����Ȩ�޲��ɷ���
//	Son2 s2;
//	s2.func();
//	//cout << s2.m_a << endl;�������̳е�Ȩ�����ⲻ�ɷ���
//	Son3 s3;
//	s3.func();
//	//cout << s3.m_a << endl;��˽�м̳е�Ȩ�����ⲻ�ɷ���
//}
//int main(void)
//{
//	test1();
//	return 0;
//}



//�����ϸ�����������Ժͷ��������̳У���ռ�ö�Ӧ���ڴ棬����Щ���ɷ���

//class Base
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private://�����˽��Ȩ�����಻�ɷ���
//	int m_c;
//};
//class Son1 :public Base
//{
//public:
//	int m_d;
//};
//class Son2 :protected Base
//{
//public:
//	int m_d;
//};
//class Son3 :private Base
//{
//public:
//	int m_d;
//};
//int main(void)
//{
//	cout << sizeof(Son1) << endl;//���16
//	cout << sizeof(Son2) << endl;//���16
//	cout << sizeof(Son3) << endl;//���16
//	return 0;
//}



//�̳�ʱ��������󴴽�ʱ���ȵ��ø��๹���ٵ������๹�죬�ͷ�ʱ���ȵ������������ٵ��ø�������

//class Father
//{
//public:
//	Father()
//	{
//		cout << "Father ����" << endl;
//	}
//	~Father()
//	{
//		cout << "Father ����" << endl;
//	}
//};
//class Son :public Father
//{
//public:
//	Son()
//	{
//		cout << "Son ����" << endl;
//	}
//	~Son()
//	{
//		cout << "Son ����" << endl;
//	}
//};
//int main(void)
//{
//	Son s1;
//	return 0;
//}



//ͬ����Ա�Ĵ������෽�������ظ���ͬ�����Ժͷ������������أ���Ҫ���ø���������������
//ͬ����̬��Աͬ��

//class Base
//{
//public:
//	Base()
//	{
//		m_a = 10;
//	}
//	void func()
//	{
//		cout << "Base" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Base int a" << endl;
//	}
//	int m_a;
//};
//class Son :public Base
//{
//public:
//	Son()
//	{
//		m_a = 100;
//	}
//	void func()
//	{
//		cout << "Son" << endl;
//	}
//	int m_a;
//};
//int main(void)
//{
//	Son s;
//	cout << s.m_a << endl;//Ĭ�ϴ�ӡ��ǰ���ͬ������
//	cout << s.Base::m_a << endl; //�Ӹ�����������������������
//
//	s.func();//Ĭ�ϵ��õ�ǰ���ͬ������
//	s.Base::func();//�Ӹ������������������෽��
//	//s.func(10);��ʹ������������Ҳ����ֱ�ӵ���ͬ���ĸ��෽��
//	s.Base::func(10);//ֻҪͬ���ͱ���������������
//
//	return 0;
//}

//class Base
//{
//public:
//	static int m_a;
//};
//int Base::m_a = 10;
//class Son:public Base
//{
//public:
//	static int m_a;
//};
//int Son::m_a = 100;
//int main(void)
//{
//	Son s;
//	cout << s.m_a << endl;
//	cout << s.Base::m_a << endl;
//
//	cout << Son::m_a << endl;
//	cout << Son::Base::m_a << endl;//���::��ʾͨ��Son�������ʣ��Ҳ�::��ʾ���ʸ����������µ�m_a
//	return 0;
//}



//��̳У�������ʹ��

//class Fa1
//{
//public:
//	int m_a = 100;
//	int m_b1 = 300;
//};
//class Fa2
//{
//public:
//	int m_a = 200;
//	int m_b2 = 400;
//};
//class So :public Fa1, public Fa2
//{
//public:
//	int m_a = 500;
//	int m_b = 600;
//};
//int main(void)
//{
//	So s;
//	cout << sizeof(s) << endl;//���24
//	cout << s.m_a << endl;
//	cout << s.Fa1::m_a << endl;
//	cout << s.Fa2::m_a << endl;
//	cout << s.m_b << endl;
//	cout << s.m_b1 << endl;
//	cout << s.m_b2 << endl;
//}



//���μ̳�
//virtualʹ���Ϊ����࣬������̳�

//class Animal
//{
//public:
//	int m_age;
//};
//class Sheep:virtual public Animal{};
//class Camel :virtual public Animal{};
//class Alpaca:public Sheep,public Camel{};
//int main(void)
//{
//	Alpaca alpaca;
//	alpaca.m_age = 10;
//	alpaca.Sheep::m_age = 20;
//	alpaca.Camel::m_age = 30;
//	cout << alpaca.Sheep::m_age << endl;
//	cout << alpaca.Camel::m_age << endl;
//}