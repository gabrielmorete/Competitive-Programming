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
const int MAXN = 1e5 + 10;

struct Trie{
	int cnt, word;
	map<char, Trie> m;

	Trie(){
		cnt = word = 0;
		m.clear();
	}

	void add(const string &s, int pos = 0){
		cnt++;
		if (pos == s.size()){
			word++;
			return;
		}

		if (!m.count(s[pos]))
			m[s[pos]] = Trie();
		m[s[pos]].add(s, pos + 1);
	}

	bool search(string &s, int sz, int pos = 0){
		if (pos < sz){
			if (m.count(s[pos]))
				return m[s[pos]].search(s, sz, pos + 1);
			return false;
		}
		else{
			if (word and pos > sz)
				cout<<s<<endl;

			for (char a = 'a'; a <= 'z'; a++)
				if (m.count(a)){
					s.push_back(a);
					m[a].search(s, sz, pos + 1);
					s.pop_back();
				}

			return true;
		}
	}
};

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;

	Trie T = Trie();

	cin>>n;

	fr(i, n){
		cin>>s;
		T.add(s);
	}

	int q;
	cin>>q;

	frr(i, q){
		cout<<"Case #"<<i<<":"<<endl;
		cin>>s;
		if (!T.search(s, (int) s.size()))
			cout<<"No match."<<endl;
	}
}