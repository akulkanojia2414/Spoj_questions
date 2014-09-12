
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <queue>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>


using namespace std;

char 	a[100000];
bool num_visited[10] ={0};
vector<long long> vec[10];
	int ctr[100000] = {0};
bool visit[100000] = {0};
int len,cur,temp,i;
int main()
{
	queue<int> q;
	scanf("%s",a);
		 len = strlen(a);

	for( i=0;i<len;i++)
	{
		vec[a[i]-'0'].push_back(i);
	}
	q.push(0);
	visit[0] = true;

	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		//cout<<cur<<endl;
		//if(visit[cur]==true) goto again;
		if(cur == len-1) break;
		 temp = vec[a[cur]-'0'].size();

		if(visit[cur+1]==false&&cur!=len-1){
		visit[cur+1] = true;
		q.push(cur+1);
		ctr[cur+1] =ctr[cur]+1;}

		if(cur!=0&&visit[cur-1]==false){visit[cur-1]=true; q.push(cur-1); ctr[cur-1] = ctr[cur]+1;}

	//if(num_visited[a[cur]-'0']==false){
		for(i =0;i<temp;i++)
		{
			if(visit[vec[a[cur]-'0'][i]]==false)
			{visit[vec[a[cur]-'0'][i]] = true;
			q.push(vec[a[cur]-'0'][i]);
			ctr[vec[a[cur]-'0'][i]] = ctr[cur]+1;}
		//}

		//q.push(cur);

	}
		num_visited[a[cur]-'0'] = true;

}

//124	q.clear();
	printf("%d",ctr[len-1]);
}
