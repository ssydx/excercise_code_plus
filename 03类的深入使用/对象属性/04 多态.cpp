#pragma once
using namespace std;
#include <iostream>
#include <string>

//静态多态早绑定，动态多态晚绑定
//动态多态的实现
//有继承关系
//子类重写父类的虚方法
//执行函数传入子类对象的引用或指针

//class Animal
//{
//public:
//	////不能达到所需
//	//void speak()
//	//{
//	//	cout << "动物在说话" << endl;
//	//}
//	//虚函数
//	//virtual void speak()
//	//{
//	//	cout << "动物在说话" << endl;
//	//}
//	//虚函数可简化为空实现
//	virtual void speak() {};
//};
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
//void dospeak(Animal& animal)//必须使用引用或指针
//{
//	animal.speak();
//}
//int main(void)
//{
//	Cat cat;
//	//dospeak(cat);//子类不需强制类型转换即可使用父类方法，输出动物在说话（这是一种地址早绑定）
//	Dog dog;
//	dospeak(cat);
//	dospeak(dog);
//	cout << sizeof(Animal) << endl;//输出4，不同于普通方法（不占类的大小）,虚方法本质是一个指针，指向虚方法表
//									//虚方法表内存放虚方法的地址，子类会继承该指针
//									//当发生虚方法的重写后子方法将替代虚方法，即虚方法表内的虚方法地址被改为子方法地址
//									//进而通过该指针调用子方法
//									//根据不同的参数（子类对象）调用不同的子方法
//	cout << sizeof(Cat) << endl;//输出4，因为继承了指针
//	return 0;
//}


//多态实现计算器

//一般实现，扩展新功能就必须修改源码，不提倡
//class Calc
//{
//public:
//	int GetResult(string ope)
//	{
//		if (ope == "+")
//		{
//			return m_n1 + m_n2;
//		}
//		else if (ope == "-")
//		{
//			return m_n1 - m_n2;
//		}
//		else if(ope == "*")
//		{
//			return m_n1 * m_n2;
//		}
//	}
//	int m_n1;
//	int m_n2;
//};
//int main(void)
//{
//	Calc c;
//	c.m_n1 = 10;
//	c.m_n2 = 20;
//	cout << c.GetResult("+") << endl;
//	cout << c.GetResult("-") << endl;
//	cout << c.GetResult("*") << endl;
//	return 0;
//}

//多态实现，结构清晰，可读性强，维护方便
//class AbstCalc
//{
//public:
//	virtual int GetResult() //virtual不可省略
//	{
//		return 0;//不可省略
//	};
//	int m_n1;
//	int m_n2;
//};
//class AddCalc:public AbstCalc
//{
//public:
//	virtual int GetResult() //子类virtual可省略
//	{
//		return m_n1 + m_n2;
//	};
//};
//class SubCalc :public AbstCalc
//{
//public:
//	virtual int GetResult()
//	{
//		return m_n1 - m_n2;
//	};
//};
//class MulCalc :public AbstCalc
//{
//public:
//	virtual int GetResult()
//	{
//		return m_n1 * m_n2;
//	};
//};
//class DivCalc :public AbstCalc
//{
//public:
//	virtual int GetResult()
//	{
//		return m_n1 / m_n2;
//	}
//};
//int main(void)
//{
//	AbstCalc* calc = new AddCalc;//采用动态分配
//	calc->m_n1 = 10;
//	calc->m_n2 = 20;
//	cout << calc->GetResult() << endl;
//	delete calc;
//	calc = new SubCalc;
//	calc->m_n1 = 10;
//	calc->m_n2 = 20;
//	cout << calc->GetResult() << endl;
//	delete calc;
//	calc = new DivCalc;
//	calc->m_n1 = 20;
//	calc->m_n2 = 7;
//	cout << calc->GetResult() << endl;
//	delete calc;
//	return 0;
//}



//纯虚函数和抽象类
//注意纯虚函数的格式：virtual 返回值类型 函数名(形参列表) = 0;（子类只要不是该形式就已经重写）
//拥有纯虚函数的类叫抽象类
//抽象类不可实例化对象
//子类必须重写父类的纯虚函数，否则也属于抽象类，无法实例化对象

//class Base//抽象类
//{
//public:
//	virtual int Calc() = 0;//纯虚函数
//	int m_a;
//	int m_b;
//};
//class Add:public Base
//{
//public:
//	virtual int Calc()
//	{
//		return m_a + m_b;
//	}
//};
//int main(void)
//{
//	Add add;
//	add.m_a = 10;
//	add.m_b = 20;
//	cout << add.Calc() << endl;
//	return 0;
//}

//制作饮品

