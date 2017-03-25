#include<cstdio>
#include<queue>
using namespace std;

unsigned n,i,T;
queue<unsigned> q;

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(T=0;scanf("%u",&n)==1&&n;++T)
  {
  	while(!q.empty())
	  q.pop();
	for(i=1;i<=n;++i)
	  q.push(i);

	printf("Discarded cards:");
	while(q.size()>1)
	{
	  printf(" %u",q.front());
	  if(q.size()>2)
	    printf(",");
	  q.pop();
	  q.push(q.front());
	  q.pop();
    }
    printf("\n");
    
    printf("Remaining card: %u\n",q.front());
  }
  return 0;
}

