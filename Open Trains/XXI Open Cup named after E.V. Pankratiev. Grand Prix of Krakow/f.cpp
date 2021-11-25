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
const int MAXN = 3e4 + 10;

int n;
char c;
string s, t;

int memo[MAXN][2][2][2];


bool pd(int pos, bool big, bool small, bool have){
	if (pos >= n){
		memo[pos][big][small][have] = big & small & have;
		return big & small & have;
	}

	int &pdm = memo[pos][big][small][have];

	if (pdm != -1)
		return pdm;
	pdm = 0;

	char ub = t[pos];
	char lb = s[pos];

	if (big) ub = 'z';
	if (small) lb = 'a';

	for (char a = lb; a <= ub; a++){
		bool isb = a < t[pos];
		bool ism = a > s[pos];
		bool isi = a == c;

		bool aux = pd(pos + 1, big | isb, small | ism, have | isi);
		pdm |= aux;
	}

	return pdm;
}

string ans;
void rec(int pos, bool big, bool small, bool have){
	if (pos >= n)
		return;

	char ub = t[pos];
	char lb = s[pos];

	if (big) ub = 'z';
	if (small) lb = 'a';

	for (char a = lb; a <= ub; a++){
		bool isb = a < t[pos];
		bool ism = a > s[pos];
		bool isi = a == c;

		if (memo[pos + 1][big | isb][small | ism][have | isi] == 1){
			ans.pb(a);
			rec(pos + 1, big | isb, small | ism, have | isi);
			return;
		}
	}
}

void solve(){
	cin>>n>>c;
	cin>>s>>t;

	fr(i, n + 1)
		fr(j, 2)
			fr(k, 2)
				fr(l, 2)
					memo[i][j][k][l] = -1;

	if (!pd(0, 0, 0, 0)){
		cout<<"NO"<<endl;
		return;
	}

	ans.clear();
	rec(0, 0, 0, 0);
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}	