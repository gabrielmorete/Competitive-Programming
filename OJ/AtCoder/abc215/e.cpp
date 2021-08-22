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


string s;
int n;

ll memo[1010][1<<10][11];

ll pd(int pos, int msk, int lst){
	if (pos >= n)
		return msk != 0; // tem que pegar alguem

	ll &pdm = memo[pos][msk][lst];
	if (pdm != -1)
		return pdm;

	pdm = pd(pos + 1, msk, lst); // faz nada

	if (lst == (s[pos] - 'a')) // sou o ultimo
		pdm = (pdm + pd(pos + 1, msk, lst)) % mod; // posso me colocar

	int x = s[pos] - 'a';

	if ((msk&(1<<x)) == 0) // me coloco
		pdm = (pdm + pd(pos + 1, msk + (1<<x), x)) % mod;
	

	return pdm;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>s;

	memset(memo, -1, sizeof memo);

	cout<<pd(0, 0, 10)<<endl;
}