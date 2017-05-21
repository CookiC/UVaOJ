#include<cstdio>
#include<cmath>

int i;
unsigned n;
double xa,xb,ya,yb,dt,d,s;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	while(scanf("%u",&n)!=EOF&&n){
		scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
		s=0;
		d=0;
		for(i=0;i<n;++i){
			scanf("%lf",&dt);
			d+=dt;
			s+=dt*dt;
		}
		double c=d*sqrt(2);
		double tan1=ya/xa;
		double tan2=yb/xb;
		double tanc=(tan1-tan2)/(1+tan1*tan2);
		double sinc=1/sqrt(1+1/(tanc*tanc));
		double tana=(1+tan2)/(1-tan2);
		double sina=1/sqrt(1+1/(tana*tana));
		tan1=1/tan1;
		double tanb=(1+tan1)/(1-tan1);
		double sinb=1/sqrt(1+1/(tanb*tanb));
		double a=c/sinc*sina;
		double b=c/sinc*sinb;
//		printf("a=%.3lf b=%.3lf c=%.3lf\n",a,b,c);
		double S=a*c*sinb/2;
		S=S-s/2;
		printf("%.3lf\n",S);
	}
	return 0;
}

