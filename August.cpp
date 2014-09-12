#include <cstdio>
#include<iostream>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        int table[n];
        int k=0;
        int cust[m];
        bool flag[401]={false};
        for(int i=0;i<m;i++){
            scanf("%d",&cust[i]);
        }
        int result=0;
        for(int i=0;i<m;i++){
            if(flag[cust[i]]){
            }
            else{
                result++;

                if(k<n){

                    table[k]=cust[i];
                    k++;
                }
                else{
                    bool temp[401]={false};
                    int oc=-1;
                    for(int j=i+1;j<m;j++){
                        if(flag[cust[j]]&&!temp[cust[j]]){
                            temp[cust[j]]=true;
                            oc=j;
                        }
                    }
                    int tno=-1;
                    for(int j=0;j<n;j++){
                        if(oc!=-1&&table[j]==cust[oc]){
                            tno=j;
                        }
                        if(!temp[table[j]]){
                            tno=j;
                            break;
                        }
                    }
                    if(tno!=-1){flag[table[tno]]=false;
                    table[tno]=cust[i];}
                }
                flag[cust[i]]=true;
            }
        }
        printf("%d\n",result);
    }
}
