#pragma once
using namespace std;
#include <iostream>

//类可直接使用类标识符

//构造函数和析构函数（拷贝构造函数）
//编译器默认就有（默认构造默认析构），但为空实现（拷贝函数默认进行属性拷贝）
//构造函数和析构函数都没有返回类型
//构造函数可以有参数，析构函数没有参数
//构造函数名为类名，析构函数为类名加~
//自定义构造和析构函数要放在公共权限下
//系统自动调用，变量创建时调用构造函数，变量释放时调用析构函数
//构造函数分为无参构造和有参构造，也分为普通构造和拷贝构造
//调用构造函数有三种方法：括号法，显示法，隐式转换法
//拷贝构造函数的调用时机：利用已知对象来初始化新对象
//值传递方式传参，值返回局部对象
//若用户定义有参构造则编译器不再提供默认无参构造，但提供默认拷贝函数
//如果用户定义拷贝构造函数则不再提供构造函数

//class Peo
//{
//public:
//	//构造函数
//	Peo()
//	{
//		cout << "Peo 构造函数调用" << endl;
//	}
//	Peo(int a)
//	{
//		age = a;
//		cout << "Peo 有参构造调用" << endl;
//	}
//	Peo(const Peo &p)//使用const加引用
//	{
//		age = p.age;
//		cout << "Peo 拷贝构造调用" << endl;
//	}
//	//析构函数
//	~Peo()
//	{
//		cout << "Peo 析构函数调用" << endl;
//	}
//public:
//	int getage(void)
//	{
//		return age;
//	}
//private:
//	int age;
//};
//void test01()//初始化调用拷贝构造函数
//{
//	Peo p;//无参构造不要加括号避免编译器视作函数声明
//	Peo p1(10);
//	Peo p2(p1);
//	//Peo p1 = Peo(10);//显示法
//	//Peo p2 = Peo(p1);显示法
//	//Peo(10);匿名对象调用有参构造函数后立即调用析构函数，基本无意义
//	//Peo(p2);匿名对象无法调用拷贝构造函数，编译器会解释为Peo p2;
//	//Peo p4 = 10;隐式转换法
//	//Peo p5 = p4;隐式转换法
//	cout << p1.getage() << endl;//输出10
//	cout << p2.getage() << endl;//输出10
//}
//void dowork(Peo p)//值传递调用拷贝构造函数
//{
//
//}
//void test02()
//{
//	Peo pd;
//	dowork(pd);
//}
//Peo dowork2(void)//值返回调用拷贝构造函数
//{
//	Peo pd1;
//	cout << &pd1 << endl;
//	return pd1;
//}
//void test3(void)
//{
//	Peo pd2 = dowork2();
//	cout << &pd2 << endl;
//}
//struct S
//{
//	int age;
//};
//int main(void)
//{
//	//test01();
//	//test02();
//	//test3();
//	return 0;
//}

//深拷贝与浅拷贝
//当存在开辟在堆区的成员时要自定义深拷贝构造函数，从而避免默认浅拷贝造成的重复释放内存的问题
//class Peo
//{
//public:
//	//默认构造
//	Peo()
//	{
//		cout << "Peo 默认构造" << endl;
//	}
//	//有参构造
//	Peo(int age,int height)
//	{
//		m_age = age;
//		m_height = new int(height);
//		cout << "Peo 有参构造" << endl;
//	}
//	//拷贝构造
//	Peo(const Peo& p)
//	{
//		m_age = p.m_age;
//		//m_height = p.m_height;//默认的浅拷贝
//		m_height = new int(*p.m_height);//自定义的深拷贝
//		cout << "Peo 的拷贝构造" << endl;
//	}
//	//析构函数
//	~Peo()
//	{
//		if (m_height != NULL)//默认拷贝构造函数使不同的m_height指向同一块内存，释放空间时会导致重复释放
//		{
//			delete m_height;
//			m_height = NULL;
//		}
//		cout << "Peo 析构" << endl;
//	}
//	int m_age;
//	int* m_height;
//};
//void test1()
//{
//	Peo p1(18, 160);
//	cout << p1.m_age << endl;
//	cout << *p1.m_height << endl;
//	Peo p2(p1);//编译器提供了默认拷贝构造函数
//	cout << p2.m_age << endl;
//	cout << *p2.m_height << endl;
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

