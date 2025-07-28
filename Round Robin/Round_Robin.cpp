#include <bits/stdc++.h>
using namespace std;

struct P {
    string pid;
    int at, bt, rem, ct, tat, wt;
};

int main() {
    int n, qt;
    cin >> n >> qt;

    vector<P> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].pid >> ps[i].at >> ps[i].bt;
        ps[i].rem = ps[i].bt;
    }

    sort(ps.begin(), ps.end(), [](const P &a, const P &b) {
        return a.at < b.at;
    });

    queue<int> q;
    vector<bool> vis(n, false);
    int cur = 0, ct_cnt = 0;
    float tot_tot = 0, tot_wt = 0;

    q.push(0);
    vis[0] = true;
    cur = ps[0].at;

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        int et = min(qt, ps[idx].rem);
        cur += et;
        ps[idx].rem -= et;

        for (int i = 0; i < n; i++) {
            if (!vis[i] && ps[i].at <= cur) {
                q.push(i);
                vis[i] = true;
            }
        }

        if (ps[idx].rem > 0) {
            q.push(idx);
        } else {
            ps[idx].ct = cur;
            ps[idx].tat = ps[idx].ct - ps[idx].at;
            ps[idx].wt = ps[idx].tat - ps[idx].bt;

            tot_tot += ps[idx].tat;
            tot_wt += ps[idx].wt;

            ct_cnt++;
        }

        if (q.empty() && ct_cnt < n) {
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                    cur = max(cur, ps[i].at);
                    break;
                }
            }
        }
    }

    cout << endl << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (auto p : ps) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << endl;
    }

    cout << fixed << setprecision(2) << endl;
    cout << "Average Turn Around Time: " << tot_tot / n << endl;
    cout << "Average Waiting Time: " << tot_wt / n << endl;

    return 0;
}
