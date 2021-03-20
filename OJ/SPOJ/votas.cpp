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
const int LMAXN = 25;

int p[MAXN], c[MAXN], c_new[MAXN], cnt[MAXN], cp[MAXN], lcp[MAXN];
pair<int, int> a[MAXN];

void count_sort(int n){
	fill(cnt, cnt + n + 1, 0);
	for (int i = 0; i < n; i++)
		cnt[c[i] + 1]++;
	for (int i = 1; i < n; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++){
		int x = c[p[i]];
		cp[cnt[x]] = p[i];
		cnt[x]++;
	}
	for (int i = 0; i < n; i++)
		p[i] = cp[i];
}

// O suffix a. está em p, o i-ésimo menor suffixo começa em na posição p[i]
// o suffixo vazio está incluso (p[0] = n)
void suffix_array(string &s){
	int n = s.size() + 1;
	for (int i = 0; i < n - 1; i++)
		a[i] = {s[i], i};
	a[n - 1] = {' ', n - 1}; // caractere 32, menor legivel

	sort(a, a + n);

	p[0] = n - 1;
	c[p[0]] = 0;
	for (int i = 1; i < n; i++){
		p[i] = a[i].second;
		c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
	}

	int k = 0;
	while ((1 << k) < n){
		for (int i = 0; i < n; i++)
			p[i] = (p[i] - (1 << k) + n) % n;

		count_sort(n);

		c_new[p[0]] = 0;
		for (int i = 1; i < n; i++){
			int eq = c[p[i - 1]] != c[p[i]];
			eq |= c[(p[i - 1] + (1 << k)) % n] != c[(p[i] + (1 << k)) % n];
			c_new[p[i]] = c_new[p[i - 1]] + eq;
		}
		for (int i = 0; i < n; i++)
			c[i] = c_new[i];	
		k++;
	}

	k = 0;
	for (int i = 0; i < n - 1; i++){ // calcula lcp
		int pi = c[i]; // permutação inversa, na posição i começa - c[i]-ésimo suffixo
		int j = p[pi - 1];
		while (s[i + k] == s[j + k]) k++;
		lcp[pi - 1] = k; // lcp[i] é o maior prefixo entre os sufixos p[i] -> p[i + 1]
		k = max(k - 1, 0);
	}
}

int n;
int table[MAXN][LMAXN], lg[MAXN];

void build_rmq(){
	for (int i = 0; i < n; i++)
		table[i][0] = lcp[i];

	for (int j = 1; j < LMAXN; j++)
    	for (int i = 0; i + (1 << j) <= n; i++)
        	table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    	
	lg[1] = 0;
	for (int i = 2; i < MAXN; i++)
	    lg[i] = lg[i/2] + 1;    
}

int query_rmq(int l, int r){
	int aux = lg[r - l + 1];
	return min(table[l][aux], table[r - (1 << aux) + 1][aux]);
}

int ans[MAXN];

void solve(){
	string s;
	cin>>s;

	suffix_array(s);

	n = s.size();

	build_rmq();

	fr(i, n + 10) ans[i] = 0;

	int rs = 1;
	for (int i = 1; i <= n; i++)
		if (p[i] == 0)
			rs = i; // posiçao da string inteira no sa

	ans[n] = 1;	
	for (int i = 1; i <= n; i++){
		if (i != rs){
			int val = query_rmq(min(i, rs), max(i, rs) - 1);
			ans[val]++;
		}
	}	

	for (int i = n - 1; i >= 0; i--)
		ans[i] += ans[i + 1];

	int q, k;
	cin>>q;

	while (q--){
		cin>>k;
		if (k > n)
			cout<<0<<' ';
		else
			cout<<ans[k]<<' ';
	}
	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}