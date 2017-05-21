//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

class SCC{
private:
	int clk;
	int pre[maxn];
	stack<int> s;
	
	int DFS(int u){
		int lowu=pre[u]=++clk;
		s.push(u);
		for(auto it=G[u].begin();it!=G[u].end();++it){
			int v=*it;
			if(!pre[v]){
				int lowv=DFS(v);
				if(lowu>lowv)
					lowu=lowv;
			}
			else if(!num[v]&&lowu>pre[v])
				lowu=pre[v];
		}
		if(lowu==pre[u]){
			++cnt;
			int x;
			do{
				x=s.top();
				s.pop();
				num[x]=cnt;
			}while(x!=u);
		}
		return lowu;
	}
	
public:
	int N,cnt;
	int num[maxn];
	vector<int> G[maxn];
	
	void clear(){
		for(int i=1;i<=N;++i)
			G[i].clear();
		memset(pre,0,sizeof(pre));
		memset(num,0,sizeof(num));
		clk=0;
		cnt=0;
	}
	
	void AddEdge(int u,int v){
		G[u].push_back(v);
	}
	
	void Find(){
		for(int i=1;i<=N;++i)
			if(!pre[i])
				DFS(i);
	} 
};

SCC scc;
bool b[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,T,u,v,i,ans;
	cin>>T;
	while(T--){
		cin>>n>>m;
		scc.N=n;
		scc.clear();
		for(i=0;i<m;++i){
			cin>>u>>v;
			scc.AddEdge(u,v);
		}
		scc.Find();
		
		memset(b,0,sizeof(bool)*(scc.cnt+1));
		for(u=1;u<=n;++u)
			for(auto it=scc.G[u].begin();it!=scc.G[u].end();++it){
				v=*it;
				if(scc.num[u]!=scc.num[v])
					b[scc.num[v]]=1;
			}
		
		ans=0;
		for(i=1;i<=scc.cnt;++i)
			if(!b[i])
				++ans;
		
		cout<<ans<<endl;
	}
	return 0;
}

