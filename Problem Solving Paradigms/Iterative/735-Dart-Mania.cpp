#include <iostream>
using namespace std;

int main(){
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,26,27,28,30,32,33,34,36,38,39,40,42,45,48,50,51,54,57,60};
	int i,j,k,x,flag;
	int n,count1,count2;
	cin>>n;
	while(n>0){
		count1=0;count2=0;
		for(i=0;i<43;i++){
			for(j=i;j<43;j++){
				for(k=j;k<43;k++){
					if((a[i]+a[j]+a[k])!=n)
						continue;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
					x=a[k];
					if(a[i]==a[j] && a[i]==x)
						flag=1;
					else if(a[i]==a[j] || a[i]==x || a[j]==x)
						flag=3;
					else
						flag=6;
					count1++;
					count2 = count2+flag;
				}
			}
		}
		if(count1!=0){
			cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<n<<" IS "<<count1<<"."<<endl;
			cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<n<<" IS "<<count2<<"."<<endl;
			cout<<"**********************************************************************"<<endl;
		}
		else{
			cout<<"THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
			cout<<"**********************************************************************"<<endl;
		}
		cin>>n;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}