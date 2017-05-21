#include<cstdio>
#include<cmath>

double a,b,c;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%lf%lf%lf",&a,&b,&c);
	double p=(a+b+c)/2;
	double S=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.3lf\n",S);
	return 0;
}

