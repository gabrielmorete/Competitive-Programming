#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e7 + 10;
const ll mod = 1e9+7;

int lp[MAXN];
vi pr;

void crivo(){
	for (int i = 2; i <= MAXN; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j = 0; j < (int)pr.size() && pr[j]<=lp[i] && i*pr[j] <= MAXN; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}

void solve(int n){
	for (auto x : pr){
		if (lp[n - x] == n - x){
			cout<<x<<' '<<n - x<<endl;
			return;
		}
	}
}

int32_t main(){
	fastio;

	crivo();

	int n;
	while (cin>>n){
		if (n < 8){
			cout<<"Impossible."<<endl;
			continue;
		}

		if (n % 2){
			cout<<2<<' '<<3<<' ';
			solve(n - 5);
		}
		else{
			cout<<2<<' '<<2<<' ';
			solve(n - 4);
		}
	}

}