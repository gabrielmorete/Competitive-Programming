#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int main(){
	fastio;
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	stack<pair<int,int>> first;
	stack<pair<int,int>> second;
	queue<pair<int,int>> moves;
	int inv = 0;
	fr(i,n){
		if(a[i] == 'a' && b[i] == 'b'){
			first.push({i,i});
			inv++;
		}
		else if(a[i] == 'b' && b[i] == 'a'){
			second.push({i,i});
			inv++;
		}
	}

	if(inv%2 != 0){
		cout << -1 << "\n";
		exit(0);
	}
	while(inv > 0){
		while(first.size() >= 2){
			auto um = first.top();
			first.pop();
			auto dois = first.top();
			first.pop();
			moves.push({um.fst, dois.snd});
			inv -= 2;
		}
		while(second.size() >= 2){
			auto um = second.top();
			second.pop();
			auto dois = second.top();
			second.pop();
			moves.push({um.fst, dois.snd});
			inv -= 2;
		}
		if(first.size() >= 1 && second.size() >= 1){
			auto um = first.top();
			first.pop();
			moves.push({um.fst, um.snd});
			second.push({um.snd, um.fst});
		}
		
	}
	cout << moves.size() << "\n";
	while(moves.size() > 0){
		auto x = moves.front();
		moves.pop();
		cout << x.fst + 1 << " " << x.snd + 1 << "\n";
	}
}