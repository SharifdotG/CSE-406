#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> request_sequence = {11, 34, 41, 50, 52, 69, 70, 114};
    int head = 50;

    vector<bool> visited(request_sequence.size(), false);
    int total_movement = 0, current = head;

    for (int i = 0; i < request_sequence.size(); i++) {
        int min_distance = INT_MAX;
        int idx = -1;

        for (int j = 0; j < request_sequence.size(); j++) {
            if (!visited[j]) {
                int distance = abs(current - request_sequence[j]);

                if (distance < min_distance) {
                    min_distance = distance;
                    idx = j;
                }
            }
        }

        visited[idx] = true;
        cout << request_sequence[idx] << " ";
        total_movement += abs(current - request_sequence[idx]);
        current = request_sequence[idx];
    }

    cout << endl << "Total Head Movement: " << total_movement << endl;

    return 0;
}