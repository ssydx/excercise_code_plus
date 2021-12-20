#pragma once
using namespace std;
#include <fstream>
#include <iostream>
#include <string>

//ofstream ifstream fstream
//打开方式：ios::in ios::out  ios::ate ios::app ios::trunc ios::binary (组合方式用|)

//文本文件
//int main(void)
//{
//	//写文件
//	//1包含头文件
//
//	//2创建流对象
//	//ofstream ofs;//创建一个对象
//	////3打开文件（路径、方式）
//	//ofs.open("text.txt", ios::out);//调用打开方法
//	////4写数据
//	//ofs << "name: zhangsan" << endl;//类似cout
//	//ofs << "sex:  male" << endl;
//	//ofs << "age:  21" << endl;
//	////5关闭文件
//	//ofs.close();
//
//	ifstream ifs;
//	ifs.open("text.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "打开失败" << endl;
//		return 0;
//	}
//	//1
//	//char buf[1024] = { 0 };
//	//while (ifs >> buf)
//	//{
//	//	cout << buf << endl;
//	//}
//	//2
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//	//3
//	string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//	}
//	//4，不建议
//	//char c;
//	//while ((c = ifs.get()) != EOF)
//	//{
//	//	cout << c;
//	//}
//	ifs.close();
//
//	return 0;
//}

//二进制文件
//class Peo
//{
//public:
//	char m_name[64];
//	int m_age;
//};
//int main(void)
//{
//	//写文件
//	//ofstream ofs("peo.txt", ios::out | ios::binary);//简化写法
//	////ofstream ofs;
//	////ofs.open("peo.txt", ios::out | ios::binary);
//	//Peo p = { "zhangsan",20 };
//	//ofs.write((const char*)&p, sizeof(Peo));//注意转换
//	//ofs.close();
//
//	//读文件
//	ifstream ifs("peo.txt", ios::in | ios::binary);
//	if (!ifs.is_open())
//	{
//		cout << "打开失败" << endl;
//		return 0;
//	}
//	Peo buf;
//	ifs.read((char*)&buf, sizeof(Peo));
//	cout << "name:" << buf.m_name << " age:" << buf.m_age << endl;
//	ifs.close();
//
//	return 0;
//}