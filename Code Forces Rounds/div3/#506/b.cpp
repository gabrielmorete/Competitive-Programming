#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

#define MAX 312345


int main(){
	int n,mx,v[MAX]; 
	fastio; 
	cin>>n; 
	fr(i,n) 
		cin>>v[i];
	mx=1;
	int last =-1;	
	if(n>1){	
		for(i=1;i<n;i++){
			if(last==-1){
				if(v[i]<=2*v[i-1]){
					mx++;	
				}
			}
			if(v[i]<=2*v[i-1])
				mx++;

		}

	}	
	cout<<mx<<endl;
	return 0;
}