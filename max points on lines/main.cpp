#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
  std::vector <int> result;
    std::sort(segments.begin(),segments.end(),[](Segment &s1,Segment &s2){
        return s1.second<s2.second;
    });
    result.push_back(segments[0].second);
    for (auto s : segments) {
      if(s.first>result.back()){
          result.push_back(s.second);
      }
  }

  return result;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count;
  std::vector <Segment> segments(segments_count);
  for (auto &s:segments) {
    std::cin >> s.first >> s.second;
  }

  auto points = get_covering_set(std::move(segments));
  std::cout << points.size() << std::endl;
  for (auto point:points) {
    std::cout << point << " ";
  }
  std::cout << std::endl;
}
