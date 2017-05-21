#include<iostream>
#include<cmath>
#include<algorithm>
#define maxn 100010
using namespace std;

struct Seg{
	double l,r;
	bool operator < (const Seg &b){
		return r<b.r;
	}
};

int L,D,N;
Seg a[maxn];

Seg Dis(double x,double y){
	double l,r,z;
	z=sqrt(D*D-y*y);
	l=x-z<0?0:x-z;
	r=x+z>L?L:x+z;
	return Seg{l,r};
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	int ans,i,j;
	double x,y;
	while(cin>>L>>D>>N){
		for(i=0;i<N;++i){
			cin>>x>>y;
			a[i]=Dis(x,y);
		}
		sort(a,a+N);
	
		ans=0;
		for(i=0,j=0;i<N;i=j){
			++ans;
			while(j<N&&a[j].l<=a[i].r)
				++j;
		}
		cout<<ans<<endl;
	}
	return 0;
}

