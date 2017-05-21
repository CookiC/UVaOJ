#include<cstdio>
#include<algorithm>
using namespace std;

int T;
unsigned n,l,i,j,sum;
unsigned item[100010];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%u%u",&n,&l);
		for(i=0;i<n;++i)
			scanf("%u",&item[i]);
		sort(item,item+n);
		
		sum=0;
		i=0;
		j=n-1;
		while(i<j){
			if(item[i]+item[j]<=l)
				++i;
			--j;
			++sum;
		}
		if(i==j)
			++sum;
		printf("%u\n",sum);
		if(T!=0)
			printf("\n");
	}
	return 0;
}

