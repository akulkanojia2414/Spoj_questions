#include<bits/stdc++.h>
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define For(n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define CLR(x) memset(x,0,sizeof(x));
using namespace std;
struct node{
    int l,r,lazy,v[3];
};
struct ans_node{
	int v0,v1,v2;
};
node tree[300000];
int arr[100000];
string s;
void built_tree(int a){
    if(tree[a].l==tree[a].r){
    	For(3)tree[a].v[tree[a].l]=0;
		tree[a].v[arr[tree[a].l]]++;
    }
    else{
        int mid=tree[a].l+tree[a].r;mid/=2;
        tree[2*a].l=tree[a].l;tree[2*a].r=mid;
        tree[2*a+1].r=tree[a].r;tree[2*a+1].l=mid+1;
        built_tree(2*a);
        built_tree(2*a+1);
        For(3){
			tree[a].v[i]=tree[2*a].v[i]+tree[2*a+1].v[i];
        }
    }
    return;
}
/*void update(int nod,int val,int i,int j){
    if(lazy[nod]!=0){
        if(tree[nod].l==tree[nod].r){
            tree[nod].val+=lazy[nod];
        }
        else{
            tree[nod].val+=lazy[nod];
            lazy[2*nod]+=lazy[nod];
            lazy[2*nod+1]+=lazy[nod];
        }
        lazy[nod]=0;
    }
    if(tree[nod].l>j||tree[nod].r<i)
        return;
    if(tree[nod].l>=i&&tree[nod].r<=j){
        tree[nod].val+=val;
        if(tree[nod].l!=tree[nod].r){
            lazy[2*nod]+=val;
            lazy[2*nod+1]+=val;
        }
        return;
    }
    update(2*nod,val,i,j);
    update(2*nod+1,val,i,j);
    tree[nod].val=min(tree[2*nod+1].val,tree[2*nod].val);
}
int query(int nod,int i,int j){
    if(lazy[nod]!=0){
        if(tree[nod].l==tree[nod].r){
            tree[nod].val+=lazy[nod];
        }
        else{
            tree[nod].val+=lazy[nod];
            lazy[2*nod]+=lazy[nod];
            lazy[2*nod+1]+=lazy[nod];
        }
        lazy[nod]=0;
    }
    if(tree[nod].l>j||tree[nod].r<i)
        return INT_MAX;
    if(tree[nod].l>=i&&tree[nod].r<=j){
        return tree[nod].val;
    }
    return min(query(2*nod,i,j),query(2*nod+1,i,j));
}
void print(int i){
    cout<<tree[i].l<<" "<<tree[i].r<<" "<<tree[i].val<<" "<<lazy[i]<<endl;
    if(tree[i].l!=tree[i].r){
        print(2*i);
        print(2*i+1);
    }
    return;
}*/
int main(){
    ios::sync_with_stdio(false);
}



