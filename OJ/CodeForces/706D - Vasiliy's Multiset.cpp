#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1ll; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int maxbit = 31;

struct Trie{
	int cnt, word;
	map<bool, Trie> m;

	Trie(){
		cnt = word = 0;
		m.clear();
	}

	void add(const ll &x, int pos = maxbit){
		cnt++;
		if (pos < 0){
			word++;
			return;
		}

		bool bit = x & (1ll << pos);

		if (!m.count(bit))
			m[bit] = Trie();
		m[bit].add(x, pos - 1ll);
	}

	void remove(const ll &x, int pos = maxbit){
		cnt--;
		if (pos < 0){
			word--;
			return;
		}

		bool bit = x & (1ll << pos);

		m[bit].remove(x, pos - 1ll);
	}

	ll search(const ll &x, int pos = maxbit){
		if (pos < 0)
			return 0;

		bool bit = x & (1ll << pos);
		// dbg(bit);
		if (m.count(!bit) and m[!bit].cnt)
			return (((ll)(!bit)) << pos) + m[!bit].search(x, pos - 1ll);
		// chapa;
		return (((ll)bit) << pos) + m[bit].search(x, pos - 1ll);
	}
};

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	Trie T = Trie();

	cin>>n;

	T.add(0ll);

	ll x;
	string s;
	while (n--){
		cin>>s>>x;
		// dbg(s);
		// dbg(x);
		if (s == "+")
			T.add(x);
		if (s == "-")
			T.remove(x);
		if (s == "?")
			cout<<(x ^ T.search(x))<<endl;
	}
}