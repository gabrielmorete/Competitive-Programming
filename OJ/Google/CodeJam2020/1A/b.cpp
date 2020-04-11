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

void solve2(int n){
	n -= 50;
	int cnt = 50;
	bool line[1000];
	ms(line, 0);

	int aux = 0;
	while (n > 0){
		if (n%2)
			line[aux] = 1;
		n = n/2;
		aux++;	
	}

	bool side = 0;

	frr(i,1000){
		if (line[i - 1]){
			if (side)
				frr(j, i)
					cout<<i<<' '<<i - j + 1<<endl;
			else
				frr(j, i)
					cout<<i<<' '<<j<<endl;
			side = 1 - side;
		}
		else{
			cnt--;
			if (side)
				cout<<i<<' '<<i<<endl;
			else
				cout<<i<<' '<<1<<endl;
			if (cnt == 0)
				break;
		}
	}
}

void solve1(int n){
	frr(i,n)
		cout<<i<<' '<<1<<endl;
}

int main(){
	fastio;
	int t, n;
	cin>>t;
	frr(i, t){
		cout<<"Case #"<<i<<":"<<endl;
		cin>>n;
		if (n <= 50)
			solve1(n);
		else
			solve2(n);
	}
}