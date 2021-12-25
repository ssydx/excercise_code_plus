#pragma once
using namespace std;
#include <iostream>
#include <algorithm>
#include <string>

//初始化
void test1(void)
{
	string s1;//默认构造

	const char* str = "hello world";//C风格字符串
	string s5 = "hello world";//C++风格字符串

	string s2(str);//拷贝构造1  拷贝C风格
	cout << "s2 = " << s2 << endl;

	string s3(s5);//拷贝构造2  拷贝C++风格
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');//按个数拷贝字符
	cout << "s4 = " << s4 << endl;

}
//赋值（拷贝）
void test2(void)
{
	//=
	string s1;
	s1 = "hello world";//赋值1
	cout << s1 << endl;

	string s2;
	s2 = s1;//赋值2
	cout << s2 << endl;

	string s3;
	s3 = 'a';//单个字符赋值
	cout << s3 << endl;

	//assign
	string s4;
	s4.assign("hello C++");
	cout << s4 << endl;

	string s5;
	s5.assign("hello C++", 5);//注意不要超过实际字符个数
	cout << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << s6 << endl;

	string s7;
	s7.assign(10, 'a');//按个数拷贝字符
	cout << s7 << endl;
}
//追加
void test3(void)
{
	//+=
	string s1 = "我";
	s1 += "爱C++";
	cout << s1 << endl;

	s1 += ':';
	cout << s1 << endl;

	string s2 = "继承、封装、多态";
	s1 += s2;
	cout << s1 << endl;

	//append
	string s3 = "I";
	s3.append(" love C++aaa", 0, 9);//追加从指定位置开始的指定个数的字符
	cout << s3 << endl;

	s3.append(":aaa", 1);//按个数追加，注意不要超过实际字符个数
	cout << s3 << endl;

	string s4 = " pakage,inherit,polypeptide";
	s3.append(s4);
	cout << s3 << endl;

	string s5 = "!aaa";
	s3.append(s5, 0, 1);//追加从指定位置开始的指定个数的字符
	cout << s3 << endl;
}
//查找
void test4(void)
{
	//find(返回首次出现的位置)
	string s1 = "abcdefgde";
	int pos1 = s1.find("de");//查找到
	cout << pos1 << endl;//输出3
	int pos2 = s1.find("dg");//查找不到
	cout << pos2 << endl;//输出-1(string::npos)

	string s4 = "de";
	int pos8 = s1.find(s4);
	cout << pos8 << endl;

	string s2 = "abcdefgde";
	int pos3 = s2.find("de", 1);//从指定位置开始查找，返回的位置仍然按原字符串
	cout << pos3 << endl;
	int pos4 = s2.find("de", 7);
	cout << pos4 << endl;

	//rfind(返回位置仍是从左往右数)
	string s3 = "abcdefgdef";
	int pos5 = s3.rfind("de", 1);//从指定位置开始从右向左查找，返回的位置仍然按原字符串（从左向右）
	cout << pos5 << endl;//查找不到
	int pos6 = s3.rfind("de", 6);
	cout << pos6 << endl;//输出3
	int pos7 = s3.rfind("de", 9);
	cout << pos7 << endl;//输出7
}
//替换
void test5(void)
{
	string s1 = "abcdegh";
	s1.replace(1, 3, "12345");//把从指定位置起的指定个数的字符替换为其他字符（不限其他字符个数）
	cout << s1 << endl;//输出a12345egh

	string s2 = "11111";
	s1.replace(3, 2, s2);
	cout << s1 << endl;//输出a12111115egh
}
//比较
void test6(void)
{
	string s1 = "hella";
	string s2 = "hello";
	if (!s1.compare(s2))
	{
		cout << "equal" << endl;
	}
	else if (s1.compare(s2) > 0)
	{
		cout << "unequal, the former is larger" << endl;
	}
	else
	{
		cout << "unequal, the latter is larger" << endl;
	}
}
//单个字符的访问修改
void test7(void)
{
	string s1 = "hello";
	//长度
	cout << s1.size() << endl;//无符号数
	cout << s1.length() << endl;//无符号数
	//访问单个字符
	//[]
	for (int i = 0; i < (int)s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	//at
	for (int i = 0; i < (int)s1.size(); i++)
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;
	//修改单个字符
	s1[1] = 'x';
	cout << s1 << endl;
	s1.at(3) = 'y';
	cout << s1 << endl;
}
//增删
void test8(void)
{
	//增加，注意与追加的区别
	string s1 = "hello";
	s1.insert(2, "12345");//从指定位置插入
	cout << s1 << endl;
	//删除
	s1.erase(2, 5);//从指定位置删除指定个数
	cout << s1 << endl;
}
//取子串
void test9(void)
{
	string s1 = "abcdefgh";
	string s2 = s1.substr(3, 3);//获取指定位置起的指定个数的字符
	cout << s2 << endl;

	string email = "zhangsan123@qq.com";
	int pos = email.find("@");
	string name = email.substr(0, pos);
	cout << name << endl;
}

//int main(void)
//{
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	//test7();
//	//test8();
//	test9();
//	return 0;
//}