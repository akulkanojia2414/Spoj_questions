#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	int temp=a[0];
	cout<<a[0]<<",";
	for(int i =1;i<n;i++){
		if(temp == a[i]) {
		}
		else {
			cout<<a[i]<<',';
			temp = a[i];
		}
	}
	
}
