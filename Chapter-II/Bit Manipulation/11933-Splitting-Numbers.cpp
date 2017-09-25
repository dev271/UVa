#include <iostream>
#include <bitset>
using namespace std;

int main(){
	long long int d;
	unsigned long long int e,f;
    int count;
	bitset<32> a(0);
	bitset<32> b(0);
	cin>>d;
	bitset<32> n(d);
	while(d){
		count=2;
		a=0;
		b=0;
		for(int i=0;i<=31;i++){
			if (n[i]==1)
			{
				if(count%2==0)
					a[i]=1;
				else
					b[i]=1;
				count++;
			}
		}
		e=a.to_ullong();f=b.to_ullong();
		cout<<e<<" "<<f<<endl;
		cin>>d;
		n=d;
	}
	return 0;
}