#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

unsigned N,n,m,k,t1,t2,t3,len,T,i,j,h;

int main(){
  freopen("test.in","w",stdout);

  srand(time(NULL));
  N=rand()%100+1;
  for(h=0;h<N;++h){
    n=rand()%5+5;
    m=rand()%(30-n)+n;
    T=1;//rand()%12+1;
    t1=rand()%20+1;
    t2=rand()%30+1;
    t3=rand()%30+1;
    k=rand()%100+1;
    cout<<n<<' '<<m<<' '<<T<<' '<<t1<<' '<<t2<<' '<<t3<<' '<<k<<endl;
    for(i=0;i<k;++i){
	    len=rand()%8+1;
	    char c='A'+rand()%24;
	    cout<<c;
      for(j=1;j<len;++j){
      	c='a'+rand()%24;
        cout<<c;
      }
      cout<<endl;
      cout<<rand()%100<<' '<<rand()%100<<endl;
    }
  }
  return 0;
}

