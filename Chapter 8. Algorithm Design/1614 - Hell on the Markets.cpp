#include<iostream>
#include<cstring>
#include<algorithm>
#include<functional>
#define maxn 100010
using namespace std;

int b[maxn];
unsigned a[maxn],num[maxn];

bool cmp(unsigned x,unsigned y){
	return a[x]>a[y];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	int i;
	unsigned n,sum;
	ios::sync_with_stdio(false);
	while(cin>>n){
		sum=0;
		for(i=0;i<n;++i){
			cin>>a[i];
			sum+=a[i];
			num[i]=i;
		}
		if(sum%2){
			cout<<"No\n";
			continue;
		}
		else
			cout<<"Yes\n";
		sort(num,num+n,cmp);
		sum/=2;
		for(i=0;i<n;++i)
			if(sum>=a[num[i]]){
				sum-=a[num[i]];
				b[num[i]]=1;
			}
			else
				b[num[i]]=-1;
		for(i=0;i<n-1;++i)
			cout<<b[i]<<' ';
		cout<<b[n-1]<<'\n';
	}
	return 0;
}

