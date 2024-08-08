import insertion_sort;

#include <print>
#include <random>
#include <ranges>
#include <string>
#include <vector>

namespace rng = std::ranges;
namespace vws = std::views;

using std::print;
using std::println;
using std::string;
using std::vector;

auto get_random_vector() -> vector<int> {
  std::random_device rd;
  vector<int> res;
  res.reserve(50);
  std::uniform_int_distridution<int> dist(-10000, 10000);

  for (auto&& i: vws::iota(0, 50)) res.push_back(dist(rd));

  return res;
}

auto main(int argc, char* argv[]) -> int {
  vector<int> to_sort = [argc, argv]() {
    if (argc > 1) {
      return (argv + 1) | vws::take(argc - 1)
             | vws::transform([](auto&& str) { return std::stoi(str); })
             | rng::to<vector>();
    } else
      return get_random_vector();
  }();
}
