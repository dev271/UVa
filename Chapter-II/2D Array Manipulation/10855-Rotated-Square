#include <iostream>
#include <cstdio>

using namespace std;

int check(int c,int d,int N,int n,char a[][100],char A[][100]){
	int i,j;
	for(i=c;i<c+n;i++){
		for(j=d;j<d+n;j++){
			if(A[i][j]!=a[i-c][j-d])
				return 0;
		}
	}
	return 1;
}
int main(){
	char A[100][100];
	char a1[100][100];
	char a2[100][100];
	char a3[100][100];
	char a4[100][100];
	int N,n,i,j,count1=0,count2=0,count3=0,count4=0;
	scanf("%d",&N);
	scanf("%d",&n);
	while(N){
		count1=0;count2=0;count3=0;count4=0;
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				cin>>A[i][j];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>a1[i][j];
				a2[j][n-i-1]=a1[i][j];
				a3[n-i-1][n-j-1]=a1[i][j];
				a4[n-j-1][i]=a1[i][j];
			}
		}
		for(i=0;i<=N-n;i++){
			for(j=0;j<=N-n;j++){
				if(check(i,j,N,n,a1,A))
					count1++;
				if(check(i,j,N,n,a2,A))
					count2++;
				if(check(i,j,N,n,a3,A))
					count3++;
				if(check(i,j,N,n,a4,A))
					count4++;
			}
		}
		printf("%d %d %d %d\n",count1,count2,count3,count4);
		scanf("%d",&N);
		scanf("%d",&n);
	}
}
