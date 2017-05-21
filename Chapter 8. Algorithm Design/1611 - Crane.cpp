#include<cstdio>
#include<cstdlib>

int T;
unsigned i,j,n,sum;
unsigned a[10010],p[40020];

void Exchange(unsigned *a,unsigned *b,unsigned n){
	unsigned t,i;
	for(i=0;i<n;++i){
		t=a[i];
		a[i]=b[i];
		b[i]=t;
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	scanf("%d",&T);
	while(T--){
		scanf("%u",&n);
		for(i=1;i<=n;++i)
			scanf("%u",&a[i]);
			
		sum=0;
		for(i=1;i<n;++i){
			if(a[i]==i)
				continue;
			for(j=i+1;i!=a[j];++j);
			if(n-j>=j-i-1)
				Exchange(&a[i],&a[j],j-i);
			else{
				unsigned len=(j-i-1)/2;
				Exchange(&a[j-len*2-1],&a[j-len],len+1);
				p[sum]=j-len*2-1;
				p[sum+1]=j;
				sum+=2;
				j-=len+1;
				Exchange(&a[i],&a[j],j-i);
			}
			p[sum]=i;
			p[sum+1]=2*j-i-1;
			sum+=2;
		}
		printf("%d\n",sum/2);
		for(i=0;i<sum;i+=2){
			printf("%u %u\n",p[i],p[i+1]);
		}
	}
	return 0;
}

