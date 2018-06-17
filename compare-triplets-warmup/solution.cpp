#include <vector>
#include <iostream>

using namespace std;

// "finish this function"
vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2){

// my code:
 vector< int > result;
 int playerA = (a0>b0 ? 1 : 0)+ (a1 > b1 ? 1 : 0) + (a2 > b2 ? 1 : 0);
 int playerB = (a0<b0 ? 1 : 0)+ (a1 < b1 ? 1 : 0) + (a2 < b2 ? 1 : 0);
 result.push_back(playerA);
 result.push_back(playerB);

 return result;

// that's all you were supposed to do.
// note: I would've used a std::tuple, but a vector is fine. -A 
}

int main() {
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    vector < int > result = solve(a0, a1, a2, b0, b1, b2);
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
