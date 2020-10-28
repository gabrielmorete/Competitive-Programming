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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

const int LMAXN = 28;


int p[MAXN], c[MAXN], c_new[MAXN], cnt[MAXN], cp[MAXN], lcp[MAXN];
int pr[MAXN], lcpr[MAXN], cr[MAXN];
pair<int, int> a[MAXN];

void count_sort(int n){
	fill(cnt, cnt + n, 0);
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

// O(nlogn)
void suffix_array(string &s){
	int n = s.size() + 1;
	for (int i = 0; i < n - 1; i++)
		a[i] = {s[i], i};
	a[n - 1] = {'$', n - 1};

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
	for (int i = 0; i < n - 1; i++){
		int pi = c[i]; // is the inverse permutation
		int j = p[pi - 1];
		while (s[i + k] == s[j + k]) k++;
		lcp[pi - 1] = k;
		k = max(k - 1, 0);
	}
}

int n;
int table1[MAXN][LMAXN], table2[MAXN][LMAXN], lg[MAXN];

void build_rmq(){
	for (int i = 0; i < n; i++){
		table1[i][0] = lcp[i];
		table2[i][0] = lcpr[i];
	}

	for (int j = 1; j < LMAXN; j++)
    	for (int i = 0; i + (1 << j) <= n; i++){
        	table1[i][j] = min(table1[i][j - 1], table1[i + (1 << (j - 1))][j - 1]);
    		table2[i][j] = min(table2[i][j - 1], table2[i + (1 << (j - 1))][j - 1]);
    	}

	lg[1] = 0;
	for (int i = 2; i < MAXN; i++)
	    lg[i] = lg[i/2] + 1;    
}

int query_rmq_fwr(int l, int r){
	int aux = lg[r - l + 1];
	return min(table1[l][aux], table1[r - (1 << aux) + 1][aux]);
}

int query_rmq_rev(int l, int r){
	int aux = lg[r - l + 1];
	return min(table2[l][aux], table2[r - (1 << aux) + 1][aux]);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	string s;
	cin>>s;
	
	reverse(all(s));
	suffix_array(s);

	fr(i, MAXN){
		lcpr[i] = lcp[i];
		cr[i] = c[i];
	}

	reverse(all(s));
	suffix_array(s);

	n = s.size();

	build_rmq();

	int ans = 1; 

	int pl, pr, aux;
	for (int sz = 1; sz <= n; sz++){
		for (int l = 0; l + sz <= n; l += sz){
			pl = c[l];
			pr = c[l + sz];
			aux = query_rmq_fwr(min(pl, pr), max(pl, pr) - 1);

			pl = cr[n - (l + sz)];
			pr = cr[n - l];

			aux += query_rmq_rev(min(pl, pr), max(pl, pr) - 1);

			ans = max(ans, 1 +  (aux / sz));
		}
	}	

	cout<<ans<<endl;	
}

// olha em janelas de tamanho sz
// tenta extender para direita fwr
// tenta extender para esquerda rev
// resposta otima está contida no intervalo de repetição
// ans = intervalo de repetição / tamaho do bloco