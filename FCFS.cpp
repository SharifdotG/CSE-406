#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number of PIDs: ";
    int num_pids;
    cin >> num_pids;

    vector<string> pids(num_pids);
    vector<int> arrival_time(num_pids), burst_time(num_pids), completion_time(num_pids), turn_around_time(num_pids), waiting_time(num_pids);

    cout << "Enter PID, Arrival Time and Burst Time:\n";
    for (int i = 0; i < num_pids; i++) {
        cin >> pids[i] >> arrival_time[i] >> burst_time[i];
    }

    int current_time = 0;
    for (int i = 0; i < num_pids; i++) {
        if (current_time < arrival_time[i]) {
            current_time = arrival_time[i];
        }

        current_time += burst_time[i];
        completion_time[i] = current_time;
        turn_around_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turn_around_time[i] - burst_time[i];
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < num_pids; i++) {
        cout << pids[i] << "\t" << arrival_time[i] << "\t" << burst_time[i] << "\t" << completion_time[i] << "\t" << turn_around_time[i] << "\t" << waiting_time[i] << endl;
    }

    return 0;
}
