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

// #define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, sec, mili;

string soma(string t){
	int h, m, s, ms;
	// dbg(t);
	h = stoi(t.substr(0, 2));
	// dbg(h);
	m = stoi(t.substr(3, 2));
	// dbg(m);
	s = stoi(t.substr(6, 2));
	// dbg(s);
	ms = stoi(t.substr(9));
	// dbg(ms);

	ms += mili;
	s += ms > 999;
	ms %= 1000;

	// dbg(s);
	s += sec;
	m += s > 59;
	s%= 60;

	h += m > 59;
	m %= 60;

	string sh = to_string(h);
	while (sh.size() < 2)
		sh.insert(sh.begin(), '0');

	string sm = to_string(m);
	while (sm.size() < 2)
		sm.insert(sm.begin(), '0');

	string ss = to_string(s);
	while (ss.size() < 2)
		ss.insert(ss.begin(), '0');

	string sms = to_string(ms);
	while (sms.size() < 3)
		sms.insert(sms.begin(), '0');

	string ans = sh+":"+sm+":"+ss+","+sms;
	return ans;
}

string solve(string s){
	string t = s.substr(0, 12);

	string ans = soma(t);
	ans += " --> ";
	t = s.substr(17);
	ans += soma(t);

	return ans;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	string s;
	cin>>s;

	fr(i, s.size()){
		if (s[i] == '.'){
			sec = stoi(s.substr(0, i));
			mili = stoi(s.substr(i + 1));
		}
	}

	vector<string> ans;

	getline(cin, s);


	fr(i, n){
		getline(cin, s);
		ans.pb(s);
		getline(cin, s);
		ans.pb(solve(s));

		getline(cin, s);
		while (s.size() != 0){
			ans.pb(s);
			getline(cin, s);
		}
		ans.pb(s);
	}
	ans.pop_back();


	for (auto x : ans)
		cout<<x<<endl;
}