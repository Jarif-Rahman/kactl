#include "Point.h>
const ld EPS = 1e-12;

struct Line{ // left half-plane intersection (keep points on left of directed lines)
    P c, lambda;
    ld angle;
    Line(){}
    Line(P a, P b): c(a), lambda(b-a){
        angle = atan2l(lambda.y, lambda.x);
    }
};

bool in(Line l, P p){
    return l.lambda.cross(p-l.c) >= -EPS;
}

P inter(Line a, Line b){
    P u = a.c-b.c;
    ld t = b.lambda.cross(u) / a.lambda.cross(b.lambda);
    return a.c + a.lambda*t;
}

vector<P> HPI(vector<Line> a){
    sort(a.begin(), a.end(), [](Line x, Line y) {
        return x.angle < y.angle;
    });
    int n = a.size(), l = 0, r = 0;
    vector<Line> q(n);
    vector<P> p(n);
    q[0] = a[0];
    for (int i = 1; i < n; i++) {
        while (l < r && !in(a[i], p[r-1])) r--;
        while (l < r && !in(a[i], p[l])) l++;
        q[++r] = a[i];
        if (fabsl(q[r].lambda.cross(q[r-1].lambda)) <= EPS) {
            r--;
            if (in(q[r], a[i].c)) q[r] = a[i];
        }
        if (l < r) p[r-1] = inter(q[r-1], q[r]);
    }
    while (l < r && !in(q[l], p[r-1])) r--;
    while (l < r && !in(q[r], p[l])) l++;
    if (r-l <= 1) return {};
    p[r] = inter(q[r], q[l]);
    return vector<P>(p.begin()+l, p.begin()+r+1);
}