//初始化列表
//class Peo
//{
//public:
//	//构造函数赋初值
//	//Peo(int x, int y, int z)
//	//{
//	//	m_x = x;
//	//	m_y = y;
//	//	m_z = z;
//	//}
//	//初始化列表赋初值，固定值
//	//Peo():m_x(10),m_y(20),m_z(30)
//	//{
//
//	//}
//	//其他值
//	Peo(int x,int y,int z) :m_x(x), m_y(y), m_z(z)//相当于Peo m_x =x（隐式转换法）
//	{
//
//	}
//	int m_x;
//	int m_y;
//	int m_z;
//};
//void test1(void)
//{
//	//Peo p(10, 20, 30);
//	Peo p(10,20,40);
//	cout << p.m_x << endl;
//	cout << p.m_y << endl;
//	cout << p.m_z << endl;
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

//类对象作为类成员时先构造类对象再构造该类，析构时相反
//class A
//{
//public:
//	A()
//	{
//		cout << "A 的构造" << endl;
//	}
//	~A()
//	{
//		cout << "A 的析构" << endl;
//	}
//};
//class B
//{
//public:
//	B()
//	{
//		cout << "B 的构造" << endl;
//	}
//	~B()
//	{
//		cout << "B 的析构" << endl;
//	}
//	A a;
//};
//void test1(void)
//{
//	B b;
//}
//struct S
//{
//
//};
//int main(void)
//{
//	//test1();
//	cout << sizeof(S) << endl;
//	cout << sizeof(A) << endl;
//	return 0;
//}

//静态属性与静态方法
//静态属性和静态方法由所有对象共享，可由类作用域或对象直接调用
//动态属性和动态方法只能由对象调用
//静态方法只能访问静态属性，动态方法可以访问动静态属性
//动态属性只能由动态方法访问
//动态属性务必初始化
//静态属性在类外初始化 类型 作用域::属性名=属性值
//class Peo
//{
//public:
//	void func1(void)
//	{
//		m_height = 170;
//		m_age = 100;
//		cout << "void func1(void)" << endl;
//	}
//	//静态方法
//	static void func(void)
//	{
//		m_age = 20;
//		//m_height = 170;非静态属性不可由静态方法访问
//		cout << "static void func(void)" << endl;
//	}
//	//静态属性
//	static int m_age;
//	int m_height;
//};
////静态属性要类外初始化
//int Peo::m_age = 10;
//void test1(void)
//{
//	////静态
//	//Peo p;
//	////通过对象访问静态属性
//	//cout << p.m_age << endl;//输出10
//	////通过类访问静态属性
//	//cout << Peo::m_age << endl;
//	////通过对象访问静态方法
//	//Peo p1;
//	//p1.func();
//	////通过类（作用域）访问静态方法
//	//Peo::func();
//	//cout << p1.m_age << endl;//输出20
//
//	//动态
//	//Peo p2;
//	//通过对象访问动态属性
//	//cout << p2.m_height << endl;m_height未初始化不可使用
//	//通过类访问动态属性
//	//cout << Peo::m_height << endl;动态属性不能由类访问
//	//通过对象访问动态方法
//	Peo p3;
//	p3.func1();
//	//通过类（作用域）访问动态方法
//	//Peo::func1();动态方法不能由类访问
//	cout << p3.m_age << endl;//输出100
//	cout << p3.m_height << endl;//输出170
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

//类大小
//空类大小为1，空结构体也是1，这点与C不同
//方法不计算入类大小，静态属性也不计算入类大小
//class S
//{
//public:
//	void func()
//	{
//		cout << "func" << endl;
//	}
//	static void func1()
//	{
//		cout << "func1" << endl;
//	}
//	int a;
//	static int age;
//};
//int S::age = 21;
//int main(void)
//{
//	S s;
//	cout << sizeof(S) << endl;//输出4
//	cout << sizeof(s) << endl;//输出4
//	return 0;
//}

//this 指针
//该指针指向调用方法的对象，隐含在方法内，不需要显式定义
//通过this指针解引用可找到对象
//class Peo
//{
//public:
//	Peo(int age)
//	{
//		//m_age = age;
//		this->age = age;
//	}
//	//一次追加
//	void PeoAddAge(Peo& p)
//	{
//		this->age += p.age;
//	}
//	//链式追加
//	//必须以引用方式返回
//	Peo& PeoAddAgePlus(Peo& p)
//	{
//		this->age += p.age;
//		return *this;//返回当前对象
//	}
//	//int m_age;
//	int age;
//};
//void test1(void)
//{
//	Peo p1(21);
//	//cout << p1.m_age << endl;
//	cout << p1.age << endl;//输出10
//}
//void test2(void)
//{
//	Peo p1(10);
//	Peo p2(10);
//	p2.PeoAddAge(p1);
//	cout << p2.age << endl;//输出20
//
//	p2.PeoAddAgePlus(p1).PeoAddAgePlus(p1).PeoAddAgePlus(p1);
//	cout << p2.age << endl;//输出50
//}
//int main(void)
//{
//	//test1();
//	test2();
//	return 0;
//}

