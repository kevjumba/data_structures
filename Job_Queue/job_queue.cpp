#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using std::floor;
using std::system;
using std::max;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  vector<int> heap;

  int LeftChild(int i) {
      return 2 * i + 1;
    }

    int RightChild(int i) {
      return 2 * i + 2;
    }

    int parent(int i) {
      return floor((i - 1) / 2);
    }

    void SiftDown(int i) {
      int maxIndex = i;
      int l = LeftChild(i);
      if (l < heap.size() && heap.at(l) < heap.at(maxIndex)) {
        maxIndex = l;
      }
      int r = RightChild(i);
      if (r < heap.size() && heap.at(r) < heap.at(maxIndex)) {
        maxIndex = r;
      }
      if (i != maxIndex) {
        swap(heap[i], heap[maxIndex]);
        SiftDown(maxIndex);
      }
    }

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
