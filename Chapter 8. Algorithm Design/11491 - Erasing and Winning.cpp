#include<cstring>
#include<string>
#include<cstdlib>

unsigned N,D,i,top;
char c;
char stk[100010];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	while(scanf("%u%u",&N,&D)!=EOF&&(N||D)){
		getchar();
		top=0;
		
		for(i=0;i<N;++i){
			c=getchar();
			while(top&&D&&c>stk[top-1]){
				--D;
				--top;
			}
			stk[top++]=c;
		}
		for(i=0;i<top-D;++i)
			printf("%c",stk[i]);
		printf("\n");
	};
	return 0;
}

