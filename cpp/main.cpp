#include <iterator>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<std::string> args(argv, argv + argc);
  std::ostream_iterator<std::string> out(std::cout, "\n");
  std::copy(args.begin(), args.end(), out);
}
