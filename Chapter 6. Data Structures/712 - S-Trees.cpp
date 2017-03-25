#include<cstdio>
#include<cstring>

unsigned n,m,i,j;
unsigned tree[10],value[10];
char str[10],leaf[200];

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);

  for(unsigned T=1;scanf("%u",&n)!=EOF&&n;++T){
    printf("S-Tree #%u:\n",T);
		for(i=0;i<n;++i){
      scanf("%s",str);
      sscanf(&str[1],"%u",&tree[i]);
    }
    scanf("%s",leaf);
    scanf("%u",&m);
    for(i=0;i<m;++i){
  	  unsigned k=0;
		  scanf("%s",str);
  	  for(j=0;j<n;++j)
  	    value[j+1]=str[j]-'0';
  	  for(j=0;j<n;++j)
  	    k=k*2+value[tree[j]];
  	  printf("%c",leaf[k],k);
	  }
	  printf("\n\n");
	}
  return 0;
}

