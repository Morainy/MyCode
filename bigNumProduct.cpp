#include <iostream>
#include <string>
using namespace std;

string bigNumAdd(string str1 , string str2 , int k)
{
	int overflow;
	int addtemp = 0;
	int str1len = str1.length();
	int str2len = str2.length();
	int i , j;
	overflow = 0;
	for(i = str1len-k , j = str2len-1 ; j >=0 || i >= 0 ;i-- ,j--)
	{
		if(i > 0 && j < 0)
		{
			break;
		}
		else if(i < 0 && j >= 0)
		{
			int temp = overflow + (str2.at(j) - 48);
			overflow = temp /10;
			str1.insert(0 , 1 , temp%10 + 48);
		}
		else
		{
			//addtemp = atoi(str1.at(i)) + atoi(str2.at(j));
			addtemp = (str1.at(i) - 48) + (str2.at(j) -48);
			addtemp = addtemp + overflow;
			overflow = addtemp / 10;
			//str1.at(i) = itoa(addtemp % 10);
			str1.at(i) = addtemp % 10 + 48;
		}
	}
	if(overflow > 0)
	{
		str1.insert(0 , 1 , overflow+48);
	}
	return str1;
}
string bigNumPro(string str1 , string str2)
{
	string strtemp1 , strtemp2;
	int overflow;
	int str1Len , str2Len;
	str1Len = str1.length();
	str2Len = str2.length();
	int k = 1;
	for(int i = str2Len-1 ; i>=0 ;i--)
	{
		//int itemp = atoi(str2.at(i));
		int itemp =str2.at(i) - 48;
		overflow = 0;
		strtemp2.assign("");
		for(int j = str1Len-1 ;j>=0 ; j--)
		{
			//int jtemp = atoi(str1.at(j));
			int jtemp = str1.at(j) - 48;
			int protemp = itemp*jtemp;
			protemp += overflow;
			overflow = protemp/10;
			//strtemp2.insert(0 , 1 , itoa(protemp%10));
			strtemp2.insert(0 , 1 , protemp%10 + 48);
		}
		if(overflow > 0)
		{
			strtemp2.insert(0 , 1 ,overflow + 48);
		}
		//cout<<"strtemp1 = "<<strtemp1<<endl;
		//cout<<"strtemp2 = "<<strtemp2<<endl;
		//strtemp1.insert(0 , 1 ,itoa(0));
		strtemp1 = bigNumAdd(strtemp1 , strtemp2 , k++);
	}
	return strtemp1;
}
int main(int argc, char const *argv[])
{
	string str1 , str2;
	cout<<"Please input the number1:"<<endl;
	while(cin>>str1)
	{
		cout<<"Please input the number2:"<<endl;
		cin>>str2;
		str1 = bigNumPro(str1 , str2);
		cout<< "result = "<<str1<<endl;
		cout<<"Please input the number1:"<<endl;
	}
	//str1 = bigNumAdd(str1 , str2);
	//cout<< "str1 = "<<str1<<endl;
	return 0;
}