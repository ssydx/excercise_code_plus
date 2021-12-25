#pragma once
using namespace std;
#include <iostream>
#include <algorithm>
#include <string>

//��ʼ��
void test1(void)
{
	string s1;//Ĭ�Ϲ���

	const char* str = "hello world";//C����ַ���
	string s5 = "hello world";//C++����ַ���

	string s2(str);//��������1  ����C���
	cout << "s2 = " << s2 << endl;

	string s3(s5);//��������2  ����C++���
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');//�����������ַ�
	cout << "s4 = " << s4 << endl;

}
//��ֵ��������
void test2(void)
{
	//=
	string s1;
	s1 = "hello world";//��ֵ1
	cout << s1 << endl;

	string s2;
	s2 = s1;//��ֵ2
	cout << s2 << endl;

	string s3;
	s3 = 'a';//�����ַ���ֵ
	cout << s3 << endl;

	//assign
	string s4;
	s4.assign("hello C++");
	cout << s4 << endl;

	string s5;
	s5.assign("hello C++", 5);//ע�ⲻҪ����ʵ���ַ�����
	cout << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << s6 << endl;

	string s7;
	s7.assign(10, 'a');//�����������ַ�
	cout << s7 << endl;
}
//׷��
void test3(void)
{
	//+=
	string s1 = "��";
	s1 += "��C++";
	cout << s1 << endl;

	s1 += ':';
	cout << s1 << endl;

	string s2 = "�̳С���װ����̬";
	s1 += s2;
	cout << s1 << endl;

	//append
	string s3 = "I";
	s3.append(" love C++aaa", 0, 9);//׷�Ӵ�ָ��λ�ÿ�ʼ��ָ���������ַ�
	cout << s3 << endl;

	s3.append(":aaa", 1);//������׷�ӣ�ע�ⲻҪ����ʵ���ַ�����
	cout << s3 << endl;

	string s4 = " pakage,inherit,polypeptide";
	s3.append(s4);
	cout << s3 << endl;

	string s5 = "!aaa";
	s3.append(s5, 0, 1);//׷�Ӵ�ָ��λ�ÿ�ʼ��ָ���������ַ�
	cout << s3 << endl;
}
//����
void test4(void)
{
	//find(�����״γ��ֵ�λ��)
	string s1 = "abcdefgde";
	int pos1 = s1.find("de");//���ҵ�
	cout << pos1 << endl;//���3
	int pos2 = s1.find("dg");//���Ҳ���
	cout << pos2 << endl;//���-1(string::npos)

	string s4 = "de";
	int pos8 = s1.find(s4);
	cout << pos8 << endl;

	string s2 = "abcdefgde";
	int pos3 = s2.find("de", 1);//��ָ��λ�ÿ�ʼ���ң����ص�λ����Ȼ��ԭ�ַ���
	cout << pos3 << endl;
	int pos4 = s2.find("de", 7);
	cout << pos4 << endl;

	//rfind(����λ�����Ǵ���������)
	string s3 = "abcdefgdef";
	int pos5 = s3.rfind("de", 1);//��ָ��λ�ÿ�ʼ����������ң����ص�λ����Ȼ��ԭ�ַ������������ң�
	cout << pos5 << endl;//���Ҳ���
	int pos6 = s3.rfind("de", 6);
	cout << pos6 << endl;//���3
	int pos7 = s3.rfind("de", 9);
	cout << pos7 << endl;//���7
}
//�滻
void test5(void)
{
	string s1 = "abcdegh";
	s1.replace(1, 3, "12345");//�Ѵ�ָ��λ�����ָ���������ַ��滻Ϊ�����ַ������������ַ�������
	cout << s1 << endl;//���a12345egh

	string s2 = "11111";
	s1.replace(3, 2, s2);
	cout << s1 << endl;//���a12111115egh
}
//�Ƚ�
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
//�����ַ��ķ����޸�
void test7(void)
{
	string s1 = "hello";
	//����
	cout << s1.size() << endl;//�޷�����
	cout << s1.length() << endl;//�޷�����
	//���ʵ����ַ�
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
	//�޸ĵ����ַ�
	s1[1] = 'x';
	cout << s1 << endl;
	s1.at(3) = 'y';
	cout << s1 << endl;
}
//��ɾ
void test8(void)
{
	//���ӣ�ע����׷�ӵ�����
	string s1 = "hello";
	s1.insert(2, "12345");//��ָ��λ�ò���
	cout << s1 << endl;
	//ɾ��
	s1.erase(2, 5);//��ָ��λ��ɾ��ָ������
	cout << s1 << endl;
}
//ȡ�Ӵ�
void test9(void)
{
	string s1 = "abcdefgh";
	string s2 = s1.substr(3, 3);//��ȡָ��λ�����ָ���������ַ�
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