/*
Problem

You are given a rectangular grid with N rows and M columns. Each cell of this grid is painted with one of two colors: green and white. Your task is to find the number of green cells in the largest Christmas tree in this grid.

To define a Christmas tree, first we define a good triangle as follows:

A good triangle with top point at row R, column C and height h (h > 0) is an isoceles triangle consisting entirely of green cells and pointing upward. Formally, this means that: The cell (R, C) is green, and for each i from 0 to h-1 inclusive, the cells in row R+i from column C-i to column C+i are all green.

For example:

..#..
.####
#####
is a good triangle with height 3. The # cells are green and the . cells are white. Note that there is a green cell that is not part of the good triangle, even though it touches the good triangle.

..#..
.###.
####.
is NOT a good triangle with height 3, because the 5th cell in the 3rd row is white. However, there are good triangles with height 2 present.

...#.
.###.
#####.
is NOT a good triangle with height 3. However, there are good triangles with height 2 present.

A K-Christmas tree is defined as follows:

It contains exactly K good triangles in vertical arrangement.
The top cell of the i+1-th triangle must share its top edge with the bottom edge of any one of the cells at the base of the i-th triangle. This means that, if the base of the i-th triangle is at row r, from column c1 to column c2, then the top of the i+1-th triangle must be on row r+1, in a column somewhere between c1 and c2, inclusive.
For example, if K = 2:

...#...
..###..
.#####.
#######
..#....
.###...
#####..
is a valid 2-Christmas tree. Note that the height of the 2 good triangles can be different.

..#..
.###.
.#...
is also a valid 2-Christmas tree. Note that a good triangle can be of height 1 and have only one green cell.

...#...
..###..
.#####.
.......
..#....
.###...
#####..
The two good triangles with height 3 does NOT form a valid 2-Christmas tree, because the 2nd triangle must starts from the 4-th row.

...#.
..###
.#...
###..
The two good triangles with height 2 does NOT form a valid 2-Christmas tree, because the top of the 2nd triangle must be in a column between 3 and 5, inclusive.

You need to find the K-Christmas tree with the largest number of green cells.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of three lines:

The first line contains 3 space-separated integers N, M and K, where N is the number of rows of the grid, M is the number of columns of the grid and K is the number of good triangle in the desired Christmas tree.
The next N lines each contain exactly M characters. Each character will be either . or #, representing a white or green cell, respectively.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of green cells in the largest K-Christmas tree. If there is no K-Christmas tree, output 0.

Limits

1 ≤ T ≤ 100.
1 ≤ M ≤ 100.
1 ≤ N ≤ 100.
Each cell in the grid is either . or #.

Small dataset

K = 1.

Large dataset

1 ≤ K ≤ 100.

Sample


Input

4
3 5 1
..#..
.###.
#####
3 5 1
.....
.....
.....
4 5 1
#####
#####
#####
#####
4 5 2
#####
#####
#####
#####

Output

Case #1: 9
Case #2: 0
Case #3: 9
Case #4: 10

In sample case #1, the largest 1-Christmas tree has 9 green cells:

..#..
.###.
#####

In sample case #2, there is no 1-Christmas tree.

In sample case #3, one largest 1-Christmas tree with 9 green cells is:

#####
#####
#####
#####

In sample case #4, one largest 2-Christmas tree with 10 green cells is:

#####
#####
#####
#####


*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    ll t;
    cin >> t;
    for(ll c=1;c<=t;c++){
        ll n,m,k;
        cin >> n >> m >> k;
        char a[n][m];
        set<ll> h;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        ll ht=0;
        h.insert(0);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                //cout << "i: " << i << " j: " << j << endl;
                ht=0;
                if(a[i][j]=='#'){
                    if(j==0 || j==m-1){
                        h.insert(1);
                        //cout << "--1--" << endl;
                    }
                    else{
                        //cout << "--2--" << endl;
                        ht++;
                        ll j1=j-1,j2=j+1;
                        ll flag=0;
                        for(ll p=i+1;p<n;p++){
                            for(ll q=j1;q<=j2;q++){
                                //cout << "p: " << p << " q: " << q << endl;
                                //cout << "a[p][q] " << a[p][q] << " ";
                                if(a[p][q]!='#'){
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==1)
                                break;
                            else{
                                ht++;
                                j1--;
                                j2++;
                                //cout << "j1: " << j1 << " j2: " << j2 << endl;
                                if(j1<0 || j2>m-1){
                                    break;
                                }
                            }
                        }
                        //cout << "<<<<<ht>>>>>: " << ht << endl;
                        h.insert(ht);
                    }
                }
            }
        }
        ll res = *h.rbegin();
        //cout << "res: " << res << endl;
        ll fin = (2 + (res-1)*2);
        fin = fin*res;
        fin = fin/2;
        cout << "Case #" << c << ": " << fin << endl;
    }
}
