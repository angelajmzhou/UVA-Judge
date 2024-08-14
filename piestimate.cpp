#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int gcd(int a, int b);

int main() {
    int n;
    
    while (cin >> n && n) {
        vector<int> m(n);
        int nofact = 0;

        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }

        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (gcd(m[j], m[k]) == 1) {
                    nofact++;
                }
            }
        }

        if (nofact == 0) {
            cout << "No estimate for this data set." << endl;
            continue;
        }

        int total = n * (n - 1) / 2;
        double prob = static_cast<double>(nofact) / total;
        double pi = sqrt(6.0 / prob);

        cout << fixed;
        cout.precision(6);
        cout << pi << endl;
    }

    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
