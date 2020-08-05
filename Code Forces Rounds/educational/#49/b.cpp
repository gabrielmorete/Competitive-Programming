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
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

ll x,y,n;

void par(){
	ll cnt;
	cnt=((x-1ll)/2ll)*( (n+1ll)/2ll+(n)/2ll);

	if(x%2ll==0ll){
		cnt+=(n+1ll)/2ll;
		cnt+=(y)/2ll;
	}
	else{
		cnt+=(y+1ll)/2ll;
	}

	cout<<cnt<<endl;

}

void impar(){
	ll cnt;

	cnt=((x-1ll)/2ll)*((n+1ll)/2ll+(n)/2ll);

	if(x%2ll==0){
		cnt+=(n)/2ll;
		cnt+=(y+1ll)/2ll;
	}
	else{
		cnt+=(y)/2ll;
	}

	cout<<cnt+(n*n+1ll)/2ll<<endl;
}

int main(){
	fastio;
	int q;
	cin>>n>>q;

	fr(i,q){
		cin>>x>>y;
		if((x+y)%2ll)
			impar();
		else 
			par();
	}	
}