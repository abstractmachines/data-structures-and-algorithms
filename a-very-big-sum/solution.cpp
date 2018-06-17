#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long aLongSum(int n, vector <long> ar) {
    long long aSum = 0;
    vector<long>::iterator it;
    for( it = ar.begin(); it != ar.end(); ++it)
    {
        aSum += *it;
    }

    return aSum;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // my code: Note: I'm not sure why we need the size of the vector.
    // Why not just emplace_back anything new to the vector? Anyway, that's
    // the problem statement: you need to have a specific size. Weird! -A
    int n;
    cin >> n;
    vector<long> ar(n);
    for( int i = 0; i < n; ++i)
    {
     cin >> ar[i];
    }
    long result = aLongSum(n, ar);
    cout<<result <<endl;

    return 0;
}
