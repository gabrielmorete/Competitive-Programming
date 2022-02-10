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
typedef vector<ll> vll;


const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

const ll mod1 = 1000015553;
const ll mod2 = 1000028537;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
static ll p = uniform_int_distribution<int>(31, mod1 - 1)(rng);

struct str_hash{
	string s; 
	ll n;
	vector<ll> hsh1, pwr1, hsh2, pwr2;

	str_hash(string _s) : n(_s.size()), s(_s), hsh1(n), pwr1(n), hsh2(n), pwr2(n){	
		pwr1[0] = pwr2[0] = 1;
		for (int i = 1; i < n; i++){
			pwr1[i] = (p * pwr1[i - 1]) % mod1;
			pwr2[i] = (p * pwr2[i - 1]) % mod2;
		}
		hsh1[0] = hsh2[0] = s[0] - 'a' + 1;
		for (int i = 1; i < n; i++){
			hsh1[i] = (hsh1[i - 1] * p + (ll)(s[i] - 'a' + 1))%mod1;
			hsh2[i] = (hsh2[i - 1] * p + (ll)(s[i] - 'a' + 1))%mod2;
		}
	}
	ll operator()(int i, int j){ 
		if (i == 0) return hsh1[j] ^ (hsh2[j]<<30);
		ll ret1 = ((hsh1[j] - (hsh1[i - 1] * pwr1[j - i + 1])) % mod1 + mod1) % mod1;
		ll ret2 = ((hsh2[j] - (hsh2[i - 1] * pwr2[j - i + 1])) % mod2 + mod2) % mod2;
		return ret1 ^ (ret2<<30);
	}
};

vector<int> lps_p(vll &pat){
	int i = 1, len = 0, tam = (int)pat.size();
	vector<int> lps(tam, 0);
	lps[0] = 0;

	while (i < tam){
		if (pat[i] == pat[len])
			lps[i++] = ++len;
		else if (len != 0)
			len = lps[len - 1];
		else
			lps[i++] = 0;
	}

	return lps;
}

vector<int> lps;

int check(vll &txt, vll &pat){
	int i = 0, j = 0, tt = (int)txt.size(), tp = (int)pat.size(), ans = 0;

	while(i < tt){
		if (txt[i] == pat[j]) 
			i++, j++;
		if (j == tp) 
			ans++, j = lps[j-1];
		else if (i < tt and txt[i] != pat[j]){
			if (j == 0) 
				i++;
			else 
				j = lps[j-1];
		}
	}

	return ans;
}

int a, b, c, d;
vll pat, obra[MAXN];
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (cin>>a>>b>>c>>d){
		pat.clear();
		fr(i, d)
			obra[i].clear();

		fr(i, a){
			string s;
			cin>>s;
			str_hash hsh(s);

			pat.pb(hsh(0, b - 1));
		}

		fr(i, c){
			string s;
			cin>>s;
			str_hash hsh(s);

			for (int j = 0; j + b - 1 < d; j++)
				obra[j].pb(hsh(j, j + b - 1));
		}

		lps = lps_p(pat); // sempre o mesmo padrão

		int ans = 0;
		for (int j = 0; j + b - 1 < d; j++)
			ans += check(obra[j], pat);

		cout<<ans<<endl;
	}
}