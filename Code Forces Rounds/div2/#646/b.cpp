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
const int MAXN = 1e3 + 10;
const ll mod = 1e9+7;

void solve(){
	string s;
	cin>>s;

	int n = s.size();

	int zero[MAXN], um[MAXN];
	
	fill(zero, zero + MAXN, 0);
	fill(um, um + MAXN, 0);

	frr(i, n){
		if (s[i - 1] == '0')
			zero[i]++;
		else
			um[i]++;
	}

	frr(i, n){
		zero[i] += zero[i - 1];
		um[i] += um[i - 1];
	}

	int ans = min(zero[n], um[n]);


	frr(i, n){
		ans = min(ans, um[i] + zero[n] - zero[i]);
		ans = min(ans, zero[i] + um[n] - um[i]);
	}

	cout<<ans<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}