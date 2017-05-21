//#include"stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
//#pragma warning(disable : 4996)
#define INF 0x7FFFFFFF
#define maxn 1010									//n表示节点个数 
using namespace std;

struct Edge{
	int c, f, cost;
	unsigned v, flip;
	Edge(unsigned v, int c, int f, unsigned flip, int cost) :v(v), c(c), f(f), flip(flip), cost(cost){}
};

class MCMF{
private:
	unsigned n;
	vector<Edge> G[maxn];
	bool inq[maxn];
	int d[maxn];
	int a[maxn];									//a表示可改进量 不会出现负数可改进量
	unsigned p[maxn];								//p[v]表示u到v的反向边 即v到u的边 

public:
	unsigned s, t;

	void init(unsigned x){
		n = x;
		for (unsigned i = 0; i < n; ++i)
			G[i].clear();
		s = 0;
		t = n - 1;
	}

	void AddEdge(unsigned u, unsigned v, int c, int cost){
		if (c){
			G[u].push_back(Edge(v, c, 0, G[v].size(), cost));
			G[v].push_back(Edge(u, 0, 0, G[u].size() - 1, -cost));
		}
	}

	bool BellmanFord(int &flow, int &cost){
		int i;
		unsigned u;
		queue<unsigned> q;
		memset(a, 0, sizeof(a));
		memset(inq, 0, sizeof(inq));
		for (i = 0; i<n; ++i)
			d[i] = INF;
		d[s] = 0;
		inq[s] = 1;
		q.push(s);
		a[s] = INF;
		while (!q.empty()){
			u = q.front();
			q.pop();
			inq[u] = false;
			for (auto it = G[u].begin(); it != G[u].end(); ++it){
				Edge &e = *it;
				if (e.c>e.f&&d[e.v]>d[u] + e.cost){
					d[e.v] = d[u] + e.cost;
					p[e.v] = e.flip;
					a[e.v] = min(a[u], e.c - e.f);
					if (!inq[e.v]){
						q.push(e.v);
						inq[e.v] = true;
					}
				}
			}
		}
		if (d[t] == INF)
			return false;
		flow += a[t];
		cost += d[t] * a[t];
		u = t;
		while (u != s){
			Edge &ue = G[u][p[u]];
			Edge &ve = G[ue.v][ue.flip];
			ue.f -= a[t];
			ve.f += a[t];
			u = ue.v;
		}
		return true;
	}

	int MincostMaxflow(int &cost){
		int flow = 0;
		while (BellmanFord(flow, cost));
		return flow;
	}
};

int cost;
unsigned n,m,u,v;
MCMF G;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i;
	while(cin>>n&&n){
		G.init(n+1);
		cin>>m;
		for(i=0;i<m;++i){
			cin>>u>>v>>cost;
			G.AddEdge(u,v,1,cost);
			G.AddEdge(v,u,1,cost);
		}
		G.AddEdge(n,0,2,0);
		cost=0;
		G.s=1;G.t=0;
		if(G.MincostMaxflow(cost)==2)
			cout<<cost<<endl;
		else
			cout<<"Back to jail"<<endl;
	}
	return 0;
}

