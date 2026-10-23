/**
 * Author: Yeo Swe Hon
 * Date: 2026-10-24
 * License: CC0
 * Source: Folklore
 * Description: 2D prefix sum, sum(x1,y1,x2,y2) returns inclusive rectangle. SubMatrix<ll> sm(grid), (x1,y1) -> (x2,y2) (0-based indexing)
 * Usage:
 * SubMatrix<int> m(matrix);
 * m.sum(0, 0, 1, 1); // top left 4 elements
 * Time: O(N^2 + Q)
 * Status: Tested on Kattis
 */
#pragma once

template<class T>
struct SubMatrix{
	vector<vector<T>> p;
	SubMatrix(){}
	SubMatrix(const vector<vector<T>> &v){
		int R=(int)v.size(), C=(int)v[0].size();
		p.assign(R+1, vector<T>(C+1));
		for(int i = 0; i < R; i++) for(int j = 0; j < C; j++)
			p[i+1][j+1] = v[i][j] + p[i][j+1] + p[i+1][j] - p[i][j];
	}
	T sum(int x1,int y1,int x2,int y2) const{
		x2++, y2++;
		return p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
	}
};