#include<iostream>
using namespace std;

unsigned n,i,j,cnt;
unsigned a[400],b[400];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	while(scanf("%u",&n)!=EOF&&n){
		for(i=1;i<=n;++i)
			scanf("%u",&b[i]);
		for(i=1;i<=n;++i)
			a[b[i]]=i;
		cnt=0;
		for(i=1;i<=n;++i)
			for(j=i+1;j<=n;++j)
				if(a[i]>a[j])
					++cnt;
		
		while(cnt){
			if(cnt==1&&a[1]>a[2]){
				printf("1");
				break;
			}
			for(i=1;i<n;++i){
				if(a[i]>a[i+1]){
					unsigned t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
					printf("1");
					--cnt;
				}
				printf("2");
			}
			printf("2");
		}
		printf("\n");
	}
	return 0;
}

