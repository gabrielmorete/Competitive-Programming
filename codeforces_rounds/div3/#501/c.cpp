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
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100; 

int n,m,dif[112345];  
ll tot,eco,val;

int main(){ 
	fastio; 
	cin>>n>>m; 
	int i,a,b;
	fr(i,n){
		cin>>a>>b; 
		dif[i]=a - b; 
		eco+=dif[i]; 
		tot+=a;
	} 
	if(tot-eco>m) 
		cout<<"-1"<<endl; 
	else if(tot<=m) 
		cout<<"0"<<endl;
	else{
		sort(dif,dif+n); 
		val=0;
		for(i=n-1;i>=0;i--){
			val+=dif[i]; 
			if(tot-val<=m) 
				break;
		}
		cout<<n-i<<endl;
		
	}
}