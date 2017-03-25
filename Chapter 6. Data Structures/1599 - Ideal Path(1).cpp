#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define maxn 100050
using namespace std;

struct Point{
  unsigned n,e;
};

unsigned n,m;
unsigned d[maxn];
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
}

void PrintDic(const unsigned origin,const unsigned destin){
  unsigned dic[maxn],i,j,u;
  bool arrive[maxn]={0};
  unsigned q[maxn],front=0,rear=0;
  memset(dic,0xFF,sizeof(dic));

  q[rear]=origin;
  ++rear;
  for(i=0;i<d[origin];++i){
    for(j=front;j<rear;++j){
   	  u=q[j];
  	  for(auto v=l[u].begin();v!=l[u].end();++v)
  	    if(d[u]==d[v->n]+1&&v->e<dic[i]) 
  	      dic[i]=v->e;
    }
	//找出当前层最小值
    if(i+1>=d[origin])
      break;
    //如果为最后一个点的话仅更新到终点的最小路径即可
	 
    unsigned mid=rear;
    for(j=front;j<mid;++j){
   	  u=q[j];
  	  for(auto v=l[u].begin();v!=l[u].end();++v)
  	    if(!arrive[v->n]&&d[u]==d[v->n]+1&&v->e==dic[i]){
  	      q[rear]=v->n;
  	      arrive[v->n]=true;
  	      //防止同一个点多次加入队列中，
		  //若同一个点多次加入队列中将会有
		  //O(路径长^同一点数)的时间复杂度 
  	      ++rear;
  	    }
    }
    //若等于当前路径最小值，则加入队列中 
    front=mid;
    //清空上一层 
  }

  printf("%u",dic[0]);
  for(i=1;i<d[origin];++i)
    printf(" %u",dic[i]);
  printf("\n");
}

//目前只有两种可能，换行符错误和字典序输出错误
 
unsigned i;

int main(){
//  freopen("test.in","r",stdin);
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
    
    printf("%u\n",d[1]);  
    PrintDic(1,n);
  }
  return 0;
}

