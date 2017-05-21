//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#define maxn 210
#define maxm 20000
#define INF 0x7FFFFFFF
//#pragma warning(disable : 4996)
using namespace std;

struct Edge{
	int v,w;
	Edge(int v,int w):v(v),w(w){}
};

vector<Edge> G[maxn];
 
class Kruskal{
	struct UdEdge{
		int u,v,w;
		UdEdge(){}
		UdEdge(int u,int v,int w):u(u),v(v),w(w){}
	};
	
	int N,M;
	UdEdge pool[maxm];
	UdEdge *E[maxm];
	int P[maxn];
	
	int Find(int x){
		if(P[x]==x)
			return x;
		return P[x]=Find(P[x]);
	}
	
public:
	static bool cmp(const UdEdge *a,const UdEdge *b){
		return a->w>b->w;
	}
	
	void Clear(int n){
		N=n;
		M=0;
	}
	
	void AddEdge(int u,int v,int w){
		pool[M]={u,v,w};
		E[M]=&pool[M];
		++M;
	}
	
	int Run(){
		int i,ans=0;
		for(i=1;i<=N;++i)
			P[i]=i;
		sort(E,E+M,cmp);
		for(i=0;i<M;++i){
			UdEdge *e=E[i];
			int x=Find(e->u);
			int y=Find(e->v);
			if(x!=y){
				P[y]=x;
				ans+=e->w;
				G[e->u].push_back(Edge(e->v,e->w));
				G[e->v].push_back(Edge(e->u,e->w));
			}
		}
		return ans;
	}
};

Kruskal kru;
map<string,int> id;

int d[maxn];
bool vis[maxn];

void DFS(int u){
	vis[u]=1;
	for(auto e=G[u].begin();e!=G[u].end();++e)
		if(!vis[e->v]){
			d[e->v]=min(d[u],e->w);
			DFS(e->v);
		}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,cnt,u,v,w,i,T;
	string un,vn;
	for(T=1;cin>>n>>m&&n;++T){
		id.clear();
		for(i=1;i<=n;++i)
			G[i].clear();
		kru.Clear(n);
		cnt=0;
		for(i=0;i<m;++i){
			cin>>un>>vn>>w;
			if(id.find(un)==id.end()){
				id[un]=++cnt;
				u=cnt;
			}
			else
				u=id[un];
			
			if(id.find(vn)==id.end()){
				id[vn]=++cnt;
				v=cnt;
			}
			else
				v=id[vn];
			kru.AddEdge(u,v,w);
		}
		
		kru.Run();
		
		cin>>un>>vn;
		u=id[un];
		v=id[vn];
		d[u]=INF;
		memset(vis,0,sizeof(vis));
		DFS(u);
		
		cout<<"Scenario #"<<T<<endl;
		cout<<d[v]<<" tons"<<endl;
		cout<<endl;
	}
	return 0;
}