//空指针调用方法（不访问属性的方法）
//class Peo
//{
//public:
//	void ShowClassName()
//	{
//		cout << "this is Peo class" << endl;
//	}
//	void ShowPeoAge()
//	{
//		//避免空指针导致的错误
//		if (this == NULL)
//		{
//			return;
//		}
//		cout << "age = " << m_age << endl;//访问当前对象的m_age
//	}
//	int m_age;
//};
//void test1(void)
//{
//	Peo* p = NULL;
//	p->ShowClassName();//可以调用不访问属性的方法
//	p->ShowPeoAge();//空指针不可调用访问属性的方法
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

//const修饰的方法:在成员函数括号后加const，实际是修饰this指针，使其指向的对象不可修改，若想修改需要在对应属性前加mutable
//this 指针的类型 Peo* const this，指针本身不可修改
//class Peo
//{
//public:
//	void ShowPeo(void) const//常函数
//	{
//		//this->m_a = 10;//不可修改
//		this->m_b = 100;
//	}
//	void func(void)
//	{
//
//	}
//	int m_a;
//	mutable int m_b;//使其可被常函数或常对象修改
//};
//void test1(void)
//{
//	Peo p;
//	p.ShowPeo();
//}
//void test2(void)
//{
//	const Peo p;
//	//p.m_a = 10;//不可修改
//	p.m_b = 100;
//	p.ShowPeo();
//	//p.func();常对象不能调用普通函数
//}
//int main(void)
//{
//	test1();
//	test2();
//	return 0;
//}

//友元
////全局函数作为友元
//class Building
//{
//	friend void goodgay(Building& building);//声明全局函数goodgay为友元函数
//public:
//	Building()
//	{
//		m_livingroom = "livingroom";
//		m_bedroom = "bedroom";
//	}
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
//void goodgay(Building &building)
//{
//	cout << building.m_livingroom << endl;
//	cout << building.m_bedroom << endl;//使其为友元函数后才能访问私有属性
//}
//void test1(void)
//{
//	Building building;
//	goodgay(building);
//}
//int main(void)
//{
//	test1();
//	return 0;
//}
//类作为友元
//class Building;
//class Goodgay
//{
//public:
//	Building* building;
//	Goodgay();
//	void visit();
//};
//class Building
//{
//	friend class Goodgay;//声明Goodgay为友元类，使该类可以访问其私有属性（visit方法）
//public:
//	Building();
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
//Building::Building()
//{
//	m_livingroom = "livingroom";
//	m_bedroom = "bedroom";
//}
//Goodgay::Goodgay()
//{
//	building = new Building;//使用Building类时会调用Building构造函数
//}
//void Goodgay::visit()
//{
//	cout << building->m_livingroom << endl;
//	cout << building->m_bedroom << endl;//访问私有属性
//}
//void test1(void)
//{
//	Goodgay g;//调用Goodgay构造函数
//	g.visit();//调用visit方法
//}
//int main(void)
//{
//	test1();
//	return 0;
//}
//方法作为友元
//class Building;
//class Goodgay
//{
//public:
//	Building* building;
//	Goodgay();
//	void visit(void);
//};
//class Building
//{
//	friend void Goodgay::visit(void);//声明Goodgay的方法visit为友元方法，使其可访问该类的私有属性
//public:
//	Building();
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
////构造函数
//Building::Building()
//{
//	m_livingroom = "livingroom";
//	m_bedroom = "bedroom";
//}
////构造函数
//Goodgay::Goodgay()
//{
//	building = new Building;//使用Building类时会调用Building构造函数
//}
////方法（成员函数）
//void Goodgay::visit()
//{
//	cout << building->m_livingroom << endl;
//	cout << building->m_bedroom << endl;//访问私有属性
//}
//void test1(void)
//{
//	Goodgay g;//调用Goodgay构造函数
//	g.visit();//调用visit方法
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

