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
const int MAXN = 5e6 + 10;
const ll mod = 1e9+7;

int32_t main(){
	fastio;
	int n, x, y;
	queue<int> a, b;

	int aux;

	cin>>n;
	cin>>x;
	fr(i, x){
		cin>>aux;
		a.push(aux);
	}

	cin>>y;
	fr(i, y){
		cin>>aux;
		b.push(aux);
	}

	int cnt = 0;

	fr(i, MAXN){
		cnt++;
		x = a.front();
		a.pop();

		y = b.front();
		b.pop();

		if (x > y){
			a.push(y);
			a.push(x);
		}
		else{
			b.push(x);
			b.push(y);
		}

		if (a.empty()){
			cout<<cnt<<' '<<2<<endl;
			return 0;
		}
		if (b.empty()){
			cout<<cnt<<' '<<1<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;

}