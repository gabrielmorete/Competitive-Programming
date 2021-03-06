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
//cout << setprecision(9)<<fixed;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;
 
ll MAXN;
ll v[100100];
ll bit[100100];
ll bit2[100100];
 
void change(ll ind, ll x){
	for(int i=ind;i<MAXN;i+=i&-i)
		bit[i]+=x;
}
 
void change2(ll ind, ll x){
	for(int i=ind;i<MAXN;i+=i&-i)
		bit2[i]+=x;
}
 
ll sum(ll ind){
	ll ret = 0;
	for(int i = ind; i>0; i-=i&-i){
		ret += bit[i];
	}
	return ret;
}
 
ll sum2(ll ind){
	ll ret = 0;
	for(int i = ind; i>0; i-=i&-i){
		ret += bit2[i];
	}
	return ret;
}
 
 
int main(){
	fastio;
	ll n;
	cin >> n;
	MAXN = n;
	fr(i,n) {
		cin >> v[i];
	}
	ll ans = 0;
	for(int i = n-1; i>=0; i--){
		ll o = 0;
		change(v[i],1);
		if(v[i] > 1){
			o = sum(v[i]-1);
			change2(v[i], o);
			if(o>1){
				ans += sum2(v[i]-1);
			}
		}
	
		
	}
	cout << ans << "\n";
 
}