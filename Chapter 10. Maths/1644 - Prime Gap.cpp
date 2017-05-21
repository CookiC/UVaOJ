#include<cstdio>
#include<vector>
using namespace std;

const unsigned n=1299711;
bool vis[n]={0};
int i,j,pos;
unsigned t;
vector<unsigned> a;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	for(i=2;i<=n;++i)
		if(!vis[i]){
			for(j=2*i;j<=n;j+=i)
				vis[j]=1;
			a.push_back(i); 
		}
	while(scanf("%u",&t)!=EOF&&t){
		pos=lower_bound(a.begin(),a.end(),t)-a.begin();
		if(a[pos]==t)
			printf("0\n");
		else
			printf("%d\n",a[pos]-a[pos-1]);
	}
	return 0;
}

