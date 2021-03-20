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

const int MAXN = 1e6 + 10; // tamanho máximo da string

int seg[4 * MAXN], lazy[4 * MAXN];

void propagete(int node, int l, int r){
	if (l != r){
		lazy[node<<1] |= lazy[node];
		lazy[node<<1|1] |= lazy[node];
	}

	if (lazy[node])
		seg[node] = (r - l + 1);
	
	lazy[node] = 0;
}

void modify(int node, int l, int r, int ql, int qr){
	propagete(node, l, r);
	if (r < ql or qr < l)
		return;
	if (ql <= l and r <= qr){
		lazy[node] = 1;
		propagete(node, l, r);
		return;
	}

	int meio = (l + r)/2;

	modify(node<<1, l, meio, ql, qr);
	modify(node<<1|1, meio + 1, r, ql, qr);
	
	// cout<<"seg "<<node<<' '<<l<<' '<<r<<' '<<seg[node]<<endl;	

	seg[node] = seg[node<<1] + seg[node<<1|1];
}

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

int n, k;

void update(int l, int r){
	// cout<<l<<' '<<r<<endl;
	if (r >= n){
		// chapa;
		modify(1, 0, n - 1, l, n - 1);
		modify(1, 0, n - 1, 0, r - n);
	}
	else
		modify(1, 0, n - 1, l, r);
	// dbg(seg[1]);
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;
	string s;
	cin>>s;

	s += s;
	suffix_array(s);

	for (int i = 0; i <= 2 * n; i++){
		if (p[i] < n){
			// cout<<s.substr(p[i], k)<<endl;

			update(p[i], p[i] + k - 1);
		}
		if (seg[1] >= n){
			cout<<s.substr(p[i], k)<<endl;
			return 0;
		}
	}
	// dbg(seg[1]);


}