#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void print(int *a, int n, int r, char *str){
	
	char temp[1100];
	strcpy(temp,"");
	
	if(r==1){
		for(int i=0;i<n;i++){
			
			cout<<'{'<<str<<a[i]<<'}'<<endl;
		}
	}
	else{
		
		
		strcpy(temp,str);
		
		for(int i=0,size=n-1;size>=r-1;size--,i++){
			strcpy(str,temp);
			sprintf(str,"%s%d,",temp,a[i]);
			
			print(a+i+1,size,r-1,str);
		}
	}
}			

int main(){
	
	int a[]={1,2,3,4,5,6,7,8,9,10};
	char str[100]="";
	print(a,10,5 ,str);
	return 0;
}
