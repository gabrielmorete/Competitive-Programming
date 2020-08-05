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
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

int n, freq[MAXN];
vi v;

int32_t main(){
	fastio;
	cin>>n;
	
	int x;
	fr(i, n){
		cin>>x;
		v.pb(x);
	}
	sort(all(v));

	int mn, mx;
	mn = mx = 0;

	//minimo
	for (auto x : v){
		if (freq[x] or freq[x - 1] or freq[x + 1])
			continue;
		freq[x + 1] = 1;
		mn++;
	}

	fill(freq, freq + MAXN, 0);

	for (auto x : v){
		if (!freq[x - 1]){
			freq[x - 1] = 1;
			mx++;
		} else if (!freq[x]){
			freq[x] = 1;
			mx++;
		} else if (!freq[x + 1]){
			freq[x + 1] = 1;
			mx++;
		}			
	}
	cout<<mn<<' '<<mx<<endl;

}