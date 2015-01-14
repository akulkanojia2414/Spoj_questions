#include<bits/stdc++.h>
using namespace std;
int x,v[5],k;
bool solve(int ind,int sum){
	cout<<ind<<" "<<sum<<endl;
	int tmp=0;
	for(int i=0;i<=ind;i++){
		tmp+=v[i];
	}
	if(ind<0){
		if(sum==0)
			return true;
		return false;
	}
	if(sum<0)
	return false;
	if(sum==0)
	return true;
	if(sum%tmp==0)
	return true;
	return (solve(ind,sum-tmp)||solve(ind-1,sum)||solve(ind-1,sum-tmp));
}
int main(){
	cin>>x>>k;
	for(int i=0;i<k;i++){
		cin>>v[i];
	}
	if(solve(k-1,x))
	cout<<"YES";
	else
	cout<<"NO";
}
