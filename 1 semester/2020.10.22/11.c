#include <iostream>
#include <vector>
using namespace std;

int search(vector <int> A, int k) {
    vector <int> Left;
    vector <int> Right;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] < A[0]) {
            Left.push_back(A[i]);
        }
        else {
            Right.push_back(A[i]);
        }
    }
    if (Left.size() + 1 == k) return(A[0]);
    if (Left.size() + 1 < k) return search(Right, k - Left.size() - 1);
    if (Left.size() + 1 > k) return search(Left, k);
}

int main()
{
    vector <int> Array;
    int k, n, x;
    cout << "enter array length";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Array.push_back(x);
    }
    cout << "enter k";
    cin >> k;
    cout << search(Array, k);
    system("PAUSE");
    return 0;
}
