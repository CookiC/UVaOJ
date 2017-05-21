//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#define maxn 1000
#define INF 0x7FFFFFFF
//#pragma warning(disable : 4996)
using namespace std;

class Point{
public:
	double x, y;

	Point(){  }

	Point(double x, double y) :x(x), y(y){ Point(); }

	Point operator - (const Point &b) const{

		return Point(x - b.x, y - b.y);
	}

	Point operator + (const Point &b) const{
		return Point(x + b.x, y + b.y);
	}

	Point operator * (const double k) const{
		return Point(k*x, k*y);
	}

	Point operator / (const double k) const{
		return Point(x / k, y / k);
	}

	double Slope(){
		return y / x;
	}

	double Len(){
		return sqrt(x*x + y*y);
	}

};

typedef Point Vector;

class Dijkstra{
private:
	struct HeapNode{
		int u;
		double d;
		HeapNode(int u, double d) :u(u), d(d){}
		bool operator < (const HeapNode &b) const{
			return d > b.d;
		}
	};

	struct Edge{
		int v;
		double w;
		Edge(int v, double w) :v(v), w(w){}
	};

	vector<Edge> G[maxn];
	bool vis[maxn];

public:
	double d[maxn];

	void clear(int n){
		int i;
		for (i = 0; i < n; ++i)
			G[i].clear();
		for (i = 0; i < n; ++i)
			d[i] = INF;
		memset(vis, 0, sizeof(vis));
	}

	void AddEdge(int u, int v, double w){
		G[u].push_back(Edge(v, w));
	}

	void run(int s){
		int u;
		priority_queue<HeapNode> q;

		d[s] = 0;
		q.push(HeapNode(s, 0));
		while (!q.empty()){
			u = q.top().u;
			q.pop();
			if (!vis[u]){
				vis[u] = 1;
				for (auto e = G[u].begin(); e != G[u].end(); ++e)
					if (d[e->v] > d[u] + e->w){
						d[e->v] = d[u] + e->w;
						q.push(HeapNode(e->v, d[e->v]));
					}
			}
		}
	}
};

int N,F,n;
Point P[maxn];
double pos[maxn];
int lab[maxn];
Dijkstra dij;

double Cost(Point p, const Point &p0, const Point &p1, Vector &v0, Vector &v1){
	static double z;
	static Point t0, t1;
	t0 = v0*(p.x / v0.Len()) + p0;
	t1 = v1*(-p.y / v1.Len()) + p1;
	z = (t0 - t1).Len();
	return F*z;
}

void Fly(int s,int t){
	Point p0 = P[s], p1 = P[s + 1];
	Point p2 = P[t - 1], p3 = P[t];
	Vector a = p1 - p0,b = p3 - p2;
	double al = a.Len(), bl = b.Len();

	static double e = 1e-4;
	double dx, dy,cost0,cost1;
	Point q;

	double yl = 0,yr = bl,ym;
	while (yr - yl>1e-5){
		ym = yl + (yr - yl) / 2;
		
		q = Point(0, ym);
		cost0 = Cost(q, p0, p3, a, b)+q.y;
		if (q.y + e <= bl)
			q.y += e;
		else
			q.y -= e;
		cost1 = Cost(q, p0, p3, a, b)+q.y;
		dy = (cost0 - cost1) / (ym-q.y);
		
		if (dy > 0)
			yr = ym;
		else
			yl = ym;
	}

	double xl = 0, xr = al,xm;
	while (xr - xl>1e-5){
		xm = xl + (xr - xl) / 2;

		q = Point(xm, 0);
		cost0 = Cost(q, p0, p3, a, b)+q.x;
		if (q.x + e <= al)
			q.x += e;
		else
			q.x -= e;
		cost1 = Cost(q, p0, p3, a, b)+q.x;
		dx = (cost0 - cost1) / (xm - q.x);

		if (dx > 0)
			xr = xm;
		else
			xl = xm;
	}

	double x, y;
	if (Cost(Point(xl, 0), p0, p3, a, b) +xl< Cost(Point(0, yl), p0, p3, a, b)+yl){
		x = xl;
		y = 0;
	}
	else{
		x = 0;
		y = yl;
	}

	int u, v;
	if (x < 1e-4){
		u = s;
		x = 0;
	}
	else if (al - x < 1e-4){
		u = s + 1;
		x = al;
	}
	else{
		u = n;
		pos[n] = pos[s] + x;
		++n;
	}

	if (y < 1e-4){
		v = t;
		y = 0;
	}
	else if (bl - y < 1e-4){
		v = t - 1;
		y = bl;
	}
	else{
		v = n;
		pos[n] = pos[t] - y;
		++n;
	}

	dij.AddEdge(u, v, Cost(Point(x, y), p0, p3, a, b));
}

bool cmp(const int a, const int b){
	return pos[a] < pos[b];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	for (int T = 1; cin >> N >> F&&N;++T){
		pos[0] = 0;
		for (i = 0; i < N + 1; ++i){
			cin >> P[i].x >> P[i].y;
			if (i)
				pos[i] = pos[i - 1] + (P[i] - P[i - 1]).Len();
		}

		n = N+1;
		dij.clear((N+1)*(N+2)/2);
		for (i = 0; i < N-1; ++i)
			for (j = i + 2; j < N+1; ++j)
				Fly(i, j);
		
		for (i = 0; i < n; ++i)
			lab[i] = i;
		sort(lab, lab + n, cmp);
		for (i = 0; i < n - 1; ++i)
			dij.AddEdge(lab[i], lab[i + 1], pos[lab[i + 1]] - pos[lab[i]]);
		dij.run(0);

		cout << "Case " << T << ": " <<fixed<<setprecision(5)<< dij.d[N]<<endl;
	}
	return 0;
}

