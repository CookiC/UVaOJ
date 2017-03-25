#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<ctime>
#define maxn 100050
using namespace std;

struct Point{
  unsigned n,e;
};

unsigned n,m,d[maxn];
vector<vector<Point>> l;

void ShortestWay(const unsigned origin,const unsigned destin){
  queue<unsigned> q;
  bool arrive[maxn]={0};
  arrive[origin]=true;
  q.push(origin);
  while(!arrive[destin]){
  	unsigned u=q.front();
  	q.pop();
  	for(auto v=l[u].begin();v!=l[u].end();++v)
  	  if(!arrive[v->n]){
  	    d[v->n]=d[u]+1;
  	    q.push(v->n);
  	    arrive[v->n]=true;
  	    //防止对同一点多次操作 仅取第一次操作的值 
  	    //一步步向外辐射 
  	  }
  }
  printf("%u\n",d[1]);
}

void PrintDic(const unsigned origin,const unsigned destin){
  unsigned dic[maxn],minarr[maxn],i,j,u;
  queue<unsigned> q;
  memset(dic,0xFF,sizeof(dic));
  memset(minarr,0xFF,sizeof(minarr));
  
  q.push(origin);
  while(!q.empty()){
   	u=q.front();
   	i=d[origin]-d[u];
   	if(minarr[u]==dic[i]){
  	  for(auto v=l[u].begin();v!=l[u].end();++v)
  	    if(d[u]==d[v->n]+1&&v->e<=dic[i+1]){//
		  dic[i+1]=v->e; 
		  if(v->n!=destin&&minarr[v->n]==0xFFFFFFFF) 
		    q.push(v->n);
		  //防止同一点被多次加入队列中
		  minarr[v->n]=v->e;
		  //对其最小值不断更新
	    }
	} 
	q.pop();
  }
  
  printf("%u",dic[1]);
  for(i=2;i<=d[origin];++i)
    printf(" %u",dic[i]);
  printf("\n");
}

unsigned i;

int main(){
  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);

  while(scanf("%u%u",&n,&m)==2){
  	l.clear();
  	l.resize(n+1);
  	memset(d,0xFF,sizeof(d));
  	d[n]=0;

    for(i=0;i<m;++i){
  	  unsigned u,v,e;
  	  scanf("%u%u%u",&u,&v,&e);
  	  l[u].push_back(Point{v,e});
  	  l[v].push_back(Point{u,e});
    }
    ShortestWay(n,1);
    PrintDic(1,n);
  }
  return 0;
}

