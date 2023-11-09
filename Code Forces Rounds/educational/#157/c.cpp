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
const int MAXN = 4e5 + 10;

int n;
vector< pair<int, string> > words;

ll ans, frq[11][111];

int get_pref_sum(string &s, int p){
	int ans = 0;
	fr(i, p)
		ans += s[i] - '0';
	return ans;		
}

int get_suf_sum(string &s, int p){
	int ans = 0;
	int sz = s.size();
	for (int i = sz - 1; i > max(sz - 1 - p, 0); i--)
		ans += s[i] - '0';
	return ans;		
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	words.resize(n);

	fr(i, n){
		cin >> words[i].second;
		words[i].first = words[i].second.size();
	}

	sort(all(words));

	// words are sorted by size
	for (auto [sz, s] : words){
		int ds = get_pref_sum(s, sz);

		int l = sz % 2; // even or odd;

		ans += 1; // string with itself

		for (int i = 2 - l; i <= sz; i += 2){ // size of the other string, same parity, smaller size
			int p = (sz - i) / 2; // <== for sure is even
			int sum_p = get_pref_sum(s, p);
			int sum_s = get_suf_sum(s, p);

			if (ds - 2 * sum_p >= 0)
				ans += frq[i][ds - 2 * sum_p];

			if (ds - 2 * sum_s >= 0)
				ans += frq[i][ds - 2 * sum_s];
		}

		frq[sz][ds]++;
	}

	cout << ans << endl;
}