#include <stdlib.h>
#include <iostream>
#include "tzfe.h"

using namespace std;

int main(int argc, char *argv[])
{
    Tzfe tzfe;
    system("cls");
    int t = 0;
    while(1){
        tzfe.print();
        cout << endl;
        int k = tzfe.control();
        if(k == -1){
            t = 0;
            break;
        }
        if(k == 1){
            t = 1;
            break; 
        }
    }
    cout << (t == 1 ? "yes": "no") << endl;
    return 0;
}
