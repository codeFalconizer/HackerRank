#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
   public:
    vector<vector<int>> a;
    friend Matrix operator+(const Matrix& x, const Matrix& b);
};

Matrix operator+(const Matrix& x, const Matrix& y) {
    Matrix result;
    vector<int> vec;
    result.a.reserve(x.a.size());
    for (size_t i = 0; i < x.a.size(); i++) {
        vec.reserve(x.a.at(i).size());
        for (size_t j = 0; j < x.a.at(i).size(); j++) {
            vec.push_back(x.a.at(i).at(j) + y.a.at(i).at(j));
        }
        result.a.push_back(vec);
        vec.clear();
    }
    return result;
}

int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
