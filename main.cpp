#include<bits/stdc++.h>
using namespace std;
int main()
{	
	cout<<"Input date format:\n  Chess(A5,B3);  or  Chess(A1(B2(;  or  Chess)C5)N5);  or  Chess,E8,A2,;\n";
	int flag=0;
	string s,Chess="Chess";//Chess(A5,B7);
	cin>>s;
	vector<string> str(3);
	for(int i=0;i<s.size()-1;++i)
	{
		if(s[i]=='(' || s[i]==',' || s[i]==')')
		{
			flag++;
			continue;
		}
		str[flag].push_back(s[i]);
	}
	if(s[s.size()-1]!=';')
	{
		cout<<"Error: Expected ';'";
		return 0;
	}
	if(flag>3)
	{
		cout<<"Error: Input data limit exceeded";
		return 1;
	}
	for(int i=0;i<3;++i)
	{
		cout<<str[i]<<"\n";
	}
	
		
	
}
