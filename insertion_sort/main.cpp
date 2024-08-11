#include <print>
#include <random>
#include <ranges>
#include <span>
#include <string>
#include <vector>

namespace rng = std::ranges;
namespace vws = std::views;

using std::print;
using std::println;
using std::vector;

auto get_random_vector() -> vector<int> {
  std::random_device rd;
  vector<int> res;
  res.reserve(30);
  std::uniform_int_distribution<int> dist(-10000, 10000);

  for (auto&& i: vws::iota(0, 30)) res.push_back(dist(rd));

  return res;
}

void vec_print(vector<int>& vec) {
  for (auto&& n: vec) print("{} ", n);
  println();
}

void insertion_sort(vector<int>& vec) {
  if (vec.size() < 2) return;
  for (ssize_t iter = 1, end = vec.size(); iter < end; ++iter) {
    vec_print(vec);
    auto key  = vec[iter];
    auto foot = iter - 1;
    while (foot >= 0 and vec[foot] > key) {
      vec[foot + 1] = vec[foot];
      --foot;
    }
    vec[foot + 1] = key;
  }
  vec_print(vec);
}

auto main(int argc, char* argv[]) -> int {
  vector<int> to_sort = [argc, argv]() {
    if (argc > 1) {
      return std::span(argv + 1, argv + argc)
             | vws::transform([](auto&& str) { return std::stoi(str); })
             | rng::to<vector>();
    } else
      return get_random_vector();
  }();

  insertion_sort(to_sort);

  return EXIT_SUCCESS;
}
