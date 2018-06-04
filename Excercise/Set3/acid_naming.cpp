#include <bits/stdc++.h>

using namespace std;

string acidNaming(string acid_name) {
    // Complete this function
    if(acid_name.substr(0,5)=="hydro"&&(acid_name[acid_name.length()-2])=='i'&&(acid_name[acid_name.length()-1])=='c')
        return "non-metal acid";
    else if((acid_name[acid_name.length()-2])=='i'&&(acid_name[acid_name.length()-1])=='c')
        return "polyatomic acid";
    else
        return "not an acid";
}

int main() {
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string acid_name;
        cin >> acid_name;
        string result = acidNaming(acid_name);
        cout << result << endl;
    }
    return 0;
}
