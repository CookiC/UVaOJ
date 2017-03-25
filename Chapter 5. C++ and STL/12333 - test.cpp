#include<cstdio>
#include<cstdlib>
#include<ctime>

int main(){
  freopen("test.in","w",stdout);
  srand(time(NULL));
  unsigned n=10000;
  printf("%u\n",n);
  for(unsigned i=0;i<n;++i){
  	unsigned m=rand()%8+1;
  	for(unsigned j=0;j<m;++j)
    	printf("%u",rand());
  	printf("\n");
  }
  return 0;
}

