#include<cstdio>
#include<cmath>
#include<cstdlib>

const int dx[]={-1,-1,0,1,1,0},dy[]={-1,1,2,1,-1,-2};
const int bx[]={1,0,-1,-1,0,1},by[]={-1,-2,-1,1,2,1};

void GetCoord(unsigned num,int &x,int &y){
	if(num==1){
		x=0;
		y=0;
		return;
	}
	int m=(num+4)/6*2;
	int n=sqrt(m),i,j;
	if((n+1)*n<m)
		++n;
	i=num-n*(n-1)*3-1;
	j=(i-1)%n+1;
	i=(i-1)/n;
	x=bx[i]*n+j*dx[i];
	y=by[i]*n+j*dy[i];
//	printf("x=%d y=%d\n",x,y);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	int x1,y1,x2,y2,move;
	unsigned a,b;
	while(scanf("%u%u",&a,&b)!=EOF&&a){
		GetCoord(a,x1,y1);
		GetCoord(b,x2,y2);
		if(abs(x1-x2)<=abs(y1-y2))
			move=(abs(x1-x2)+abs(y1-y2))/2;
		else
			move=abs(x1-x2);
		printf("The distance between cells %u and %u is %d.\n",a,b,move);
	}
	return 0;
}


