#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> request_sequence = {137, 240, 179, 75, 118, 29, 15, 51};
    int head = 55;
    int disk_size = 240;
    string direction = "right";

    vector<int> left, right;
    int total_movement = 0, current = head;

    for (int request : request_sequence) {
        if (request < head) {
            left.push_back(request);
        } else if (request > head) {
            right.push_back(request);
        }
    }

    sort(left.begin(), left.end(), greater<int>());
    sort(right.begin(), right.end());

    cout << "Request Order (SCAN served):" << endl;

    if (direction == "right") {
        for (int request : right) {
            cout << request << " ";
            total_movement += abs(current - request);
            current = request;
        }

        if (!right.empty()) {
            total_movement += abs(current - (disk_size - 1));
            current = disk_size - 1;
        }

        for (int request : left) {
            cout << request << " ";
            total_movement += abs(current - request);
            current = request;
        }
    } else {
        for (int request : left) {
            cout << request << " ";
            total_movement += abs(current - request);
            current = request;
        }

        if (!left.empty()) {
            total_movement += abs(current - 0);
            current = 0;
        }

        for (int request : right) {
            cout << request << " ";
            total_movement += abs(current - request);
            current = request;
        }
    }

    cout << endl << "Total Head Movement: " << total_movement << endl;

    return 0;
}