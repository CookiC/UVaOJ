#include<cstdio>
#include<queue>
using namespace std;

struct Task{
  unsigned  num,pri;
  bool operator <(const Task b) const{ 
    return pri<b.pri;
  }
};

int T;


int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  scanf("%d",&T);
  while(T--){
    queue<Task> q;
    priority_queue<unsigned> maxpri;
    unsigned n,m,time;

    scanf("%u%u",&n,&m);
    for(unsigned i=0;i<n;++i){
      Task t;
      scanf("%u",&t.pri);
      t.num=i;
      maxpri.push(t.pri);
      q.push(t);
    }
    
    time=0;
    bool inque=true;
    while(!q.empty()&&inque){
	  while(q.front().pri<maxpri.top()){
	    q.push(q.front());
	    q.pop();
      }
      if(q.front().num==m)
        inque=false;
      q.pop();
      maxpri.pop();
      ++time; 
	}
	printf("%u\n",time);
  }
  return 0;
}

