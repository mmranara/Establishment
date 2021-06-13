#include <iostream>
using namespace std;

void multiplicationTable(int x){
    for(int i = 1; i<=x; i++){
        for(int j = 1; j<=x; j++){
            cout << i*j << "\t";
        }
        cout << "\n";
    }
}

int main(){

    cout << "hello World\n";
    multiplicationTable(10);
    
}