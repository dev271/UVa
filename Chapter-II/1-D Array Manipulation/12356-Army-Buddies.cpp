#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int left1[100010];
int right1[100010];
void work(int s,int b){	
	int i,j,l,r,k;
	for (int o = 1; o <= s; ++o)		
	{
		left1[o]=o-1;
		right1[o]=o+1;
	}
	for(i=0;i<b;i++){
			scanf("%d",&l);
			scanf("%d",&r);
			left1[right1[r]]=left1[l];
			right1[left1[l]]=right1[r];
			if(left1[l]<=0)
				printf("* ");
			else
				printf("%d ",left1[l]);
			if(right1[r]>s)
				printf("*\n");
			else
				printf("%d\n",right1[r]);
		}
		printf("-\n");
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int s,b;
	scanf("%d",&s);
	scanf("%d",&b);
	while(s){
		work(s,b);
		scanf("%d",&s);
		scanf("%d",&b);
	}
	return 0;
}