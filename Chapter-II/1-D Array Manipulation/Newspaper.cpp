#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[10010];
double work(){
		int flag[600]={0};
	int i,n,x,m,j;
	long long int count=0;
	char ch,ch1;
	scanf("%d",&n);
	for (i = 0; i < n; ++	i)
	{
		cin>>ch>>x;
		flag[int(ch)+128]=x;
	}
	scanf("%d",&m);
	cin.ignore();
	for(i=0;i<m;i++){
		cin.getline(str, 100000);
		for (j = 0; j < strlen(str); ++j)
		{
			count=count+flag[int(str[j])+128];
		}
		
	}
	return double(count)/100;
}
int main(){
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i)
	{
		printf("%.2f",work());
		printf("$\n");
	}
	return 0;
}
