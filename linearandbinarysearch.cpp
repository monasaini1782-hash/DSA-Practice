#include <iostream>
using namespace std;

int main() {
    int n, key, pos = -1;

    cout << "Enter n: ";
    cin >> n;

    int a[n];
    cout << "Enter sorted elements: ";
    for(int i=0; i<n; i++) cin >> a[i];

    cout << "Enter key: ";
    cin >> key;

    // Linear Search
    for(int i=0; i<n; i++) {
        if(a[i] == key) {
            pos = i;
            break;
        }
    }
    cout << "Linear Search: " << pos << endl;
    cout << "Time Complexity: O(n)" << endl;

    // Binary Search
    int l=0, r=n-1, mid;
    pos=-1;

    while(l<=r) {
        mid=(l+r)/2;
        if(a[mid]==key) {
            pos=mid;
            break;
        }
        else if(a[mid]<key) l=mid+1;
        else r=mid-1;
    }

    cout << "Binary Search: " << pos << endl;
    cout << "Time Complexity: O(log n)" << endl;

    return 0;
}
  