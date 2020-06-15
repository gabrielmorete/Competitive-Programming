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
const int MAXN = 1e6 + 10;

int d1[MAXN], d2[MAXN];// # de palindromos centrados em i
int pal[2 * MAXN];	// pal[2i], maior palindromo centrado em i, 
					//pal[2i + 1] maior palindromo centrado em i e i + 1

void manacher(string &s){
	int n = s.size();
	for (int i = 0, l = 0, r = -1; i < n; i++){
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    	while (0 <= i - k and i + k < n and s[i - k] == s[i + k]) {
    	    k++;
    	}

    	d1[i] = k--;
    	if (i + k > r) {
    	    l = i - k;
		    r = i + k;
		}
	}

	for (int i = 0, l = 0, r = -1; i < n; i++) {
	    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
	    while (0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k]) {
	        k++;
	    }

	    d2[i] = k--;
	    
	    if (i + k > r) {
	        l = i - k - 1;
    		r = i + k ;
    	}
	}
	for (int i = 0; i < n; i++)
		pal[2 * i] = 2 * d1[i] + 1;
	for (int i = 0; i < n; i++)
		pal[2 * i + 1] = 2 * d2[i + 1];
}

void solve(){
	string s;
	cin>>s;

	int n = s.size();
	int p, q;

	p = 0;
	q = n - 1;

	while (s[p] == s[q] and p < q){
		p++;
		q--;
	}
	if (p == q){
		cout<<s<<endl;
		return;
	}

	string t = s.substr(p, q - p + 1);

	manacher(t);

	int sz, szz;
	sz = szz = 1;
	for (int i = 0; i < t.size(); i++){
		if (d1[i] == i + 1)
			sz = max(sz, 2 * d1[i] - 1);
		if (d2[i] == i)
			sz = max(sz, 2 * d2[i]);

		if (d1[i] + i == t.size())
			szz = max(szz, 2 * d1[i] - 1);
		if (d2[i] + i == t.size())
			szz = max(szz, 2 * d2[i]);
	}

	if (sz > szz)
		t = t.substr(0, sz);
	else{
		reverse(all(t));
		t = t.substr(0, szz);
	}

	string ans = s.substr(0, p);
	ans += t;
	ans += s.substr(q + 1, n - q);

	cout<<ans<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}