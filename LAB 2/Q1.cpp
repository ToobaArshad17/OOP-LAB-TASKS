#include <iostream>
using namespace std;

int main (int argc , char *argv[]) {
    int sum=0 , *ptr;


    for (int i=1 ; i<argc ; i++) {
        int num = stoi(argv[i]);
        ptr = &num;
        sum += *ptr;
    }

    cout << "Sum is:" << sum ;

    return 0;
}