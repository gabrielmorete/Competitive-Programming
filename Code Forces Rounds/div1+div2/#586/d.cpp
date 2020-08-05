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
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

ll v[212345], pwr[212345], freq[123];

int main(){
	fastio;
	ll n;
	cin>>n;

	fr(i,n)
		cin>>v[i];

	fr(i,n){
		ll aux = v[i];
		while (!(aux%2)){
			pwr[i]++;
			aux /= 2;
		}
		freq[pwr[i]]++;
	}

	ll bst = 0, p = 0;	
	fr(i,123)
		if (freq[i]>bst){
			bst = freq[i];
			p=i;
		}
			
	cout<<n-bst<<endl;		
	fr(i,n)
		if(pwr[i] != p)
			cout<<v[i]<<' ';
	gnl;	
				
}