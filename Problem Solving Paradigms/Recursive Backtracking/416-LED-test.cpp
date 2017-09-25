#include <iostream>
#include <cstring>
using namespace std;

bool check(string a, bool burnables[] , int n){
	string b[10] = {"YYYYYYN",
    "NYYNNNN",
 	"YYNYYNY",
 	"YYYYNNY",
 	"NYYNNYY",
 	"YNYYNYY",
 	"YNYYYYY",
 	"YYYNNNN",
	"YYYYYYY",
 	"YYYYNYY"};
 	int i,j;
 	if(n<0)return false;
 	for(j=0;j<7;j++){
 		if(b[n][j] == 'N' && a[j]!='N')return false;
 		if(b[n][j] == 'Y' && (!burnables[j] && a[j]!='Y'))return false;
 	}
 	return true;

}
bool ans(string a[], bool burnables[], int ind, int num, int n){
	int i,j;
	if(ind == n){
		return true;
	}
	for(i=0;i<12;i++)burnables[i] = true;
	for(i=0;i<7;i++){
		for(j=ind;j<n;j++){
			if(a[j][i] == 'Y')burnables[i] = false;
		}
	}
	if(check(a[ind],burnables,num)){
		return ans(a,burnables,ind+1,num-1,n);
	}
	else return false;
}
int main(){
	string a[12];
	bool burnables[12];
	bool flag;
	int k,i,j;
	cin>>k;
	while(k){
		flag = false;
		for(i=0;i<k;i++){
			cin>>a[i];
		}	
		for(i=9;i>=k-1;i--){
			if(ans(a,burnables,0,i,k))flag=true;
		}
		if(flag)cout<<"MATCH"<<endl;
		else cout<<"MISMATCH"<<endl;
		cin>>k;
	}
}