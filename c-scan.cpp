#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> request_sequence = {21, 39, 50, 64, 79, 90, 176};
    int head = 50;
    string direction = "left";

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

    cout << "Request Order (C-SCAN served):" << endl;

    if (direction == "right") {
        for (int request : right) {
            cout << request << " ";
            total_movement += abs(current - request);
            current = request;
        }

        if (!left.empty()) {
            int smallest_left = *min_element(left.begin(), left.end());
            total_movement += abs(current - smallest_left);
            current = smallest_left;
            cout << smallest_left << " ";
            
            left.erase(find(left.begin(), left.end(), smallest_left));
        }

        reverse(left.begin(), left.end());
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

        if (!right.empty()) {
            int largest_right = *max_element(right.begin(), right.end());
            total_movement += abs(current - largest_right);
            current = largest_right;
            cout << largest_right << " ";
            
            right.erase(find(right.begin(), right.end(), largest_right));
        }

        reverse(right.begin(), right.end());
        for (int request : right) {
            cout << request << " ";
            total_movement += abs(current - request);
            current = request;
        }
    }

    cout << endl << "Total Head Movement: " << total_movement << endl;

    return 0;
}