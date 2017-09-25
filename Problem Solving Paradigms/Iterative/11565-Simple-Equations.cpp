#include <iostream>
using namespace std;

int main(){
	int n,a,b,c,i,j,k,flag;
	scanf("%d",&n);
	while(n--){
		flag=0;
		scanf("%d %d %d",&a,&b,&c);
		for(i=-100;i<=100;i++){if(i*i<=c)
			for(j=i;j<=a-i;j++){
				k=a-i-j;
				if(i*j*k==b && i*i+j*j+k*k==c && (i!=j && i!=k && j!=k)){
					printf("%d %d %d\n",i,j,k);
					flag=1;
					break;
				}
			}
			if(flag)break;
		}
		if(!flag)printf("No solution.\n");
	}
}