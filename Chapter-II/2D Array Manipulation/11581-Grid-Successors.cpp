#include <iostream>
#include <cstdio>

using namespace std;
	int count;
int trans(int a[][3]){
	int b[3][3];
	int flag=1;
	int j,k;
	for(j=0;j<3;j++){
		for(k=0;k<3;k++){
			if(a[j][k]==1)
				flag=0;
		}
	}
	if(flag)
		return (count);
	else{
		count++;
		b[0][0]=(a[0][1]+a[1][0])%2;
		b[0][1]=(a[0][0]+a[0][2]+a[1][1])%2;
		b[0][2]=(a[0][1]+a[1][2])%2;
		b[1][0]=(a[0][0]+a[1][1]+a[2][0])%2;
		b[1][1]=(a[1][0]+a[0][1]+a[1][2]+a[2][1])%2;
		b[1][2]=(a[0][2]+a[2][2]+a[1][1])%2;
		b[2][0]=(a[1][0]+a[2][1])%2;
		b[2][1]=(a[2][0]+a[1][1]+a[2][2])%2;
		b[2][2]=(a[2][1]+a[1][2])%2;
		return trans(b);
	}	
}
int main(){
	int t,i,j,k;
	cin>>t;

	int a[3][3];
	char c;
	for(i=0;i<t;i++){
		count=-1;
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				cin>>c;
				a[j][k]=int(c)-48;
			}
		}
		cout<<trans(a)<<endl;
	}
	return 0;
}