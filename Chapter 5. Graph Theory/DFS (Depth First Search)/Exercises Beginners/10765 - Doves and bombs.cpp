//#include"stdafx.h"
#include<iostream> 
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<cstring>
//#pragma warning(disable : 4996)
#define maxn 100010
using namespace std;

int n, m;

class BCC{
private:
	int clk, cnt;
	int pre[maxn];
	stack<int> s;
	
	int DFS(int u,int f){
		int lowu = pre[u] = ++clk;
		int child = 0;
		s.push(u);
		for (auto it = G[u].begin(); it != G[u].end(); ++it){
			int v = *it;
			if (!pre[v]){
				s.push(u);
				++child;
				int lowv = DFS(v, u);
				if (lowu > lowv)
					lowu = lowv;
				if (lowv >= pre[u]){
					iscut[u] = 1;
					++cnt;
					int x;
					do{
						x = s.top();
						s.pop();
						if (num[x] != cnt)
							num[x] = cnt;
					}while (x != u);
				}
			}
			else if (pre[v] < pre[u] && v != f){
				if (lowu > pre[v])
					lowu = pre[v];
			}
		}
		if (f < 0 && child == 1)
			iscut[u] = 0;
		return lowu;
	}
public:
	vector<int> G[maxn];
	bool iscut[maxn];
	int num[maxn];
	
	void Clear(int n){
		for (int i = 0; i < n; ++i)
			G[i].clear();
	}

	void AddEdge(int u,int v){
		G[u].push_back(v);
		G[v].push_back(u);
	}

	void Find(){
		int i;
		memset(pre, 0, sizeof(pre));
		memset(iscut, 0, sizeof(iscut));
		memset(num,0,sizeof(num));
		clk = cnt = 0;
		for (i = 0; i < n; ++i)
			if (!pre[i]){
				while(!s.empty())
					s.pop();
				DFS(i,-1);	
			}
	}
};

struct HeapNode{
	int n,v;
	HeapNode(int n,int v):n(n),v(v){}
	
	bool operator < (const HeapNode &b) const{
		if(v==b.v)
			return n<b.n;
		return v>b.v;
	}
};

BCC bcc;
vector<HeapNode> a;
int P[maxn];
set<int> s;

int Find(int x){
	if (P[x] == x)
		return x;
	return P[x] = Find(P[x]);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);


	int u, v, i, n0;
	while(cin>>n>>m&&n){
		for (i = 0; i < n; ++i)
			P[i] = i;
		bcc.Clear(n);

		while (cin >> u >> v&&u != -1)
			if(u!=v){
				bcc.AddEdge(u, v);
				int x = Find(u);
				int y = Find(v);
				if (x != y)
					P[y] = x;
			}

		s.clear();
		for (i = 0; i < n; ++i)
			s.insert(Find(i));
		n0 = s.size();
		bcc.Find();
		
		a.clear();
		for (i = 0; i < n; ++i)
			if (bcc.iscut[i]){
				s.clear();
				for (auto v = bcc.G[i].begin(); v != bcc.G[i].end(); ++v)
					s.insert(bcc.num[*v]);
				a.push_back(HeapNode(i, s.size() + n0 - 1));
			}
			else
				if (bcc.G[i].size())
					a.push_back(HeapNode(i, n0));
				else
					a.push_back(HeapNode(i, n0-1));

		sort(a.begin(),a.end());
		for(i=0;i<m;++i)
			cout<<a[i].n<<' '<<a[i].v<<endl;
		cout<<endl;
	}
	return 0;
}

