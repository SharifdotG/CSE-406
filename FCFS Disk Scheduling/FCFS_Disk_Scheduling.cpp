#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> request_sequence = {11, 34, 41, 50, 52, 69, 70, 114};
    int head = 50;

    int total_movement = 0, current = head;

	cout << "Request Order (FCFS served):" << endl;
    for (size_t i = 0; i < request_sequence.size(); i++) {
        cout << request_sequence[i] << " ";
        total_movement += abs(current - request_sequence[i]);
        current = request_sequence[i];
    }

    cout << endl << "Total Head Movement: " << total_movement << endl;

    return 0;
}
