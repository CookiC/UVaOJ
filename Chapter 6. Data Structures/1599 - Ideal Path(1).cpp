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
  	    //��ֹ��ͬһ���β��� ��ȡ��һ�β�����ֵ 
  	    //һ����������� 
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
	//�ҳ���ǰ����Сֵ
    if(i+1>=d[origin])
      break;
    //���Ϊ���һ����Ļ������µ��յ����С·������
	 
    unsigned mid=rear;
    for(j=front;j<mid;++j){
   	  u=q[j];
  	  for(auto v=l[u].begin();v!=l[u].end();++v)
  	    if(!arrive[v->n]&&d[u]==d[v->n]+1&&v->e==dic[i]){
  	      q[rear]=v->n;
  	      arrive[v->n]=true;
  	      //��ֹͬһ�����μ�������У�
		  //��ͬһ�����μ�������н�����
		  //O(·����^ͬһ����)��ʱ�临�Ӷ� 
  	      ++rear;
  	    }
    }
    //�����ڵ�ǰ·����Сֵ������������ 
    front=mid;
    //�����һ�� 
  }

  printf("%u",dic[0]);
  for(i=1;i<d[origin];++i)
    printf(" %u",dic[i]);
  printf("\n");
}

//Ŀǰֻ�����ֿ��ܣ����з�������ֵ����������
 
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

