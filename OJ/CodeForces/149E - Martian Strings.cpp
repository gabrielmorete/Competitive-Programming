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
const int LMAXN = 25;

const int MAXN = 1e6 + 10; // tamanho máximo da string

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
int table1[MAXN][LMAXN],table2[MAXN][LMAXN], lg[MAXN];
int pr[MAXN];

void build_rmq(){
	for (int i = 0; i < n + 1; i++){
		table1[i][0] = p[i];
		table2[i][0] = pr[i];
	}

	for (int j = 1; j < LMAXN; j++)
    	for (int i = 0; i + (1 << j) <= n + 1; i++){
        	table1[i][j] = min(table1[i][j - 1], table1[i + (1 << (j - 1))][j - 1]);
    	    table2[i][j] = min(table2[i][j - 1], table2[i + (1 << (j - 1))][j - 1]);
    	}
    	
	lg[1] = 0;
	for (int i = 2; i < MAXN; i++)
	    lg[i] = lg[i/2] + 1;    
}

int query_p(int l, int r){
	int aux = lg[r - l + 1];
	return min(table1[l][aux], table1[r - (1 << aux) + 1][aux]);
}

int query_pr(int l, int r){
	int aux = lg[r - l + 1];
	return min(table2[l][aux], table2[r - (1 << aux) + 1][aux]);
}

string t, s, v;

int pref[MAXN], suf[MAXN];

bool solve(){
	cin>>v;
	int sz = v.size();
	
	fr(i, sz + 1){
		pref[i] = n + 1;
		suf[i] = -1;
	}

	int ini = 0;
	int end = n;		

	// Build pref
	for (int i = 0; i < sz - 1; i++){
		while (ini < n and (p[ini] + i >= n or s[p[ini] + i] != v[i]))
			ini++;
		
		while (end >= ini and (p[end] + i >= n or s[p[end] + i] != v[i]))
			end--;

		if (ini <= end)
			pref[i] = query_p(ini, end) + i; // first ocurrance
	}

	// build suf
	ini = 0;
	end = n;

	for (int i = sz - 1; i > 0; i--){
		int pos = sz - 1 - i;
		while (ini < n and (pr[ini] + pos >= n or t[pr[ini] + pos] != v[i]))
			ini++;

		while (end >= ini and (pr[end] + pos >= n or t[pr[end]  + pos] != v[i]))
			end--;
	
		if (ini <= end)
			suf[i] = n - query_pr(ini, end) - 1 - pos; // last ocurrence (t is reversed)
	}

	for (int i = 0; i < sz - 1; i++) // both parts shoud not be empty
		if (pref[i] < suf[i + 1])    // if prefix end before suffix start
			return true;

	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>s;
	t = s;
	reverse(all(t));

	suffix_array(t);
	fr(i, s.size() + 1)
		pr[i] = p[i];

	suffix_array(s);

	n = s.size();

	build_rmq();

	int qry;
	cin>>qry;

	int ans = 0;
	while (qry--)
		ans += solve();
		
	cout<<ans<<endl;
}
