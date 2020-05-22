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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

vii mv;
vi sz;

int32_t main(){
	fastio;
	int n, k;
	string s;
	
	cin>>n>>k;
	cin>>s;

	int turn;
	turn = 0;

	int ok = 1;
	while (ok){
		ok = 0;
		int aux = 0;	
		for (int i = 0; i < n - 1; i++)
			if (s[i] == 'R' and s[i + 1] == 'L'){
				mv.pb({turn, i});
				swap(s[i], s[i + 1]);
				i++;
				ok = 1;
				aux++;
			}
	
		if (ok){
			turn++;
			sz.pb(aux);
		}
	}

	if (k < turn or k > mv.size()){
		cout<<-1<<endl;
	}
	else{
		int delta = mv.size() - k;
		int t = 0, p = 0;
		while (k > 0){
			if (sz[t] <= delta and delta > 0){
				delta -= sz[t] - 1;
				k--;
				cout<<sz[t];
				while (mv[p].fst == t)
					cout<<' '<<mv[p++].snd + 1;
				gnl;
				t++;
			}
			else{
				if (delta == 0){
					cout<<1<<' '<<1 + mv[p++].snd<<endl;
					k--;
				}
				else{
					cout<<delta + 1;
					for (int i = p; i < p + delta + 1; i++)
						cout<<' '<<1 + mv[i].snd;
					gnl;
					p += delta + 1;
					delta = 0;
					k--;
				}
			}
		}
	}
}