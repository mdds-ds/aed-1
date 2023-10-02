#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j) {
    int i = 1;
    string res = s;
    while(i<=j){
        string temp;
        char last = res[res.size()-1];
        temp.push_back(last);
        int k = 0;
        while(k<res.size()-1){
            temp.push_back(res[k]);
            k++;
        }
        res = temp;
        i++;
    }
    return res;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;

    string res = rotar(s, j);
    cout << res;
    return 0;
}