#include <bits/stdc++.h>
using namespace std;

struct Request {
	int pos = 0;
	bool done = false;
};

int main() {
	int n, head;
	if (!(cin >> n >> head) || n < 0) {
		return 0;
	}

	vector<Request> reqs(n);
	for (int i = 0; i < n; i++) {
		cin >> reqs[i].pos;
	}

	int cur = head;
	long long total_move = 0;
	vector<int> order; order.reserve(n);
	vector<int> move_dist; move_dist.reserve(n);

	for (int served = 0; served < n; served++) {
		int pick = -1;
		int bestDist = INT_MAX;
		for (int i = 0; i < n; i++) if (!reqs[i].done) {
			int d = abs(reqs[i].pos - cur);

			if (d < bestDist) {
				bestDist = d;
				pick = i;
			}
		}

		if (pick == -1) {
			break;
		}

		total_move += bestDist;
		move_dist.push_back(bestDist);
		cur = reqs[pick].pos;
		order.push_back(cur);
		reqs[pick].done = true;
	}

	cout << "Initial Head: " << head << "\n";
	cout << "Request Order (SSTF served):\n";
	for (size_t i = 0; i < order.size(); i++) {
		if (i) cout << " -> ";
		cout << order[i];
	}
	cout << '\n';

	cout << "\nIndex\tFrom\tTo\tMove\n";
	int from = head;
	for (size_t i = 0; i < order.size(); i++) {
		int to = order[i];
		cout << (i + 1) << '\t' << from << '\t' << to << '\t' << move_dist[i] << '\n';
		from = to;
	}

	cout << fixed << setprecision(2);
	cout << "\nTotal Head Movement: " << total_move << "\n";
	cout << "Average Seek per Move: " << (order.empty() ? 0.0 : (double)total_move / order.size()) << "\n";

	return 0;
}
