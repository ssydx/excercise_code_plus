#include <iostream>
using namespace std;
#include <string>

//�ڴ�ķ���ģ��
//���������Դ���루ֻ������
//ȫ������ž�̬����ȫ�ֱ���������������ϵͳ����
//ջ����žֲ����������βΣ�����������
//�����ɳ���Ա���й���

//��������ؼ���

//int* mem_alloc_i()
//{
//	int* p = new int(10);
//	return p;
//}
//int* mem_alloc_arr()
//{
//	int* p = new int[10];
//	return p;
//}
//int main(void)
//{
//	int* i = mem_alloc_i();
//	cout << *i << endl;
//	delete i;//�ͷ��ڴ�
//	int* arr = mem_alloc_arr();
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i]<<" ";
//	}
//	delete[] arr;//ע���ͷ�����ʱ���﷨
//	return 0;
//}

//����&
//һ���̶����൱��typedef�����������������������չ�������������
//���ñ����ʼ��
//�����ڳ�ʼ����Ͳ��ɸ���
//��Ҫ���ؾֲ�����������
//���ñ�����ָ��ļ�д��
//����ֵΪ�������͵ĺ�������Ϊ��ֵ��ע�ⷵ�ص����õ�ԭ��Ӧ����Ϊ��̬������

//void swap(int &a, int &b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
////int& test()//�Ƿ�����
////{
////	int a = 10;
////	return a;
////}
//int& test2()
//{
//	static int num = 30;
//	return num;
//}
////int test3()//�Ƿ�����
////{
////	static int num = 15;
////	return num;
////}
//void show(const int& num)
//{
//	//num = 1000;//const���κ�ͱ����˷Ƿ����޸Ĳ���
//	cout << num << endl;
//}
//int main(void)
//{
//	//int a = 10;
//	//int& b = a;
//	//cout << a << endl;
//	//cout << b << endl;
//	//b = 20;
//	//cout << a << endl;
//	//cout << b << endl;
//
//	//int& c;//δ��ʼ��
//	//int c = 20;
//	//b = c;//���Ǹ�ֵ�����Ǹ�������
//
//	//int x = 10;
//	//int y = 20;
//	//swap(x, y);//�������ý��н���
//	//cout << x << endl;
//	//cout << y << endl;
//
//	//int& ret = test();
//	//cout << ret << endl;//����������һ�Σ�����״������ȷ
//	//cout << ret << endl;//�ڶ��ν������ֵ����˲�Ҫ���ؾֲ�����������
//
//	//int& ret = test2();
//	//cout << ret << endl;
//	//cout << ret << endl;
//	//test2() = 100;//��Ϊ��ֵʹ��
//	//int& ret2 = test2();
//	//cout << ret2 << endl;
//
//	//int a = 10;
//	////int& ret = 10;//����ֱ�����ó���
//	//const int& ret = 10;//��������const���ó���
//	////ret = 20;//const���κ󲻿ɸ���
//	//int b = 100;
//	//show(b);
//
//	return 0;
//}

//�������ؼ�����
//Ĭ�ϲ���ֻ���ڶ���������е�һ������
//�����൱��const���ε�����
//���ز�Ҫ��Ĭ�ϲ���ͬʱʹ��

////��ͨ����
//int func(int x, int y, int z)
//{
//	return x + y + z;
//}
////��Ĭ�ϲ����ĺ�����ĳ������Ĭ��ֵ��֮����Ĭ��ֵ��ʵ���ǰ�˳�򴫵ģ���Ĭ��ֵ�Ĳ������Բ���ʵ��
////���������뺯�����岻��ͬʱ����Ĭ�ϲ�������������Ĭ�ϲ�������������Ĭ��ֵ������������û��
//int func1(int x, int y = 20, int z = 30)
//{
//	return x + y + z;
//}
////ռλ��������������ֻд�������͵Ĳ��������봫�ݸ��������͵�ʵ�Σ�������ʹ��
////ռλ����Ҳ������Ĭ�ϲ�������int = 10;
//void func2(int x,int)
//{
//	cout << "ռλ����\n";
//	cout << x << endl;
//}
////�������أ�ͬһ�������򣬺�������ͬ���ββ�ͬ��������ͬ�����Ͳ�ͬ��˳��ͬ��
////ע�⺯������ֵ���Ͳ�����Ϊ�������ص�����
//void fun(void)
//{
//	cout << "fun" << endl;
//}
//void fun(int x)
//{
//	cout << "fun(int x)" << endl;
//}
//void fun(int x, int y)
//{
//	cout << "fun(int x,int y)" << endl;
//}
//void fun(int x, float y)
//{
//	cout << "fun(int x,float y)" << endl;
//}
//void fun(float y, int x)
//{
//	cout << "fun(float y,int x)" << endl;
//}
////����������
//void function(int& x)
//{
//	cout << "function(int& x)" << endl;
//}
//void function(const int& x)
//{
//	cout << "function(const int& x)" << endl;
//}
////Ĭ�ϲ���������
//void function1(int x, int y = 10)
//{
//	cout << "function1(int x,int y=10)" << endl;
//}
//void function1(int x)
//{
//	cout << "function1(int x)" << endl;
//}
//
//int func1(int x, int y, int z);//����û��Ĭ�ϲ���
//int main(void)
//{
//	//Ĭ�ϲ���
//	cout << func(10, 20, 30) << endl;//���60
//	cout << func1(10) << endl;//���60����Ĭ�ϲ������Բ���ʵ��
//	cout << func1(10, 20) << endl;//���60����˳��
//	cout << func1(10, 30) << endl;//���70����˳��
//	cout << func1(10, 20, 30) << endl;//���60��Ҳ����ȫ������
//
//	func2(10,20);//ռλ����
//
//	//��������
//	fun();//�����޲ΰ汾
//	fun(10);//����һ�����Ͳ����汾
//	fun(10, 20);//�����������Ͳ����汾
//	fun(10, 3.14f);//���õ�һ�����ͣ��ڶ��������Ͱ汾
//	fun(3.14f, 10);//���õ�һ�������ͣ��ڶ������Ͱ汾
//
//	//������Ϊ������������
//	int a = 10;
//	const int b = 10;
//	function(a);//����int& x�汾
//	function(b);//����const int& x�汾
//	function(10);//����const int& x�汾
//
//	//����������Ĭ�ϲ��������߾�����Ҫͬʱʹ��
//	//function1(10);//�����У��ɵ��ö��
//	function1(10, 20);//ֻ�ܵ���һ��
//
//	return 0;
//}
