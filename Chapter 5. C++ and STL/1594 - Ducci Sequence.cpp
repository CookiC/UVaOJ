#include<cstdio>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

unsigned T,n,i;
int e;
vector<int> rec;
set<vector<int>> tab;

vector<int> next(const vector<int> &rec)
{
  vector<int> t;
  t.resize(rec.size());
  for(unsigned i=0;i<n;++i)
    t[i]=abs(rec[i]-rec[(i+1)%n]);
  return t;
}

int recsum(const vector<int> &rec)
{
  int sum=0;
  for(auto i=rec.begin();i!=rec.end();++i)
    sum+=*i;
  return sum;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  scanf("%u",&T);
  while(T--)
  {
  	rec.clear();
  	tab.clear();
  	
  	scanf("%u",&n);
  	for(i=0;i<n;++i)
  	{
  	  scanf("%d",&e);
  	  rec.push_back(e);
	}
	
	while(tab.find(rec)==tab.end()&&recsum(rec))
	{
	  tab.insert(rec);
	  rec=next(rec);
	}
    if(recsum(rec))
      printf("LOOP\n");
    else
      printf("ZERO\n");
  }
  return 0;
}

