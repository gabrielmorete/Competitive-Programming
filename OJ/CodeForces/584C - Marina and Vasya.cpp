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

char nxt( char a, char b){
char c = 'a';
while (c == a or c == b)
    c++;
return c;    
}

int main(){
fastio;
int n, t;
cin>>n>>t;
string a, b;
cin>>a>>b;

int df = 0;
fr(i,n)
    if (a[i] != b[i])
        df++;

int eq = n - df;
int k = n - t;

if (k > df/2 + eq){
    cout<<"-1\n";
    return 0;
}
int mkdif = 0;
int mkeq = eq;

if (k > eq)
    mkdif = k - eq;
else
    mkeq = k;
int aa = 0;
int bb = 0;

fr(i, n){
    if (a[i] == b[i]){
        if (mkeq){
            mkeq--;
            cout<<a[i];
        }
        else
            cout<<nxt( a[i], b[i]);
    }
    else{
        if (aa < mkdif){
            aa++;
            cout<<a[i];;
        }
        else if (bb < mkdif){
            bb++;
            cout<<b[i];
        }
        else{
            cout<<nxt( a[i], b[i]);
        }
    }
}
gnl;    
}