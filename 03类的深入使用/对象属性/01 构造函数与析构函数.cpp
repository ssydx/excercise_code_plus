#pragma once
using namespace std;
#include <iostream>

//���ֱ��ʹ�����ʶ��

//���캯���������������������캯����
//������Ĭ�Ͼ��У�Ĭ�Ϲ���Ĭ������������Ϊ��ʵ�֣���������Ĭ�Ͻ������Կ�����
//���캯��������������û�з�������
//���캯�������в�������������û�в���
//���캯����Ϊ��������������Ϊ������~
//�Զ��幹�����������Ҫ���ڹ���Ȩ����
//ϵͳ�Զ����ã���������ʱ���ù��캯���������ͷ�ʱ������������
//���캯����Ϊ�޲ι�����вι��죬Ҳ��Ϊ��ͨ����Ϳ�������
//���ù��캯�������ַ��������ŷ�����ʾ������ʽת����
//�������캯���ĵ���ʱ����������֪��������ʼ���¶���
//ֵ���ݷ�ʽ���Σ�ֵ���ؾֲ�����
//���û������вι���������������ṩĬ���޲ι��죬���ṩĬ�Ͽ�������
//����û����忽�����캯�������ṩ���캯��

//class Peo
//{
//public:
//	//���캯��
//	Peo()
//	{
//		cout << "Peo ���캯������" << endl;
//	}
//	Peo(int a)
//	{
//		age = a;
//		cout << "Peo �вι������" << endl;
//	}
//	Peo(const Peo &p)//ʹ��const������
//	{
//		age = p.age;
//		cout << "Peo �����������" << endl;
//	}
//	//��������
//	~Peo()
//	{
//		cout << "Peo ������������" << endl;
//	}
//public:
//	int getage(void)
//	{
//		return age;
//	}
//private:
//	int age;
//};
//void test01()//��ʼ�����ÿ������캯��
//{
//	Peo p;//�޲ι��첻Ҫ�����ű��������������������
//	Peo p1(10);
//	Peo p2(p1);
//	//Peo p1 = Peo(10);//��ʾ��
//	//Peo p2 = Peo(p1);��ʾ��
//	//Peo(10);������������вι��캯��������������������������������
//	//Peo(p2);���������޷����ÿ������캯���������������ΪPeo p2;
//	//Peo p4 = 10;��ʽת����
//	//Peo p5 = p4;��ʽת����
//	cout << p1.getage() << endl;//���10
//	cout << p2.getage() << endl;//���10
//}
//void dowork(Peo p)//ֵ���ݵ��ÿ������캯��
//{
//
//}
//void test02()
//{
//	Peo pd;
//	dowork(pd);
//}
//Peo dowork2(void)//ֵ���ص��ÿ������캯��
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

//�����ǳ����
//�����ڿ����ڶ����ĳ�ԱʱҪ�Զ���������캯�����Ӷ�����Ĭ��ǳ������ɵ��ظ��ͷ��ڴ������
//class Peo
//{
//public:
//	//Ĭ�Ϲ���
//	Peo()
//	{
//		cout << "Peo Ĭ�Ϲ���" << endl;
//	}
//	//�вι���
//	Peo(int age,int height)
//	{
//		m_age = age;
//		m_height = new int(height);
//		cout << "Peo �вι���" << endl;
//	}
//	//��������
//	Peo(const Peo& p)
//	{
//		m_age = p.m_age;
//		//m_height = p.m_height;//Ĭ�ϵ�ǳ����
//		m_height = new int(*p.m_height);//�Զ�������
//		cout << "Peo �Ŀ�������" << endl;
//	}
//	//��������
//	~Peo()
//	{
//		if (m_height != NULL)//Ĭ�Ͽ������캯��ʹ��ͬ��m_heightָ��ͬһ���ڴ棬�ͷſռ�ʱ�ᵼ���ظ��ͷ�
//		{
//			delete m_height;
//			m_height = NULL;
//		}
//		cout << "Peo ����" << endl;
//	}
//	int m_age;
//	int* m_height;
//};
//void test1()
//{
//	Peo p1(18, 160);
//	cout << p1.m_age << endl;
//	cout << *p1.m_height << endl;
//	Peo p2(p1);//�������ṩ��Ĭ�Ͽ������캯��
//	cout << p2.m_age << endl;
//	cout << *p2.m_height << endl;
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

