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
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;
 
vi v[312345];
bool vis[312345];
int n, q;
 
int t[600100];
 
void modify(int p, int value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
 
int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
 
int main(){
    int app;
	
    cin>>app>>q;
    n = q;

	int tp, a, sz, read;
	sz = read = 0;
	frr(i,q){
		cin>>tp>>a;
		if (tp == 1){
			sz++;
			v[a].pb(sz);
			cout<< sz - read - query(read + 1, sz + 1)<<endl;
		}
		else if (tp == 2){
			while (!v[a].empty()){
                modify( v[a].back(), 1);
                v[a].pop_back();
            }
            
			cout<< sz - read  - query(read + 1, sz + 1)<<endl;
		}
		else{
			read = max(read, a);
			cout<< sz - read - query(read + 1, sz + 1)<<endl;
		}
	}
}