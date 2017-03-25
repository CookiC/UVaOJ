#include<cstdio>
#include<unordered_set>
using std::unordered_set;

int j;
unsigned n,i,T,m;
unsigned a[11],b[11],pro[11];
long long unsigned h;
unordered_set<long long unsigned> s;

unsigned awake()
{
  unsigned i,cou=0;
  for(i=0;i<n;++i)
    if(pro[i]<=a[i])
      ++cou;
  return cou;
}

long long unsigned hash()
{
  unsigned i;
  long long unsigned sum=0;
  for(i=0;i<n;++i)
  {
    sum*=11;
  	sum+=pro[i];
  }
  return sum;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(T=1;scanf("%u",&n)==1&&n;++T)
  {
  	s.clear();
	for(i=0;i<n;++i)
  	  scanf("%u%u%u",&a[i],&b[i],&pro[i]);
    
    for(j=1;s.find(h=hash())==s.end()&&(m=awake())!=n;++j)
    { 
	  s.insert(h);
      for(i=0;i<n;++i)
        if(pro[i]==a[i]&&n-m<=m)
          pro[i]=1;
        else
      	  pro[i]=pro[i]%(b[i]+a[i])+1;
	}
    if(awake()!=n)
      j=-1;
    printf("Case %u: %d\n",T,j);
  }
  return 0;
}

