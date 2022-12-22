// ChyrunSofia8.1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_08_1.cpp
// < Чирун Софія >
// Лабораторна робота № 8.1.2
// Пошук та заміна символів у літерному рядку рекурсивним способом
// Варіант 18

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* str, int i)
{
	if (strlen(str) < 0)
	   return 0;
	   if (str[i] != 0)
		  if (str[i] == '.')
			 return 1 + Count(str, i + 1);
		  else
			 return Count(str, i + 1);
	   else
		  return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i] != 0)
	{
	   if (str[i] == '.')
	   {
		  strcat(t, "**");
		  return Change(dest, str, t + 2, i + 1);
	   }
	   else
	   {
		  *t++ = str[i++];
		  *t = '\0';
		  return Change(dest, str, t, i);
	   }
	}
	else
	{
	   *t++ = str[i++];
	   *t++ = str[i++];
	   *t = '\0';
	   return dest;
	}
}

int Count4Poit(char* str, int number, int a, int k, int j)
{
	if (strlen(str) < 1)
	   return 0;
	if (a >= 0)
	{
	   if (number < 4) 
	   {
		  cout << ". <4" << endl;
		  return 0;
	   }
	   else 
	   {
		  if (str[a] == '.' && k < 4) 
		  {
			 k++;
			 j = a;				
		  }
		  a--;				
		  return Count4Poit(str, number, a, k, j);
	   }		
	}
	else
	   return j;
}

int main()
{
	char str[101];
	int number, a;
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	number = Count(str,0);
	cout << "String contained " <<  number << " groups of '. >=4' " << endl;
	a = strlen(str);
	cout << "Number i is " << Count4Poit(str, number, a-1, 0, 0)+1 << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}



