#include <iostream>
using namespace std;
#include <string>

//内存的分区模型
//代码区存放源代码（只读共享）
//全局区存放静态变量全局变量及常量（操作系统管理）
//栈区存放局部变量函数形参（编译器管理）
//堆区由程序员自行管理

//堆区管理关键字

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
//	delete i;//释放内存
//	int* arr = mem_alloc_arr();
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i]<<" ";
//	}
//	delete[] arr;//注意释放数组时的语法
//	return 0;
//}

//引用&
//一定程度上相当于typedef（给数据类型起别名）的扩展，给变量起别名
//引用必须初始化
//引用在初始化后就不可更改
//不要返回局部变量的引用
//引用本质是指针的简化写法
//返回值为引用类型的函数可作为左值（注意返回的引用的原型应该作为静态变量）

//void swap(int &a, int &b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
////int& test()//非法操作
////{
////	int a = 10;
////	return a;
////}
//int& test2()
//{
//	static int num = 30;
//	return num;
//}
////int test3()//非法操作
////{
////	static int num = 15;
////	return num;
////}
//void show(const int& num)
//{
//	//num = 1000;//const修饰后就避免了非法的修改操作
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
//	//int& c;//未初始化
//	//int c = 20;
//	//b = c;//这是赋值而不是更改引用
//
//	//int x = 10;
//	//int y = 20;
//	//swap(x, y);//利用引用进行交换
//	//cout << x << endl;
//	//cout << y << endl;
//
//	//int& ret = test();
//	//cout << ret << endl;//编译器保留一次，因此首次输出正确
//	//cout << ret << endl;//第二次将是随机值，因此不要返回局部变量的引用
//
//	//int& ret = test2();
//	//cout << ret << endl;
//	//cout << ret << endl;
//	//test2() = 100;//作为左值使用
//	//int& ret2 = test2();
//	//cout << ret2 << endl;
//
//	//int a = 10;
//	////int& ret = 10;//不可直接引用常量
//	//const int& ret = 10;//可以利用const引用常量
//	////ret = 20;//const修饰后不可更改
//	//int b = 100;
//	//show(b);
//
//	return 0;
//}

//函数重载及其他
//默认参数只能在定义或声明中的一个出现
//常量相当于const修饰的类型
//重载不要与默认参数同时使用

////普通函数
//int func(int x, int y, int z)
//{
//	return x + y + z;
//}
////带默认参数的函数，某参数有默认值则之后都是默认值，实参是按顺序传的，有默认值的参数可以不传实参
////函数声明与函数定义不可同时具有默认参数，即定义有默认参数则声明不加默认值，声明有则定义没有
//int func1(int x, int y = 20, int z = 30)
//{
//	return x + y + z;
//}
////占位参数，函数定义只写数据类型的参数，必须传递该数据类型的实参，但并不使用
////占位参数也可以是默认参数，如int = 10;
//void func2(int x,int)
//{
//	cout << "占位参数\n";
//	cout << x << endl;
//}
////函数重载：同一个作用域，函数名相同，形参不同（个数不同，类型不同，顺序不同）
////注意函数返回值类型不能作为函数重载的条件
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
////引用与重载
//void function(int& x)
//{
//	cout << "function(int& x)" << endl;
//}
//void function(const int& x)
//{
//	cout << "function(const int& x)" << endl;
//}
////默认参数与重载
//void function1(int x, int y = 10)
//{
//	cout << "function1(int x,int y=10)" << endl;
//}
//void function1(int x)
//{
//	cout << "function1(int x)" << endl;
//}
//
//int func1(int x, int y, int z);//声明没有默认参数
//int main(void)
//{
//	//默认参数
//	cout << func(10, 20, 30) << endl;//输出60
//	cout << func1(10) << endl;//输出60，有默认参数可以不传实参
//	cout << func1(10, 20) << endl;//输出60，按顺序
//	cout << func1(10, 30) << endl;//输出70，按顺序
//	cout << func1(10, 20, 30) << endl;//输出60，也可以全部传参
//
//	func2(10,20);//占位参数
//
//	//函数重载
//	fun();//调用无参版本
//	fun(10);//调用一个整型参数版本
//	fun(10, 20);//调用两个整型参数版本
//	fun(10, 3.14f);//调用第一个整型，第二个浮点型版本
//	fun(3.14f, 10);//调用第一个浮点型，第二个整型版本
//
//	//引用作为函数重载条件
//	int a = 10;
//	const int b = 10;
//	function(a);//调用int& x版本
//	function(b);//调用const int& x版本
//	function(10);//调用const int& x版本
//
//	//函数重载与默认参数，两者尽量不要同时使用
//	//function1(10);//不可行，可调用多个
//	function1(10, 20);//只能调用一个
//
//	return 0;
//}
