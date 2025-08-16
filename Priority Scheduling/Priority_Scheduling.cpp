#include <bits/stdc++.h>
using namespace std;

struct Process {
    string pid;
    int at = 0;
    int bt = 0;
    int pr = 0;
    int ct = 0;
    int tat = 0;
    int wt = 0;
    bool done = false;
};

int main() {
    int n;
    if (!(cin >> n) || n < 0) {
        return 0;
    }

    vector<Process> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].pid >> ps[i].at >> ps[i].bt >> ps[i].pr;
    }

    sort(ps.begin(), ps.end(), [](const Process &a, const Process &b) {
        if (a.at != b.at) return a.at < b.at;
        if (a.pr != b.pr) return a.pr < b.pr;
        return a.pid < b.pid;
    });

    long long time_now = 0;
    if (!ps.empty()) time_now = ps.front().at;

    int completed = 0;
    double total_tat = 0.0, total_wt = 0.0;

    while (completed < n) {
        int pick = -1;

        for (int i = 0; i < n; i++) {
            if (!ps[i].done && ps[i].at <= time_now) {
                if (pick == -1) pick = i;
                else if (ps[i].pr < ps[pick].pr) pick = i;
                else if (ps[i].pr == ps[pick].pr && ps[i].at < ps[pick].at) pick = i;
            }
        }

        if (pick == -1) {
            int next_at = INT_MAX;
            for (auto &p : ps) if (!p.done) next_at = min(next_at, p.at);
            time_now = max<long long>(time_now, next_at);
            continue;
        }

        time_now += ps[pick].bt;
        ps[pick].ct = (int)time_now;
        ps[pick].tat = ps[pick].ct - ps[pick].at;
        ps[pick].wt = ps[pick].tat - ps[pick].bt;
        ps[pick].done = true;
        completed++;

        total_tat += ps[pick].tat;
        total_wt += ps[pick].wt;
    }

    cout << "PID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (const auto &p : ps) {
        cout << p.pid << '\t' << p.at << '\t' << p.bt << '\t' << p.pr
             << '\t' << p.ct << '\t' << p.tat << '\t' << p.wt << '\n';
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turn Around Time: " << (n ? total_tat / n : 0.0) << "\n";
    cout << "Average Waiting Time: " << (n ? total_wt / n : 0.0) << "\n";

    return 0;
}
