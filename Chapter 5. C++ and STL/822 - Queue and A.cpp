#include<cstdio>
#include<map>
#include<list>
#include<cstring>
#include<algorithm>
#define maxt 50100
using namespace std;

struct Task{
	unsigned tid,num,t0,t,dt;
	bool operator < (const Task &b) const{
		return tid<b.tid;
	}
};

struct Personnel{
	unsigned pid,k,tid[21];
	bool operator < (const Personnel &b) const{
		return pid<b.pid;
	}
};

Personnel per[6];
vector<unsigned> line[maxt];
unsigned n,m;
unsigned deal[21],curn[21],be[6];
bool busy[6];

void Read(){
  Task task[21];
  map<unsigned,unsigned> id;
	unsigned i,j;
	
	for(i=0;i<n;++i)
    scanf("%u%u%u%u%u",&task[i].tid,&task[i].num,&task[i].t0,&task[i].t,&task[i].dt);
	sort(task,task+n);
	for(i=0;i<n;++i){
	  id[task[i].tid]=i;
	  deal[i]=task[i].t;
	  for(j=0;j<task[i].num;++j)
	    line[task[i].t0+task[i].dt*j].push_back(i);
	} 
	//已将task全部加入时间线中，此时t0和dt和num可丢弃； 
	 
	scanf("%u",&m);
  for(i=0;i<m;++i){
    scanf("%u%u",&per[i].pid,&per[i].k);
    for(j=0;j<per[i].k;++j){
      scanf("%u",&per[i].tid[j]);
      per[i].tid[j]=id[per[i].tid[j]];
    }
	}
	sort(per,per+m);
}

void Update(unsigned t){
	for(auto it=line[t].begin();it!=line[t].end();++it)
		if(*it<100)
			++curn[*it];
		else
			busy[*it-100]=false;
}

void Check(unsigned t){
	unsigned i,j,q[5],qlen;
	j=0;
	for(i=0;i<m;++i)
	  if(!busy[i]){
		  q[j]=i;
			++j;
		}
	qlen=j;
	for(i=0;i<qlen;++i)
	  for(j=i+1;j<qlen;++j)
	    if(be[q[i]]>be[q[j]]||be[q[i]]==be[q[j]]&&q[i]>q[j]){
	    	unsigned t=q[i];
	    	q[i]=q[j];
	    	q[j]=t;
	    }

	for(i=0;i<qlen;++i){
		unsigned pid=q[i];
    Personnel &p=per[pid];
    for(j=0;j<p.k;++j){
    	unsigned tid=p.tid[j];
    	if(curn[tid]){
    		line[t+deal[tid]].push_back(pid+100);
    		--curn[tid];
    	  busy[pid]=true;
    	  be[pid]=t;
    		break;
    	}
    }
  }
};

unsigned i;

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(unsigned T=0;scanf("%u",&n)!=EOF&&n;++T){
	  for(i=0;i<maxt;++i)
      line[i].clear();
    memset(be,0,sizeof(be));
    memset(deal,0,sizeof(deal));
		memset(curn,0,sizeof(curn));
		memset(be,0,sizeof(be));
    memset(busy,0,sizeof(busy));
    Read();
    unsigned last;
    for(i=0;i<maxt;++i)
      if(line[i].size()!=0){
        Update(i);
        Check(i);
        last=i;
      }
		printf("Scenario %u: All requests are serviced within %u minutes.\n",T+1,last);
  }
  return 0;
}
