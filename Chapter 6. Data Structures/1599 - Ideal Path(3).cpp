#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct Point{
  unsigned n,e;
};

struct Node{
  unsigned d,n,e,o;
  bool operator <(const Node &b) const{
  	if(d==b.d){
  	  if(e==b.e)
  	    return o>b.o;
  	  return e>b.e;
    }
  	return d>b.d;
  }
};

unsigned n,m;
vector<vector<Point>> l;

void IdealPath(const unsigned origin,const unsigned destin,const unsigned maxn){
  priority_queue<Node> q; 
  unsigned d[maxn],order[maxn]={0};
  bool handle[maxn]={0}; 
  unsigned i=1,j=1;
  memset(d,0xFF,sizeof(d));
  d[destin]=0;

  q.push(Node{0,destin,0,0});
  while(q.top().n!=origin){
  	unsigned u=q.top().n;
  	if(!handle[u]){
  	  order[u]=i++;
  	  for(auto v=l[u].begin();v!=l[u].end();++v)
  	    if(d[v->n]==d[u]+1||d[v->n]==0xFFFFFFFF){
  	      d[v->n]=d[u]+1;
  	      q.push(Node{d[v->n],v->n,v->e,j++});
		}
	  handle[u]=true;
	  }
	q.pop();
  }
  
  printf("%u\n",d[origin]);
  unsigned mino,minv=origin,mine;
  for(i=0;i<d[origin];++i){
  	unsigned u=minv;
	auto v=l[u].begin();
  	mino=0xFFFFFFFF;
  	mine=0xFFFFFFFF;
  	while(v!=l[u].end()){
      if(d[u]==d[v->n]+1&&(mine>v->e||mine==v->e&&mino>order[v->n])){
  	  	minv=v->n;
  	  	mine=v->e; 
		mino=order[v->n];
	  }
	  ++v;
	}
	if(i)
	  printf(" ");
	printf("%u",mine);
  }
  printf("\n");
}

int main(){
  while(scanf("%u%u",&n,&m)==2){
  	l.clear();
  	l.resize(n+1);

    for(unsigned i=0;i<m;++i){
  	  unsigned u,v,e;
  	  scanf("%u%u%u",&u,&v,&e);
  	  l[u].push_back(Point{v,e});
  	  l[v].push_back(Point{u,e});
    }
    IdealPath(1,n,n+5);
  }
  return 0;
}

