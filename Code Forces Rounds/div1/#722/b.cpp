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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e6 + 10;
const ll mod = 998244353;

ll n, ans[MAXN], sum[MAXN], dv[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	ans[1] = 1; sum[1] = 1;
	ans[2] = 3; sum[2] = 4;
	ans[3] = 6; sum[3] = 10;

	dv[1] = 1;

	for (int i = 2; i <= n; i++){
		dv[i] += 2;
		for (int j = 2*i; j <= n; j += i)
			dv[j]++;

		ans[i] = (sum[i - 1] + dv[i]) % mod; // cobre todas as combinações anteriores
		sum[i] = (sum[i - 1] + ans[i]) % mod;
	}

	cout<<ans[n]<<endl;
}