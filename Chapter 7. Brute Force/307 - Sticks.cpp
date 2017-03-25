#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
using namespace std; 

bool b[110];
unsigned n,H,ans;
unsigned a[250];

bool DFS(unsigned h,unsigned num,unsigned l){
	int i;
	if(num==1)
		return true;
	unsigned pre=-1;
	for(i=l;i<n;++i)
		if(!b[i]&&a[i]!=pre){
			pre=a[i];
			if(a[i]<h){
				b[i]=1;
				if(DFS(h-a[i],num,i+1))
					return true;
				b[i]=0;
				if(h==H)
					break;
			}
			else if(a[i]==h){
				b[i]=1;
				if(DFS(H,num-1,0))
					return true;
				b[i]=0;
				break;
			}
		}
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	int i,j,k;
	unsigned sum;
	while(scanf("%u",&n)!=EOF&&n){
		sum=k=0;
		for(i=0;i<n;++i){
			scanf("%d",&a[i]);
			sum+=a[i];
			if(a[i]>k)
				k=a[i];
		}
		
		sort(a,a+n,greater<unsigned>());
//		printf("%d\n",k);
		for(i=k;i<=sum;++i)
			if(sum%i==0){
				memset(b,0,sizeof(b));
				if(DFS(H=i,sum/i,0))
					break;
			}
		printf("%u\n",H);
	}
	return 0;
}

