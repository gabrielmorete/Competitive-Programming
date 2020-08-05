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

int v[MAXN], com[MAXN], fim[MAXN];

int32_t main(){
	fastio;
	int n;
	cin>>n;

	fr(i, n)
		cin>>v[i];

	fim[0] = 1;
	frr(i, n - 1){
		if (v[i] > v[i - 1])
			fim[i] = fim[i - 1] + 1;
		else
			fim[i] = 1;		
	}

	int ans = 1;
	com[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--){
		if (v[i] < v[i + 1])
			com[i] = com[i + 1] + 1;
		else
			com[i] = 1;
		ans = max(ans, com[i]);
	}
	
	for (int i = 2; i < n - 1; i++)
		if (v[i - 1] < v[i + 1])
			ans = max(ans, fim[i - 1] + com[i + 1]);

	cout<<ans<<endl;	
}