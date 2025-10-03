#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int frame_size, num_pages;
    cin >> frame_size >> num_pages;

    vector<int> pages(num_pages);
    for (int i = 0; i < num_pages; i++) {
        cin >> pages[i];
    }

    vector<int> frames(frame_size, -1);
    queue<int> fifoQueue;
    int pageFaults = 0;
    int pageHits = 0;

    cout << "\nPage Reference | Frames Status | Hit/Miss\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < num_pages; i++) {
        int currentPage = pages[i];
        bool found = false;

        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == currentPage) {
                found = true;
                pageHits++;
                break;
            }
        }

        cout << "      " << currentPage << "        | ";

        if (!found) {
            pageFaults++;

            if (fifoQueue.size() < frame_size) {
                for (int j = 0; j < frame_size; j++) {
                    if (frames[j] == -1) {
                        frames[j] = currentPage;
                        fifoQueue.push(currentPage);
                        break;
                    }
                }
            } else {
                int pageToReplace = fifoQueue.front();
                fifoQueue.pop();

                for (int j = 0; j < frame_size; j++) {
                    if (frames[j] == pageToReplace) {
                        frames[j] = currentPage;
                        fifoQueue.push(currentPage);
                        break;
                    }
                }
            }

            for (int j = 0; j < frame_size; j++) {
                if (frames[j] == -1) {
                    cout << "[ ] ";
                } else {
                    cout << "[" << frames[j] << "] ";
                }
            }
            cout << "| MISS";
        } else {
            for (int j = 0; j < frame_size; j++) {
                if (frames[j] == -1) {
                    cout << "[ ] ";
                } else {
                    cout << "[" << frames[j] << "] ";
                }
            }
            cout << "| HIT";
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