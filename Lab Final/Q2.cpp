#include <bits/stdc++.h>

using namespace std;

int main() {
	int f_s, n;
	cin >> f_s >> n;

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	vector<int> f(f_s, -1), l_u(f_s, -1);
	int p_f = 0, p_h = 0;

	cout << "\nPage Reference | Frames Status | Hit/Miss\n";
	cout << "--------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		int cur = p[i];
		bool found = false;
		int found_idx = -1;

		for (int j = 0; j < f_s; j++) {
			if (f[j] == cur) {
				found = true;
				found_idx = j;
				break;
			}
		}

		cout << "      " << cur << "        | ";

		if (found) {
			p_h++;
			l_u[found_idx] = i;
		} else {
			p_f++;

			int r_idx = -1;
			for (int j = 0; j < f_s; j++) {
				if (f[j] == -1) {
					r_idx = j;
					break;
				}
			}

			if (r_idx == -1) {
				int lru_v = numeric_limits<int>::max();
				for (int j = 0; j < f_s; j++) {
					if (l_u[j] < lru_v) {
						lru_v = l_u[j];
						r_idx = j;
					}
				}
			}

			f[r_idx] = cur;
			l_u[r_idx] = i;
		}

		for (int j = 0; j < f_s; j++) {
			if (f[j] == -1) {
				cout << "[ ] ";
			} else {
				cout << "[" << f[j] << "] ";
			}
		}

		if (found) {
			cout << "| HIT";
		} else {
			cout << "| MISS";
		}
		cout << endl;
	}

	cout << "\n====== RESULTS ======\n";
	cout << "Total Page Requests: " << n << endl;
	cout << "Total Page Hits: " << p_h << endl;
	cout << "Total Page Faults: " << p_f << endl;
	cout << "Hit Ratio: " << (double)p_h / n * 100 << "%" << endl;
	cout << "Fault Ratio: " << (double)p_f / n * 100 << "%" << endl;

	return 0;
}
