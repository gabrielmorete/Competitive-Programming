#include<bits/stdc++.h> 
using namespace std;
char st1[212345],st2[212345]; 

int main(){
	int t1,t2,i,p1,p2,dif; 
	scanf(" %s",st1); 
	scanf(" %s",st2); 
	p1=t1=strlen(st1); 
	p2=t2=strlen(st2);  
	p1--; 
	p2--; 
	dif=0;
	while(p1>=0 && p2 >=0){
		if(st1[p1]==st2[p2]){
			p1--; 
			p2--;
		} 
		else{
			dif+=p1+p2+2; 
			break;
		}

	} 
	if(dif==0){ 
		if(p1>=0){
			dif=p1+1;
		} 
		else if(p2>=0){
			dif=p2+1;
		}
	}
	printf("%d\n",dif);
	return 0;	
}	