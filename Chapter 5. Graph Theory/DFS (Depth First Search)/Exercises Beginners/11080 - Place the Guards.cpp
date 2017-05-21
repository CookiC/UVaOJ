//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#define INF 0x7FFFFFFF
#define maxn 210
using namespace std;

class Bipartite{
private:
	int c,d;
	int C[maxn];
	vector<int> G[maxn];
	
	bool DFS(int u){
		if(C[u]==1)
			++c;
		else
			++d;
		
		for(auto it=G[u].begin();it!=G[u].end();++it){
			int v=*it;
			if(C[u]==C[v])
				return false;
			if(!C[v]){
				C[v]=3-C[u];
				if(!DFS(v))
					return false;
			}
		}
		return true;
	}
	
public:
	int N;
	
	void clear(){
		for(int i=0;i<N;++i)
			G[i].clear();
		memset(C,0,sizeof(int)*(N));
	}
	
	void AddEdge(int u,int v){
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int Answer(){
		int i,ans=0;
		bool b=1;
		for(i=0;i<N&&b;++i)
			if(!C[i]){
				C[i]=1;
				c=0;
				d=0;
				b&=DFS(i);
				if(d==0)
					ans+=1;
				else
					ans+=min(c,d);
			}
		if(!b)
			ans=-1;
		return ans;
	}
};

Bipartite bpt;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int T,n,m,ans,i,u,v;
	cin>>T;
	while(T--){
		cin>>n>>m;
		bpt.N=n;
		bpt.clear();
		for(i=0;i<m;++i){
			cin>>u>>v;
			bpt.AddEdge(u,v);
		}
		cout<<bpt.Answer()<<endl;
	}
	return 0;
}