//class Cre
//{
//public:
//	virtual void boil(void) = 0;
//	virtual void Brew(void) = 0;
//	virtual void pour(void) = 0;
//	virtual void put(void) = 0;
//	void make()
//	{
//		boil();
//		Brew();
//		pour();
//		put();
//	}
//};
//class Tea
//{
//public:
//	virtual void boil(void)
//	{
//		cout << "煮山泉水" << endl;
//	}
//	virtual void Brew(void)
//	{
//		cout << "冲泡茶叶" << endl;
//	}
//	virtual void pour(void)
//	{
//		cout << "倒入杯中" << endl;
//	}
//	virtual void put(void)
//	{
//		cout << "加入蜂蜜" << endl;
//	}
//};
//class Coffee
//{
//public:
//	virtual void boil(void)
//	{
//		cout << "煮纯净水" << endl;
//	}
//	virtual void Brew(void)
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	virtual void pour(void)
//	{
//		cout << "倒入杯中" << endl;
//	}
//	virtual void put(void)
//	{
//		cout << "加入牛奶" << endl;
//	}
//};
//void dowork(Cre* cre)
//{
//	cre->make();
//	delete cre;
//}
//int main(void)
//{
//	
//	dowork((Cre*)new Coffee);
//	cout << "-----------------------" << endl;
//	dowork((Cre*)new Tea);
//	return 0;
//}



//虚析构和纯虚析构（纯虚析构也会使该类为抽象类）
//注意纯虚析构也需要具体函数实现，实现放在类外

//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造" << endl;
//	}
//	//virtual ~Animal()//虚析构
//	//{
//	//	cout << "Animal虚析构" << endl;
//	//}
//	virtual ~Animal() = 0;//纯虚析构
//	virtual void speak() = 0;
//};
//Animal::~Animal()
//{
//	cout << "Animal纯虚析构" << endl;
//}
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat构造" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		if (m_name != NULL)
//		{
//			cout << "Cat析构" << endl;
//			delete m_name;
//			m_name = NULL;
//		}
//	}
//	virtual void speak()
//	{
//		cout << *m_name << "小猫在说话" << endl;
//	}
//	string* m_name;
//};
//int main(void)
//{
//	Animal* animal = new Cat("tom");
//	animal->speak();
//	//父类指针析构时不会调用子类的析构，造成堆区内存泄漏，将父类析构改为虚析构即可解决该问题
//	delete animal;
//	return 0;
//}

//制作电脑
////抽象
//class CPU
//{
//public:
//	virtual void calc() = 0;
//};
//class VC
//{
//public:
//	virtual void disp() = 0;
//};
//class MEM
//{
//public:
//	virtual void store() = 0;
//};
//class Comp
//{
//public:
//	Comp(CPU* cpu, VC* vc, MEM* mem)
//	{
//		m_cpu = cpu;
//		m_vc = vc;
//		m_mem = mem;
//	}
//	void work(void)
//	{
//		m_cpu->calc();
//		m_vc->disp();
//		m_mem->store();
//	}
//	~Comp()
//	{
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		if (m_vc != NULL)
//		{
//			delete m_vc;
//			m_vc = NULL;
//		}
//		if (m_mem != NULL)
//		{
//			delete m_mem;
//			m_mem = NULL;
//		}
//	}
//private:
//	CPU* m_cpu;
//	VC* m_vc;
//	MEM* m_mem;
//};
////具体
//class IntelCPU :public CPU
//{
//	void calc()
//	{
//		cout <<"IntelCPU开始计算" << endl;
//	}
//};
//class AmdCPU :public CPU
//{
//	void calc()
//	{
//		cout << "AmdCPU开始计算" << endl;
//	}
//};
//class IntelVC :public VC
//{
//	void disp()
//	{
//		cout << "IntelVC开始显示" << endl;
//	}
//};
//class AmdVC :public VC
//{
//	void disp()
//	{
//		cout << "AmdVC开始显示" << endl;
//	}
//};
//class IntelMEM :public MEM
//{
//	void store()
//	{
//		cout << "IntelMEM开始存储" << endl;
//	}
//};
//class AmdMEM :public MEM
//{
//	void store()
//	{
//		cout << "AmdMEM开始存储" << endl;
//	}
//};
//int main(void)
//{
//	CPU* intelcpu = new IntelCPU;
//	VC* intelvc = new IntelVC;
//	MEM* intelmem = new IntelMEM;
//	Comp* comp1 = new Comp(intelcpu, intelvc, intelmem);
//	comp1->work();
//	delete comp1;
//	cout << "++++++++++++++++++" << endl;
//	CPU* intelcpu1 = new AmdCPU;
//	VC* intelvc1 = new AmdVC;
//	MEM* intelmem1 = new AmdMEM;
//	Comp* comp2 = new Comp(intelcpu1, intelvc1, intelmem1);
//	comp2->work();
//	delete comp2;
//	cout << "++++++++++++++++++" << endl;
//	Comp* comp3 = new Comp(new IntelCPU, new AmdVC, new IntelMEM);
//	comp3->work();
//	delete comp3;
//
//	return 0;
//}