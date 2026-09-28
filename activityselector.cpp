#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity a[n];

    cout << "Enter start and finish time:\n";

    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> a[i].start >> a[i].finish;
    }

    auto startTime = high_resolution_clock::now();

    // Sort according to finish time
    sort(a, a + n, compare);

    cout << "\nSelected Activities:\n";

    int lastFinish = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].start >= lastFinish) {
            cout << "(" << a[i].start << ", "
                 << a[i].finish << ")\n";

            lastFinish = a[i].finish;
            count++;
        }
    }

    auto endTime = high_resolution_clock::now();

    auto executionTime =
        duration_cast<nanoseconds>(endTime - startTime);

    cout << "\nMaximum Activities Selected: " << count;
    cout << "\nExecution Time: "
         << executionTime.count() << " nanoseconds\n";

    return 0;
}