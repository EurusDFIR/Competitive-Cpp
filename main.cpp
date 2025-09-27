#include <iostream>
#include <string>

using namespace std;
int main(int, char**){
    int cnt=0;
    for (int i=0;i<100;++i){

        if (i>50){
            cnt+=1;
            cout<<i;
        }
    }
    
    cout<<cnt;
}
