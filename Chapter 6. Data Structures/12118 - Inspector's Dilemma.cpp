#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int i;
unsigned V,E,T,j,cnt;
unsigned uFind[1010];
vector<unsigned> u[1010],q;
bool inG[1010];

unsigned find(unsigned x){
	return uFind[x]==x?x:uFind[x]=find(uFind[x]);
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(unsigned K=1;scanf("%u%u%u",&V,&E,&T)!=EOF&&V;++K){
  	for(i=1;i<=V;++i){
  	  uFind[i]=i;
  	  u[i].clear();
  	  inG[i]=false;
  	}
  	q.clear();
  	
    for(i=0;i<E;++i){
  	  unsigned ut,vt;
  	  scanf("%u%u",&ut,&vt);
  	  u[ut].push_back(vt);
  	  u[vt].push_back(ut);
  	  inG[ut]=true;
  	  inG[vt]=true;
  	  unsigned x=find(ut);
  	  unsigned y=find(vt);
  	  uFind[x]=y;
    }
//    for(i=1;i<=V;++i)
//      printf("%u:%u ",i,uFind[i]);
//    printf("\n");
    
		j=2;
    while(j>1){
    	unsigned last;
    	j=0;
    	
      for(i=1;i<=V;++i){
//      	printf("i:%u\n",i);
        if(inG[i]&&u[find(i)].size()%2==0&&u[i].size()%2==1){
        	unsigned t=find(i);
        	uFind[t]=i;
        	uFind[i]=i;
			  }
			}
		  for(i=1;i<=V;++i)
		    if(inG[i]&&uFind[i]==i){
		    	++j;
//		    	printf("j:%u\n",j);
		    	if(j%2==1)
		    	  last=i;
		    	else{
		    		u[i].push_back(last);
		    		u[last].push_back(i);
		    		uFind[last]=i;
					}
				}
		}
		
		for(i=1;i<=V;++i)
		  if(inG[i]&&u[i].size()%2==1){
		    q.push_back(i);
//		    printf("(%u,%u) ",i,u[i].size());
		  }
//		printf("\n");
		for(i=q.size()-1;i>=2;i-=2){
			u[q[i]].push_back(q[i-1]);
			u[q[i-1]].push_back(q[i]);
//			printf("i:%d\n",i);
		}
		
		cnt=0;
		for(i=1;i<=V;++i)
		  if(inG[i])
		    cnt+=u[i].size();
		printf("Case %u: %u\n",K,cnt/2*T);
	}
  return 0;
}

