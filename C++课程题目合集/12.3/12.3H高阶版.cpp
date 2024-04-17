#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        string str;
        
        if(n == 0)
        {
            cout << setw(11) << n << "-->0" << endl;
            continue;
        }
        
        for(int i=n; i; i /=2)
            str += (i %2) ? '1' : '0';
        
        reverse(str.begin(), str.end());
        
        cout << setw(11) << n << ((n > 0)? "-->" : "-->-") << str << endl;
    }

    return EXIT_SUCCESS;
}
