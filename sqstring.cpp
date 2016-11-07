#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#define Maxsize 1000
using namespace std;

typedef struct SqNode//顺序表的结构
{
	char data[Maxsize];
	int length;
}SqString;

void Encrypt(SqString  &s) //加密
{
	int i=0;
	for(i=0;i<s.length;i++)
	{
		s.data[i]='a'+(s.data[i]-'a'+3)%26;
	}
	return ;
}


void Decipher(SqString &s)  //解密
{
	int i=0;
	for(i=0;i<s.length;i++)
	{
		if(s.data[i]-'a'-3<'a')          //c-‘a’<’a’时考虑加26
			s.data[i]='a'+(s.data[i]+26-'a'-3)%26;
		else
			s.data[i]='a'+(s.data[i]-'a'-3)%26;
		// if(s.data[i]>=97&&s.data[i]<=100)
	}
}

void ShowString(SqString s)//输出
{
	int i;
	for(i=0;i<s.length;i++)
	{
		cout<<s.data[i];
	}
	cout<<endl;
}

void StringInput(SqString &s, char s1[]) //输入
{
	int i=0;
	while(s1[i]!='\0')
	{
		s.data[i]=s1[i];
		// cout<<s.data[i]<<endl;	
		i++;
	}
	s.length=i;
}
int main()
{
	char s1[1000];
	// memset(s1,0,sizeof(s1));
	cin>>s1;
	// cout<<s1<<endl;
	SqString s;
	StringInput(s,s1);	
	// ShowString(s);	
	Encrypt(s);
	// cout<<s<<endl;
	ShowString(s);
	Decipher(s);
	// cout<<s<<endl;
	ShowString(s);


	return 0;
