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

ll memo[110][40];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int j = 0; j < 40; j++)
		memo[0][j] = 1;

	for (int j = 2; j < 31; j++){ // prize
		ll sum = 1;
		for (int i = 1; i < 101; i++){ // max loss
			ll cur = sum/(j - 1);
			while ((j - 1) * cur <= sum)
				cur++;

			sum += cur;

			memo[i][j] = min(sum, 1000000001ll);
			if (sum > 1000000000ll)
				break;
		}

		for (int i = 1; i < 101; i++)
			memo[i][j] = max(memo[i][j], memo[i - 1][j]);
	}

	// fr(i, 100)
	// 	dbg(memo[i][13]);

	// return 0;	

	// chapa;
	int T;
	cin>>T;

	while (T--){
		ll k, x, a;
		cin>>k>>x>>a;

		if (memo[x][k] <= a)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

}