#include <iostream>
using namespace std;

int main() {

    int a[] = {50, 20, 40, 10, 30};
    int n = 5;
    int key = 40;

        for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {

            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

        int low = 0, high = n-1;
    bool found = false;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(a[mid] == key) {
            cout << "Element found at position " << mid+1;
            found = true;
            break;
        }
        else if(a[mid] < key) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    if(!found) {
        cout << "Element not found";
    }

    return 0;
}