//��ʼ���б�
//class Peo
//{
//public:
//	//���캯������ֵ
//	//Peo(int x, int y, int z)
//	//{
//	//	m_x = x;
//	//	m_y = y;
//	//	m_z = z;
//	//}
//	//��ʼ���б���ֵ���̶�ֵ
//	//Peo():m_x(10),m_y(20),m_z(30)
//	//{
//
//	//}
//	//����ֵ
//	Peo(int x,int y,int z) :m_x(x), m_y(y), m_z(z)//�൱��Peo m_x =x����ʽת������
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

//�������Ϊ���Աʱ�ȹ���������ٹ�����࣬����ʱ�෴
//class A
//{
//public:
//	A()
//	{
//		cout << "A �Ĺ���" << endl;
//	}
//	~A()
//	{
//		cout << "A ������" << endl;
//	}
//};
//class B
//{
//public:
//	B()
//	{
//		cout << "B �Ĺ���" << endl;
//	}
//	~B()
//	{
//		cout << "B ������" << endl;
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

//��̬�����뾲̬����
//��̬���Ժ;�̬���������ж���������������������ֱ�ӵ���
//��̬���ԺͶ�̬����ֻ���ɶ������
//��̬����ֻ�ܷ��ʾ�̬���ԣ���̬�������Է��ʶ���̬����
//��̬����ֻ���ɶ�̬��������
//��̬������س�ʼ��
//��̬�����������ʼ�� ���� ������::������=����ֵ
//class Peo
//{
//public:
//	void func1(void)
//	{
//		m_height = 170;
//		m_age = 100;
//		cout << "void func1(void)" << endl;
//	}
//	//��̬����
//	static void func(void)
//	{
//		m_age = 20;
//		//m_height = 170;�Ǿ�̬���Բ����ɾ�̬��������
//		cout << "static void func(void)" << endl;
//	}
//	//��̬����
//	static int m_age;
//	int m_height;
//};
////��̬����Ҫ�����ʼ��
//int Peo::m_age = 10;
//void test1(void)
//{
//	////��̬
//	//Peo p;
//	////ͨ��������ʾ�̬����
//	//cout << p.m_age << endl;//���10
//	////ͨ������ʾ�̬����
//	//cout << Peo::m_age << endl;
//	////ͨ��������ʾ�̬����
//	//Peo p1;
//	//p1.func();
//	////ͨ���ࣨ�����򣩷��ʾ�̬����
//	//Peo::func();
//	//cout << p1.m_age << endl;//���20
//
//	//��̬
//	//Peo p2;
//	//ͨ��������ʶ�̬����
//	//cout << p2.m_height << endl;m_heightδ��ʼ������ʹ��
//	//ͨ������ʶ�̬����
//	//cout << Peo::m_height << endl;��̬���Բ����������
//	//ͨ��������ʶ�̬����
//	Peo p3;
//	p3.func1();
//	//ͨ���ࣨ�����򣩷��ʶ�̬����
//	//Peo::func1();��̬���������������
//	cout << p3.m_age << endl;//���100
//	cout << p3.m_height << endl;//���170
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

//���С
//�����СΪ1���սṹ��Ҳ��1�������C��ͬ
//���������������С����̬����Ҳ�����������С
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
//	cout << sizeof(S) << endl;//���4
//	cout << sizeof(s) << endl;//���4
//	return 0;
//}

