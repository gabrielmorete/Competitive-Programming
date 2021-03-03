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
const int MAXN = 1e5 + 10;

map< pair<int, int>, char> arc;

int edg, ant;

void add(int a, int b, char c){
	arc[{a,b}] = c;
	if (arc.count({b, a})){ 
		ant++;
		if (arc[{b, a}] == c)
			edg++;
	}	
}

void rmv(int a, int b){
	if (arc.count({b, a})){
		ant--;
		if (arc[{a, b}] == arc[{b, a}])
			edg--;
	}
	arc.erase({a, b});
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;

	cin>>n>>m;

	char c;
	int a, b;
	string s;

	fr(i, m){
		cin>>s;

		if (s == "+"){
			cin>>a>>b>>c;
			add(a, b, c);
		}
		else if (s == "-"){
			cin>>a>>b;
			rmv(a, b);
		}
		else{
			cin>>a;

			if (edg)
				cout<<"YES"<<endl;
			else{
				if (a % 2 and ant)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
		}
	}
}