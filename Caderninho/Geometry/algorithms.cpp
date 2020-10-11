// Algorithms for geometry
// Use with basic library

// Sort by augment angle related to o
struct comparator{
	point o;
	comparator(point _o): o(_o){}
	bool operator()(point a, point b){
		if (sign((a - o) ^ (b - o)) != 0)
			return sign((a - o) ^ (b - o)) > 0;
		return sign((a - o).norm2() - (b - o).norm2()) < 0;
	}
};

// build convex hull in nlog(n), n > 1
vector<point> convex_hull(vector<point> v, int border_in){ // should border be in convex?
	swap(v[0], *min_element(all(v))); // lex_sort
	sort(v.begin() + 1, v.end(), comparator(v[0]));
	int sz = 2, s, nv = v.size();
	if (border_in){
		for (s = nv - 1; s > 1 and sign((v[s] - v[0]) ^ (v[s - 1] - v[0])) == 0; s--);
		reverse(v.begin() + s, v.end());	
	}
	vector<point> hull = {v[0], v[1]};
	for (int i = 2; i < nv; i++)
		if (sz < 2)
			hull.push_back(v[i]), sz++;
		else if (sign((hull[sz - 1] - hull[sz - 2]) ^ (v[i] - hull[sz - 1])) >= 1 - border_in)
			hull.push_back(v[i]), sz++;
		else
			hull.pop_back(), i--, sz--;
	return hull;	
}

// find diameter of a polygon in O(n) n > 2
pair<point, point> diameter_polygon(vector<point> v){
	int l, r, p = 2, nv = v.size();
	coord mxdst = 0;
	pair<point, point> ans = {v[0], v[1]};

	for (int i = 0; i < nv; i++){
		l = i, r = (i + 1) % nv;
		point lr = v[r] - v[l]; 
		while (sign(abs((v[(p + 1) % nv] - v[l]) ^ lr) - abs((v[p] - v[l]) ^ lr)) >= 0) 
			p = (p + 1) % nv;
		if (sign((v[l] - v[p]).norm2() - mxdst) > 0)
			mxdst = (v[l] - v[p]).norm2(), ans = {v[l], v[p]};
		if (sign((v[r] - v[p]).norm2() - mxdst) > 0)
			mxdst = (v[r] - v[p]).norm2(), ans = {v[r], v[p]};
	}
	return ans;
}

// check if a is conteined in polygon in O(log(n)) n > 1
bool pol_contain(vector<point> &pol, point a){ // pol must be in clockwise order
	int r = pol.size() - 1, l = 1, meio;
	while (r - l > 1){
		meio = (r + l) / 2;
		if (segment(pol[0], pol[meio]).ccw(a) >= 0) r = meio;
		else l = meio;
	}
	if (r == l) return segment(pol[0], pol[r]).contains(a);
	else{
		coord a1 =	abs((pol[r] - pol[0]) ^ (pol[l] - pol[0]));
		coord a2 =	abs((pol[r] - a) ^ (pol[l] - a)) +
					abs((pol[l] - a) ^ (pol[0] - a)) +
					abs((pol[0] - a) ^ (pol[r] - a));
		return sign(a1 - a2) == 0;			
	}
}
