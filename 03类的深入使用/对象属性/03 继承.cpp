#pragma once
using namespace std;
#include <iostream>

//继承
//继承有三种类型：公共、保护、私有
//继承者叫子类（派生类），被继承者叫父类（基类）
//可以明显减少代码冗余



//class BasePage
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图" << endl;
//	}
//	void left()
//	{
//		cout << "JAVA、Python、C、CPP" << endl;
//	}
//};
//class C :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "C学科视频" << endl;
//	}
//};
//class CPP :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "CPP学科视频" << endl;
//	}
//};
//class JAVA :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "JAVA学科视频" << endl;
//	}
//};
//class Python :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Python学科视频" << endl;
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
//private://父类的私有权限子类不可访问
//	int m_c;
//};
//class Son1:public Base//父类的公共、保护权限也被继承
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;
//	}
//};
//class Son2 :protected Base//父类的公共权限被改为保护，保护权限保持不变
//{
//public:
//	void func()
//	{
//		m_a = 10;
//		m_b = 10;
//		//m_c = 10;
//	}
//};
//class Son3 :private Base//父类的公共、保护权限被改为私有
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
//	//cout << s1.m_b << endl;保护权限不可访问
//	Son2 s2;
//	s2.func();
//	//cout << s2.m_a << endl;被保护继承的权限类外不可访问
//	Son3 s3;
//	s3.func();
//	//cout << s3.m_a << endl;被私有继承的权限类外不可访问
//}
//int main(void)
//{
//	test1();
//	return 0;
//}



//本质上父类的所有属性和方法都被继承，即占用对应的内存，但有些不可访问

//class Base
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private://父类的私有权限子类不可访问
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
//	cout << sizeof(Son1) << endl;//输出16
//	cout << sizeof(Son2) << endl;//输出16
//	cout << sizeof(Son3) << endl;//输出16
//	return 0;
//}



//继承时的子类对象创建时会先调用父类构造再调用子类构造，释放时则先调用子类析构再调用父类析构

//class Father
//{
//public:
//	Father()
//	{
//		cout << "Father 构造" << endl;
//	}
//	~Father()
//	{
//		cout << "Father 析构" << endl;
//	}
//};
//class Son :public Father
//{
//public:
//	Son()
//	{
//		cout << "Son 构造" << endl;
//	}
//	~Son()
//	{
//		cout << "Son 析构" << endl;
//	}
//};
//int main(void)
//{
//	Son s1;
//	return 0;
//}



//同名成员的处理，子类方法会隐藏父类同名属性和方法（保护重载），要调用父类则必须加作用域
//同名静态成员同理

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
//	cout << s.m_a << endl;//默认打印当前类的同名属性
//	cout << s.Base::m_a << endl; //加父类作用域才能输出父类属性
//
//	s.func();//默认调用当前类的同名方法
//	s.Base::func();//加父类作用域才能输出父类方法
//	//s.func(10);即使发生函数重载也不可直接调用同名的父类方法
//	s.Base::func(10);//只要同名就必须给父类加作用域
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
//	cout << Son::Base::m_a << endl;//左侧::表示通过Son类名访问，右侧::表示访问父类作用域下的m_a
//	return 0;
//}



//多继承，不建议使用

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
//	cout << sizeof(s) << endl;//输出24
//	cout << s.m_a << endl;
//	cout << s.Fa1::m_a << endl;
//	cout << s.Fa2::m_a << endl;
//	cout << s.m_b << endl;
//	cout << s.m_b1 << endl;
//	cout << s.m_b2 << endl;
//}



//菱形继承
//virtual使其成为虚基类，产生虚继承

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