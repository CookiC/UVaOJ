#include<cstdio>
#include<cstring>
#include<cstdlib>

bool find;
char c;
char b[21][21],s[21][21],ans[21][21];
short a[21][21];
int H[21];
unsigned n,K;

void Print(){
	int i;
	for(i=0;i<n;++i){
		b[i][n]=0;
		printf("%s\n",b[i]);
	}
}

void DFS(unsigned uz){
	//边界条件 
	int i,j;
	if(c-'A'==K){
		find=1;
		return;
	}
	
	//向后查找空位 
	while(b[uz/n][uz%n])
		++uz;
	int k,h,l,vx,vy,limx;
	int ux=uz/n;
	int uy=uz%n;
	
	vx=n;
	limx=n;
	for(i=uy;i<n&&!b[ux][i];++i){ 
		//当前元素高度小于之前最小元素的高度 则选取此人做组长
		if(vx>=H[i]){
			limx=vx;
			vx=H[i];
			vy=i;
			j=H[i];
			do{++j;}while(j<n&&!a[j][i]);
			if(limx>j)
				limx=j;
		}
		else if(limx>H[i])
			limx=H[i];
		
		//当此列有人能选为组长时 且能画出矩阵时
		if(vx<n&&a[vx][vy]%(i-uy+1)==0){
			l=i;
			h=a[vx][vy]/(i-uy+1)+ux-1;

			if(vx<=h&&h<limx){
				for(j=vx+1;j<n&&!a[j][vy];++j);
				H[vy]=j;
				for(j=ux;j<=h;++j)
					for(k=uy;k<=l;++k)
						b[j][k]=c;
				++c;
				DFS(ux*n+l+1);
				if(find)  return;
				--c;
				for(j=ux;j<=h;++j)
					for(k=uy;k<=l;++k)
						b[j][k]=0;
				H[vy]=vx;
			}
		}
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	int i,j;
	while(scanf("%u%u",&n,&K)!=EOF&&n&&K){
		//初始化L,H，并读入数据 
		memset(b,0,sizeof(b));
		for(i=0;i<n;++i){
			scanf("%s",s[i]);
			H[i]=n;
		}
		
		//转化s为a，初始化H
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				if(s[i][j]=='.')
					a[i][j]=0;
				else{
					a[i][j]=s[i][j]-'0';
					if(i<H[j])
						H[j]=i;
				}
		
		c='A';
		find=0;
		memset(ans,0,sizeof(ans));
		DFS(0);
		Print();
	}
	return 0;
}

