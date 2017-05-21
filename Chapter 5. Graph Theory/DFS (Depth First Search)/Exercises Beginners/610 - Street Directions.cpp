//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#define maxn 1010
using namespace std;

struct Edge{
	int u,v;
	Edge(int u,int v):u(u),v(v){}
};
	
vector<Edge> ans;

class CutEdge{
private:
	int N;
	int clk,pre[maxn];
	
	int DFS(int u,int f){
		int lowu=pre[u]=++clk;
		for(auto e=G[u].begin();e!=G[u].end();++e){
			int v=*e;
			if(!pre[v]){
				ans.push_back(Edge(u,v));
				int lowv=DFS(v,u);
				lowu=min(lowu,lowv);
				if(lowv>pre[u])
					ans.push_back(Edge(v,u));
			}
			else if(pre[u]>pre[v]&&v!=f){
				ans.push_back(Edge(u,v));
				lowu=min(lowu,pre[v]);
			}
		}
		return lowu;
	}
	
public:
	vector<int> G[maxn];
	
	void Clear(int n){
		N=n;
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=N;++i)
			G[i].clear();
		clk=0;
	}
	
	void AddEdge(int u,int v){
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	void Find(){
		for(int i=1;i<=N;++i)
			if(!pre[i])
				DFS(i,-1);
	}
};

CutEdge ce;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,i,u,v,T;
	for(T=1;cin>>n>>m&&n;++T){
		ans.clear();
		ce.Clear(n);
		for(i=0;i<m;++i){
			cin>>u>>v;
			ce.AddEdge(u,v);
		}
		ce.Find();
		
		cout<<T<<endl<<endl;
		for(auto e=ans.begin();e!=ans.end();++e)
			cout<<e->u<<' '<<e->v<<endl;
		cout<<'#'<<endl;
	}
	return 0;
}

