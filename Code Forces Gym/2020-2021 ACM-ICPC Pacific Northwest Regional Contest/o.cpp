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
const int MAXN = 1e5 + 10;
const ll mod = 998244353;

string low, up;

ll memo[MAXN][14][2][2], n;

ll pd(int p, int lst, int menor, int maior){
	if (p >= n)
		return 1;

	ll &pdm = memo[p][lst][menor][maior];
	if (pdm != -1)
		return pdm;

	pdm = 0;

	int l = low[p] - '0';
	int r = up[p] - '0';

	if (menor)// já sou menor
		r = 9;
	if (maior)
		l = 0;

	for (int i = l; i <= r; i++){
		if (i != lst){
			bool men = menor|(i < (int)(up[p] - '0')); 
			bool mai = maior|(i > (int)(low[p] - '0'));
			pdm = (pdm + pd(p + 1, i, men, mai)) % mod;
		}
	}

	return pdm;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>low>>up;

	reverse(all(low));

	while (low.size() < up.size())
		low.pb('0');
	reverse(all(low));

	n = up.size();

	memset(memo, -1, sizeof memo);

	cout<<pd(0, 11, 0, 0)<<endl;
}