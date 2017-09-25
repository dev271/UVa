#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	long long int i,j,k,l,x,c,q,w;
	for(i=1;i<=2000;i++){
		if(i*i*i*i>2000000000)break;
		for(j=i;j<=2000-i;j++){
			if(i*j*j*j>2000000000)break;
			for(k=j;k<=2000-j-i;k++){
				if(i*j*k*k>2000000000)break;
				c=1000000;
				x=i*j*k-c;
				if(x==0)continue;
				q=c*(i+j+k);
				if(q%x!=0)continue;
				w=q/x;
				if(k>w)continue;
				if(w+i+j+k>2000)continue;
				if(w*i*j*k>2000000000)continue;
				cout<<fixed;
				cout<<setprecision(2)<<i/100.00<<" "<<j/100.00<<" "<<k/100.00<<" "<<w/100.00<<endl;
			}
		}
	}
	return 0;
}