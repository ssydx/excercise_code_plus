#pragma once
using namespace std;
#include <iostream>
#include <string>

//��̬��̬��󶨣���̬��̬���
//��̬��̬��ʵ��
//�м̳й�ϵ
//������д������鷽��
//ִ�к������������������û�ָ��

//class Animal
//{
//public:
//	////���ܴﵽ����
//	//void speak()
//	//{
//	//	cout << "������˵��" << endl;
//	//}
//	//�麯��
//	//virtual void speak()
//	//{
//	//	cout << "������˵��" << endl;
//	//}
//	//�麯���ɼ�Ϊ��ʵ��
//	virtual void speak() {};
//};
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//void dospeak(Animal& animal)//����ʹ�����û�ָ��
//{
//	animal.speak();
//}
//int main(void)
//{
//	Cat cat;
//	//dospeak(cat);//���಻��ǿ������ת������ʹ�ø��෽�������������˵��������һ�ֵ�ַ��󶨣�
//	Dog dog;
//	dospeak(cat);
//	dospeak(dog);
//	cout << sizeof(Animal) << endl;//���4����ͬ����ͨ��������ռ��Ĵ�С��,�鷽��������һ��ָ�룬ָ���鷽����
//									//�鷽�����ڴ���鷽���ĵ�ַ�������̳и�ָ��
//									//�������鷽������д���ӷ���������鷽�������鷽�����ڵ��鷽����ַ����Ϊ�ӷ�����ַ
//									//����ͨ����ָ������ӷ���
//									//���ݲ�ͬ�Ĳ�����������󣩵��ò�ͬ���ӷ���
//	cout << sizeof(Cat) << endl;//���4����Ϊ�̳���ָ��
//	return 0;
//}


//��̬ʵ�ּ�����

//һ��ʵ�֣���չ�¹��ܾͱ����޸�Դ�룬���ᳫ
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

//��̬ʵ�֣��ṹ�������ɶ���ǿ��ά������
//class AbstCalc
//{
//public:
//	virtual int GetResult() //virtual����ʡ��
//	{
//		return 0;//����ʡ��
//	};
//	int m_n1;
//	int m_n2;
//};
//class AddCalc:public AbstCalc
//{
//public:
//	virtual int GetResult() //����virtual��ʡ��
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
//	AbstCalc* calc = new AddCalc;//���ö�̬����
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



//���麯���ͳ�����
//ע�ⴿ�麯���ĸ�ʽ��virtual ����ֵ���� ������(�β��б�) = 0;������ֻҪ���Ǹ���ʽ���Ѿ���д��
//ӵ�д��麯������г�����
//�����಻��ʵ��������
//���������д����Ĵ��麯��������Ҳ���ڳ����࣬�޷�ʵ��������

//class Base//������
//{
//public:
//	virtual int Calc() = 0;//���麯��
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

//������Ʒ

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
//		cout << "��ɽȪˮ" << endl;
//	}
//	virtual void Brew(void)
//	{
//		cout << "���ݲ�Ҷ" << endl;
//	}
//	virtual void pour(void)
//	{
//		cout << "���뱭��" << endl;
//	}
//	virtual void put(void)
//	{
//		cout << "�������" << endl;
//	}
//};
//class Coffee
//{
//public:
//	virtual void boil(void)
//	{
//		cout << "�󴿾�ˮ" << endl;
//	}
//	virtual void Brew(void)
//	{
//		cout << "���ݿ���" << endl;
//	}
//	virtual void pour(void)
//	{
//		cout << "���뱭��" << endl;
//	}
//	virtual void put(void)
//	{
//		cout << "����ţ��" << endl;
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



//�������ʹ�����������������Ҳ��ʹ����Ϊ�����ࣩ
//ע�ⴿ������Ҳ��Ҫ���庯��ʵ�֣�ʵ�ַ�������

//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal����" << endl;
//	}
//	//virtual ~Animal()//������
//	//{
//	//	cout << "Animal������" << endl;
//	//}
//	virtual ~Animal() = 0;//��������
//	virtual void speak() = 0;
//};
//Animal::~Animal()
//{
//	cout << "Animal��������" << endl;
//}
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat����" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		if (m_name != NULL)
//		{
//			cout << "Cat����" << endl;
//			delete m_name;
//			m_name = NULL;
//		}
//	}
//	virtual void speak()
//	{
//		cout << *m_name << "Сè��˵��" << endl;
//	}
//	string* m_name;
//};
//int main(void)
//{
//	Animal* animal = new Cat("tom");
//	animal->speak();
//	//����ָ������ʱ��������������������ɶ����ڴ�й©��������������Ϊ���������ɽ��������
//	delete animal;
//	return 0;
//}

//��������
////����
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
////����
//class IntelCPU :public CPU
//{
//	void calc()
//	{
//		cout <<"IntelCPU��ʼ����" << endl;
//	}
//};
//class AmdCPU :public CPU
//{
//	void calc()
//	{
//		cout << "AmdCPU��ʼ����" << endl;
//	}
//};
//class IntelVC :public VC
//{
//	void disp()
//	{
//		cout << "IntelVC��ʼ��ʾ" << endl;
//	}
//};
//class AmdVC :public VC
//{
//	void disp()
//	{
//		cout << "AmdVC��ʼ��ʾ" << endl;
//	}
//};
//class IntelMEM :public MEM
//{
//	void store()
//	{
//		cout << "IntelMEM��ʼ�洢" << endl;
//	}
//};
//class AmdMEM :public MEM
//{
//	void store()
//	{
//		cout << "AmdMEM��ʼ�洢" << endl;
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