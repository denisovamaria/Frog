#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int *num = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    if (n == 1) {
        cout << num[0] << '\n' << n;
        return 0;
    }
    if (n == 2) {
        cout << -1 << '\n';
        return 0;
    }
    int *way = new int[n];
    way[0] = num[0];
    way[1] = -1;
    way[2] = num[0] + num[2];
    for (int i = 3; i < n; i++) {
        if (way[i - 2] > way[i - 3])
            way[i] = num[i] + way[i - 2];
        else
            way[i] = num[i] + way[i - 3];
    }
    cout << way[n - 1] << '\n';

    vector<int> way1;
    way1.push_back(n);
    int i = n - 1;
    while (i > 3) {
        if (way[i] - num[i] == way[i - 2]) {
            way1.push_back(i - 1);
            i = i - 2;
        } else {
            way1.push_back(i - 2);
            i = i - 3;
        }
    }
    cout << 1;
    for (int i = way1.size() - 1; i > -1; i--) {
        cout << " " << way1[i];
    }
}