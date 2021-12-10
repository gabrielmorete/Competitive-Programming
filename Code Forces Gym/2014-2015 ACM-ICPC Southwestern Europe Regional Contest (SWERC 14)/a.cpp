#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

int n, pos[300];
string s[11];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	fr(i, n){
		cin>>s[i];
		reverse(all(s[i]));
	}

	set<char> q;
	fr(i, n)
		for (auto x : s[i])
			q.insert(x);

	ll sob = 10 - q.size();	

	int p = 0;
	while (!q.empty()){
		pos[*q.begin()] = p++;
		q.erase(q.begin());
	}
			
	vector<ll> v;
	fr(i, 10)
		v.pb(i);

	int ans = 0;

	string notzero;
	fr(i, n)
		notzero.pb(s[i].back());

	do{
		bool ok = 1;	
		for (auto x : notzero)
			if (v[pos[x]] == 0)
				ok = 0;

		if (ok){	
			ll sum = 0;
			fr(i, n - 1){
				ll aux = 0, pwr = 1;
				fr(j, s[i].size()){
					aux += pwr * v[pos[s[i][j]]];
					pwr *= 10;
				}
				sum += aux;
			}

			ll tot = 0, pwr = 1;
			fr(j, s[n - 1].size()){
				tot += pwr * v[pos[s[n - 1][j]]];
				pwr *= 10;
			}

			if (sum == tot){
				ans++;
			}
		}

	} while (next_permutation(all(v)));


	ll f = 1;
	for (ll i = 1; i <= sob; i++)
		f *= i;

	cout<<ans/f<<endl;
}