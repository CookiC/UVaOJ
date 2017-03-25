#include<iostream>
#include<cmath>
using std::cin;
using std::cout;

long long unsigned K,N,Sp,Sq;
unsigned i,j,A,B;

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  while(cin>>N>>Sp>>Sq)
  {
  	K=0xFFFFFFFFFFFFFFFF;
  	for(i=0;N*Sp<<11>(long long unsigned)1<<i&&i<=31;++i)
  	{  for(j=0;Sp+(Sp<<i)>>j>=Sq;++j)
  	  	if(((N-1)*Sp+((N-1)*Sp<<i)>>j)+Sq<K)
  	  	{
		  K=((N-1)*Sp+((N-1)*Sp<<i)>>j)+Sq;
		  A=i;
		  B=j;
	    }}
   	cout<<K<<' '<<A<<' '<<B<<'\n';
  }
  return 0;
}
