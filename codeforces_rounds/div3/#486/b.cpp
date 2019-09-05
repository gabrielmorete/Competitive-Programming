#include<bits/stdc++.h> 
using namespace std; 
char m[123][123];
int n;
pair<int,int> a[123]; 

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first < j.first;
}  
bool lll(int i,int j,int t){
	int k; 
	if(t+strlen(m[i])>strlen(m[j])) 
		return 0;  
	for(k=0;m[i][k]!=0;k++) 
			if(m[i][k]!=m[j][k+t]){ 
				return 0; 
			}
	return 1;
}
bool comp(int i,int j){
	int t;
	for(t=0;m[j][t]!=0;t++){ 
		if(m[i][0]==m[j][t]){ 
			if(lll(i,j,t)==1) 
				return 1;
		}
	}
	return 0;
}
int main(){ 
	int i,ok=1;
	scanf("%d",&n); 
	for(i=0;i<n;i++){ 
		scanf(" %s",&m[i]); 
		a[i].first=strlen(m[i]); 
		a[i].second=i;
	} 
	sort(a,a+n,compare); 
	for(i=0;i<n-1&&ok==1;i++) 
		if(comp(a[i].second,a[i+1].second)==0)  
			ok=0;
	if(ok==0) 
		printf("NO\n"); 
	else{
		printf("YES\n"); 
		for(i=0;i<n;i++) 
			printf("%s\n",m[a[i].second] );
	} 

	return 0;	
}	