//this ָ��
//��ָ��ָ����÷����Ķ��������ڷ����ڣ�����Ҫ��ʽ����
//ͨ��thisָ������ÿ��ҵ�����
//class Peo
//{
//public:
//	Peo(int age)
//	{
//		//m_age = age;
//		this->age = age;
//	}
//	//һ��׷��
//	void PeoAddAge(Peo& p)
//	{
//		this->age += p.age;
//	}
//	//��ʽ׷��
//	//���������÷�ʽ����
//	Peo& PeoAddAgePlus(Peo& p)
//	{
//		this->age += p.age;
//		return *this;//���ص�ǰ����
//	}
//	//int m_age;
//	int age;
//};
//void test1(void)
//{
//	Peo p1(21);
//	//cout << p1.m_age << endl;
//	cout << p1.age << endl;//���10
//}
//void test2(void)
//{
//	Peo p1(10);
//	Peo p2(10);
//	p2.PeoAddAge(p1);
//	cout << p2.age << endl;//���20
//
//	p2.PeoAddAgePlus(p1).PeoAddAgePlus(p1).PeoAddAgePlus(p1);
//	cout << p2.age << endl;//���50
//}
//int main(void)
//{
//	//test1();
//	test2();
//	return 0;
//}

//��ָ����÷��������������Եķ�����
//class Peo
//{
//public:
//	void ShowClassName()
//	{
//		cout << "this is Peo class" << endl;
//	}
//	void ShowPeoAge()
//	{
//		//�����ָ�뵼�µĴ���
//		if (this == NULL)
//		{
//			return;
//		}
//		cout << "age = " << m_age << endl;//���ʵ�ǰ�����m_age
//	}
//	int m_age;
//};
//void test1(void)
//{
//	Peo* p = NULL;
//	p->ShowClassName();//���Ե��ò��������Եķ���
//	p->ShowPeoAge();//��ָ�벻�ɵ��÷������Եķ���
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

//const���εķ���:�ڳ�Ա�������ź��const��ʵ��������thisָ�룬ʹ��ָ��Ķ��󲻿��޸ģ������޸���Ҫ�ڶ�Ӧ����ǰ��mutable
//this ָ������� Peo* const this��ָ�뱾�����޸�
//class Peo
//{
//public:
//	void ShowPeo(void) const//������
//	{
//		//this->m_a = 10;//�����޸�
//		this->m_b = 100;
//	}
//	void func(void)
//	{
//
//	}
//	int m_a;
//	mutable int m_b;//ʹ��ɱ��������򳣶����޸�
//};
//void test1(void)
//{
//	Peo p;
//	p.ShowPeo();
//}
//void test2(void)
//{
//	const Peo p;
//	//p.m_a = 10;//�����޸�
//	p.m_b = 100;
//	p.ShowPeo();
//	//p.func();�������ܵ�����ͨ����
//}
//int main(void)
//{
//	test1();
//	test2();
//	return 0;
//}

//��Ԫ
////ȫ�ֺ�����Ϊ��Ԫ
//class Building
//{
//	friend void goodgay(Building& building);//����ȫ�ֺ���goodgayΪ��Ԫ����
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
//	cout << building.m_bedroom << endl;//ʹ��Ϊ��Ԫ��������ܷ���˽������
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
//����Ϊ��Ԫ
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
//	friend class Goodgay;//����GoodgayΪ��Ԫ�࣬ʹ������Է�����˽�����ԣ�visit������
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
//	building = new Building;//ʹ��Building��ʱ�����Building���캯��
//}
//void Goodgay::visit()
//{
//	cout << building->m_livingroom << endl;
//	cout << building->m_bedroom << endl;//����˽������
//}
//void test1(void)
//{
//	Goodgay g;//����Goodgay���캯��
//	g.visit();//����visit����
//}
//int main(void)
//{
//	test1();
//	return 0;
//}
//������Ϊ��Ԫ
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
//	friend void Goodgay::visit(void);//����Goodgay�ķ���visitΪ��Ԫ������ʹ��ɷ��ʸ����˽������
//public:
//	Building();
//public:
//	string m_livingroom;
//private:
//	string m_bedroom;
//};
////���캯��
//Building::Building()
//{
//	m_livingroom = "livingroom";
//	m_bedroom = "bedroom";
//}
////���캯��
//Goodgay::Goodgay()
//{
//	building = new Building;//ʹ��Building��ʱ�����Building���캯��
//}
////��������Ա������
//void Goodgay::visit()
//{
//	cout << building->m_livingroom << endl;
//	cout << building->m_bedroom << endl;//����˽������
//}
//void test1(void)
//{
//	Goodgay g;//����Goodgay���캯��
//	g.visit();//����visit����
//}
//int main(void)
//{
//	test1();
//	return 0;
//}

