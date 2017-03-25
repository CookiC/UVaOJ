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
	//�߽����� 
	int i,j;
	if(c-'A'==K){
		find=1;
		return;
	}
	
	//�����ҿ�λ 
	while(b[uz/n][uz%n])
		++uz;
	int k,h,l,vx,vy,limx;
	int ux=uz/n;
	int uy=uz%n;
	
	vx=n;
	limx=n;
	for(i=uy;i<n&&!b[ux][i];++i){ 
		//��ǰԪ�ظ߶�С��֮ǰ��СԪ�صĸ߶� ��ѡȡ�������鳤
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
		
		//������������ѡΪ�鳤ʱ ���ܻ�������ʱ
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
		//��ʼ��L,H������������ 
		memset(b,0,sizeof(b));
		for(i=0;i<n;++i){
			scanf("%s",s[i]);
			H[i]=n;
		}
		
		//ת��sΪa����ʼ��H
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

