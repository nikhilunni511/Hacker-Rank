#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the maximumProgramValue function below.
 */
long maximumProgramValue(int n) {
    /*
     * Write your code here.
     */
    long x = 0;
    
    while(n-->0){
        string str;
        int a;
        cin>>str>>a;
        
        if(str=="add"){
            if(a>0)
                x+=a;
        }
        else if(str=="set"){
            if(a>x)
                x=a;
        }
    }
    return x;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = maximumProgramValue(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
