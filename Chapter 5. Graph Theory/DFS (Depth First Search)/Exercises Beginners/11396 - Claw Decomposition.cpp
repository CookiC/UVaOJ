//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#define maxn 1000
//#pragma warning(disable : 4996)
using namespace std;

class Bipartite{
private:
	int C[maxn];
	vector<int> G[maxn];
	
	bool DFS(int u){
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
		for(int i=1;i<=N;++i)
			G[i].clear();
		memset(C,0,sizeof(int)*(N+1));
	}
	
	void AddEdge(int u,int v){
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	bool Answer(){
		int i;
		bool b=1;
		for(i=1;i<=N&&b;++i)
			if(!C[i]){
				C[i]=1;
				b&=DFS(i);
			}
		return b;
	}
};

Bipartite bpt;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int V,a,b;
	while(cin>>V&&V){
		bpt.N=V;
		bpt.clear();
		while(cin>>a>>b&&a)
			bpt.AddEdge(a,b);
		if(bpt.Answer())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

