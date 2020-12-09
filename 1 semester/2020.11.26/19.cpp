#include <iostream>
using namespace std;

int main() {
    string A, B;
    int S, j, m;
    j = 0;
    S = 0;
    cin >> A >> B;
    for (int i = 0; i < A.size(); i++) {
        if (j < B.size()) {
            if (A[i] != A[j]) {
                S++;
            }
            else {
                j++;
                m = i;
            }
        }
    }
    S += max(A.size() - m, B.size() - j);
    cout << S;
    system("PAUSE");
    return 0;
}
