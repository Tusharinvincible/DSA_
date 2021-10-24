// Given two numbers x and y, and a range [l, r] where 1 <= l, 
// r <= 32. Find the set bits of y in range [l, r] and set these bits in x also.

#include <bits/stdc++.h>

using namespace std;

int setSetBit(int x, int y, int l, int r) {

    int i = 1 << (l - 1);
    int idx = l - 1;
    while (idx < r) {
        x = x | (y & i);

        i = i << 1;
        idx++;
    }

    return x;
}

int main() {
    int X = 44, Y = 3;
    int L = 1, R = 5;
    cout << setSetBit(X, Y, L, R) << endl;
    return 0;
}