#include <iostream>
using namespace std;

int main() {
    float arr[20];
    float *ptr = arr;  

    cout << "Enter 20 float numbers: " << endl;
    for (int i = 0; i < 20; i++) {
        cin >> *(ptr + i);
    }

    float highest = *(ptr);
    float sec_highest = *(ptr);

    for (int i = 1; i < 20; i++) {
        if (*(ptr + i) > highest) {
            sec_highest = highest;
            highest = *(ptr + i);
   		 }	
    }

    cout << "The second highest number is: " << sec_highest << endl;

    return 0;
}
