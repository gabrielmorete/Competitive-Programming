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

int p[MAXN], c[MAXN], c_new[MAXN], cnt[MAXN], cp[MAXN];
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
	for (int i = 1; i < n; i++)
		p[i - 1] = p[i];
}

int n, nn;
string s, t;

int test(int pos){
	pos = p[pos];
	for (int i = 0; i < min(nn, n - pos); i++)
		if (t[i] != s[pos + i])
			return t[i] < s[pos + i] ? 1:-1;
	
	if ((n - pos) < nn) return -1;
	return 0;
}

bool solve(){
	int ini, fim, meio;
	ini = 0;
	fim = n - 1;
	nn = t.size();
	while (ini <= fim){
		meio = (ini + fim) / 2;
		int res = test(meio);
		if (res == 0) return true;
		if (res < 0) ini = meio + 1; // menor
		else fim = meio - 1;
	}
	return false; 
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>s;
	suffix_array(s);
	n = s.size();
	int q;
	cin>>q;
	while (q--){
		cin>>t;
		if (solve())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}