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

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin>>s;

	int n = s.size();
	int p = n - 1;
	while (p >= 0 and s[p] == 'a')
		p--;

	int cnt = n - 1 - p;

	p = 0;
	while (p < n and s[p] == 'a')
		p++;

	cnt -= p;

	if (cnt < 0){
		cout<<"No"<<endl;
		return 0;
	}


	reverse(all(s));
	while (cnt--)
		s.pb('a');

	p = 0;
	int q = s.size() - 1;

	while (p <= q){
		if (s[p] != s[q]){
			cout<<"No"<<endl;
			return 0;
		}
		p++;
		q--;
	}

	cout<<"Yes"<<endl;
}