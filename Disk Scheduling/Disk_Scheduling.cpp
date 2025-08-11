
#include <bits/stdc++.h>
using namespace std;

struct Req {
	int pos;
	bool done;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, head;
	cin >> n >> head;

	vector<Req> rq(n);
	for (int i = 0; i < n; i++) {
		cin >> rq[i].pos;
		rq[i].done = false;
	}

	int cur = head;
	long long total_move = 0;
	vector<int> order; order.reserve(n);
	vector<int> move_each; move_each.reserve(n);

	for (int i = 0; i < n; i++) {
		int pick = -1, bestDist = INT_MAX;
		for (int j = 0; j < n; j++) if (!rq[j].done) {
			int d = abs(rq[j].pos - cur);

			if (d < bestDist) {
				bestDist = d;
				pick = j;
			}
		}

		if (pick == -1) {
            break;
        }

		total_move += bestDist;
		move_each.push_back(bestDist);
		cur = rq[pick].pos;
		order.push_back(cur);
		rq[pick].done = true;
	}

	cout << "\nInitial Head: " << head << "\n";
	cout << "Request Order (served):\n";
	for (size_t i = 0; i < order.size(); i++) {
		if (i) {
            cout << " -> ";
        }

		cout << order[i];
	}
    
	cout << "\n\nIndex\tFrom\tTo\tMove\n";
	int from = head;
	for (size_t i = 0; i < order.size(); i++) {
		int to = order[i];
		int mv = move_each[i];
		cout << i+1 << '\t' << from << '\t' << to << '\t' << mv << '\n';
		from = to;
	}

	cout << fixed << setprecision(2) << "\n";
	cout << "Total Head Movement: " << total_move << "\n";
	cout << "Average Seek per Move: " << (order.empty() ? 0.0 : (double)total_move / order.size()) << "\n";

	return 0;
}
