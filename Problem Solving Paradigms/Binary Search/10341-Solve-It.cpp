#include <iostream>
#include <cmath>

using namespace std;
double p,q,r,s,t,u;
double func(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main(){
	double x,mid;
	double low=0,high=1;
	while(cin>>p>>q>>r>>s>>t>>u){
		low = 0;high = 1;
		if(func(low)*func(high)>0){cout<<"No solution"<<endl;continue;}
		while(low + 0.0000001<high){
			mid = (low+high)/2;
			if((func(mid)*func(low)<=0))high = mid;
			else low = mid;
		}
		printf("%.4lf\n",(low+high)/2);
	}
	return 0;
}