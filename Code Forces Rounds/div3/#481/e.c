#include<stdio.h> 
int n,w,x;
int main(){
	int i,a,max=0,min=0; 
	scanf("%d",&n); 
	scanf("%d",&w); 
	for(i=0;i<n;i++){ 
			scanf("%d",&a); 
			x+=a; 
			if(x>max) 
				max=x; 
			if(x<min) 
				min=x; 
	}	
 if(max>w) 
		printf("0\n"); 
	else{ 
		if(min+(w-max+1)>0)
			printf("%d\n",min+(w-max+1)); 
		else 
			printf("0\n");
	}
	return 0;
}