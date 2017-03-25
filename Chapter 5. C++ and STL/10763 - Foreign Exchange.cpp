#include<cstdio>
#include<map>
using std::map;

unsigned n,i,u,v;
map<unsigned,unsigned> l,t;
bool pass;

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  while(scanf("%u",&n)==1&&n)
  {
  	pass=1;
  	l.clear();
  	t.clear();
  	for(i=0;i<n;++i)
  	{
  	  scanf("%u%u",&u,&v);
  	  if(!l.count(u))
  	    l[u]=0;
	  ++l[u];
	  if(!t.count(v))
	    t[v]=0;
	  ++t[v];
	}
	for(auto it=l.begin();it!=l.end();++it)
	  if(t[it->first]!=it->second)
	  {
	  	pass=0;
	  	break;
	  }
	if(pass)
	  printf("YES\n");
	else
	  printf("NO\n");
  }
  return 0;
}

