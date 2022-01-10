#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

const double PI = acos(-1);

double sigma;

double f(double x){
	double y = (x*x)/(2*sigma*sigma);
	double z = x * exp(-y);

	return z/(2*PI*sigma*sigma);
}

double simp(double a, double b, int n = 1e6) {
	double h = (b - a) / n, s = f(a) + f(b);
	for (int i = 1; i < n; i += 2) s += 4*f(a+h*i);
	for (int i = 2; i < n; i += 2) s += 2*f(a+h*i);
	return s*h/3;
}

int main(){

	cout << setprecision(12) << fixed;

	double ibull, obull, itriple, otriple, idouble, odouble;

	cin >> ibull >> obull >> itriple >> otriple >> idouble >> odouble;
	cin >> sigma;

	double expected = 0.0;

	expected += 50*simp(0, ibull); // inner bull's eye
	expected += 25*simp(ibull, obull); // bull's area
	expected += (10.5)*(simp(obull, itriple) + simp(otriple, idouble)); // normal area
	expected += 3*(10.5)*simp(itriple, otriple); // triple area
	expected += 2*(10.5)*simp(idouble, odouble); // double area

	cout << 2*PI*expected << endl;
}
