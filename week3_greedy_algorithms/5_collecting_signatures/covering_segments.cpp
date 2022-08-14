#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

/*
You are responsible for collecting signatures from all tenants of a certain building. For each 
tenant, you know a period of time when he or she is at home.
You would like to collect all signatures by visiting the building as few times as
possible.

The mathematical model for this problem is the following. You are given a set
of segments on a line and your goal is to mark as few points on a line as possible
so that each segment contains at least one marked point.

Given a set of 𝑛 segments {[𝑎0, 𝑏0], [𝑎1, 𝑏1], . . . , [𝑎𝑛−1, 𝑏𝑛−1]} with integer coordinates on a line, find
the minimum number 𝑚 of points such that each segment contains at least one point. That is, find a
set of integers 𝑋 of the minimum size such that for any segment [𝑎𝑖, 𝑏𝑖] there is a point 𝑥 ∈ 𝑋 such
that 𝑎𝑖 ≤ 𝑥 ≤ 𝑏𝑖.
*/

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  // First, we sort the segments by their ending points.
  std::sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) {
    return a.end < b.end;
  });
  
  /*
  for (const Segment &segment : segments) {
    std::cout << "[" << segment.start << ", " << segment.end << "] ";
  }
  std::cout << '\n';
  */

  // Then, we iterate over the sorted segments and add the ending point of each segment,
  // we delete the next segment if it overlaps with the current one.
  for (int i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].end);
    int current_end = segments[i].end;
    while ((i + 1 < segments.size()) && (segments[i + 1].start <= current_end)) {
      ++i;
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
