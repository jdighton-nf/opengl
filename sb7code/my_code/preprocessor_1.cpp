#include <iostream>

#define A 0
#undef A
#define B 0

using namespace std; 

int main(){
    int C { 3 }; 
    #if A
        C=1; 
    #elif B
        C=2;
    #else
        C=3;
        cout << C << '\n'; 
    #endif

    return 0; 
}
