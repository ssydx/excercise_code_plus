#pragma once
using namespace std;
#include <fstream>
#include <iostream>
#include <string>

//ofstream ifstream fstream
//�򿪷�ʽ��ios::in ios::out  ios::ate ios::app ios::trunc ios::binary (��Ϸ�ʽ��|)

//�ı��ļ�
//int main(void)
//{
//	//д�ļ�
//	//1����ͷ�ļ�
//
//	//2����������
//	//ofstream ofs;//����һ������
//	////3���ļ���·������ʽ��
//	//ofs.open("text.txt", ios::out);//���ô򿪷���
//	////4д����
//	//ofs << "name: zhangsan" << endl;//����cout
//	//ofs << "sex:  male" << endl;
//	//ofs << "age:  21" << endl;
//	////5�ر��ļ�
//	//ofs.close();
//
//	ifstream ifs;
//	ifs.open("text.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "��ʧ��" << endl;
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
//	//4��������
//	//char c;
//	//while ((c = ifs.get()) != EOF)
//	//{
//	//	cout << c;
//	//}
//	ifs.close();
//
//	return 0;
//}

//�������ļ�
//class Peo
//{
//public:
//	char m_name[64];
//	int m_age;
//};
//int main(void)
//{
//	//д�ļ�
//	//ofstream ofs("peo.txt", ios::out | ios::binary);//��д��
//	////ofstream ofs;
//	////ofs.open("peo.txt", ios::out | ios::binary);
//	//Peo p = { "zhangsan",20 };
//	//ofs.write((const char*)&p, sizeof(Peo));//ע��ת��
//	//ofs.close();
//
//	//���ļ�
//	ifstream ifs("peo.txt", ios::in | ios::binary);
//	if (!ifs.is_open())
//	{
//		cout << "��ʧ��" << endl;
//		return 0;
//	}
//	Peo buf;
//	ifs.read((char*)&buf, sizeof(Peo));
//	cout << "name:" << buf.m_name << " age:" << buf.m_age << endl;
//	ifs.close();
//
//	return 0;
//}