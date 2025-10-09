#include <bits/stdc++.h>

using namespace std;

int main() {
	int frame_size, num_pages;
	cin >> frame_size >> num_pages;

	vector<int> pages(num_pages);
	for (int i = 0; i < num_pages; i++) {
		cin >> pages[i];
	}

	vector<int> frames(frame_size, -1);
	vector<int> lastUsed(frame_size, -1);
	int pageFaults = 0;
	int pageHits = 0;

	cout << "\nPage Reference | Frames Status | Hit/Miss\n";
	cout << "--------------------------------------------\n";

	for (int i = 0; i < num_pages; i++) {
		int currentPage = pages[i];
		bool found = false;
		int foundIndex = -1;

		for (int j = 0; j < frame_size; j++) {
			if (frames[j] == currentPage) {
				found = true;
				foundIndex = j;
				break;
			}
		}

		cout << "      " << currentPage << "        | ";

		if (found) {
			pageHits++;
			lastUsed[foundIndex] = i;
		} else {
			pageFaults++;

			int replaceIndex = -1;
			for (int j = 0; j < frame_size; j++) {
				if (frames[j] == -1) {
					replaceIndex = j;
					break;
				}
			}

			if (replaceIndex == -1) {
				int mruValue = numeric_limits<int>::min();
				for (int j = 0; j < frame_size; j++) {
					if (lastUsed[j] > mruValue) {
						mruValue = lastUsed[j];
						replaceIndex = j;
					}
				}
			}

			frames[replaceIndex] = currentPage;
			lastUsed[replaceIndex] = i;
		}

		for (int j = 0; j < frame_size; j++) {
			if (frames[j] == -1) {
				cout << "[ ] ";
			} else {
				cout << "[" << frames[j] << "] ";
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
	cout << "Total Page Requests: " << num_pages << endl;
	cout << "Total Page Hits: " << pageHits << endl;
	cout << "Total Page Faults: " << pageFaults << endl;
	cout << "Hit Ratio: " << (double)pageHits / num_pages * 100 << "%" << endl;
	cout << "Fault Ratio: " << (double)pageFaults / num_pages * 100 << "%" << endl;

	return 0;
}
