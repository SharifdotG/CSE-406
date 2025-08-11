
#include <bits/stdc++.h>
using namespace std;

struct P {
    string pid;
    int at, bt, pr;
    int ct, tat, wt;
    bool done;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<P> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].pid >> ps[i].at >> ps[i].bt >> ps[i].pr;
        ps[i].ct = ps[i].tat = ps[i].wt = 0;
        ps[i].done = false;
    }

    sort(ps.begin(), ps.end(), [](const P &a, const P &b) {
        if (a.at != b.at) {
            return a.at < b.at;
        }

        if (a.pr != b.pr) {
            return a.pr < b.pr;
        }

        return a.pid < b.pid;
    });

    int finished = 0;
    long long cur = 0;
    if (!ps.empty()) {
        cur = ps[0].at;
    }

    double tot_tat = 0.0, tot_wt = 0.0;

    while (finished < n) {
        int pick = -1;
        for (int i = 0; i < n; i++) {
            if (!ps[i].done && ps[i].at <= cur) {
                if (pick == -1) {
                    pick = i;
                } else if (ps[i].pr < ps[pick].pr) {
                    pick = i;
                } else if (ps[i].pr == ps[pick].pr && ps[i].at < ps[pick].at) {
                    pick = i;
                }
            }
        }

        if (pick == -1) {
            int nextIdx = -1;
            for (int i = 0; i < n; i++) {
                if (!ps[i].done) {
                    nextIdx = i;
                    break;
                }

                if (nextIdx == -1) {
                    break;
                }

                cur = max<long long>(cur, ps[nextIdx].at);
                continue;
            }

            cur += ps[pick].bt;
            ps[pick].ct = (int)cur;
            ps[pick].tat = ps[pick].ct - ps[pick].at;
            ps[pick].wt = ps[pick].tat - ps[pick].bt;
            ps[pick].done = true;
            finished++;

            tot_tat += ps[pick].tat;
            tot_wt += ps[pick].wt;
        }

        cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
        for (const auto &p : ps) {
            cout << p.pid << '\t' << p.at << '\t' << p.bt << '\t' << p.pr
                 << '\t' << p.ct << '\t' << p.tat << '\t' << p.wt << '\n';
        }

        cout << fixed << setprecision(2) << "\n";
        cout << "Average Turn Around Time: " << (n ? tot_tat / n : 0.0) << "\n";
        cout << "Average Waiting Time: " << (n ? tot_wt / n : 0.0) << "\n";

        return 0;
    }
