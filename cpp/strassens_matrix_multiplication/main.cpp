#include <iostream>
#include <iterator>
#include <vector>

template <size_t Rows, size_t Columns, typename T>
struct Matrix {
  std::vector<T> vec;

  void print() {
    for (size_t row = 0; row < Rows; ++row) {
      for (size_t column = 0; column < Columns; ++column) {
        std::cout << this->operator()(row, column) << ' ';
      }
      std::cout << '\n';
    }
  }

  T& operator()(size_t row, size_t column) {
    return vec[column + (row * Columns)];
  }
};

template <size_t Rows, size_t K, size_t Columns, typename T>
Matrix<Rows, Columns, T> operator*(const Matrix<Rows, K, T>& left,
                                   const Matrix<K, Columns, T>& right) {
  Matrix<Rows, Columns, T> result;
  std::vector<T> vec_result;
  vec_result.reserve(Rows * Columns);

  result.vec = std::move(vec_result);
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args(argv, argv + argc);
  std::ostream_iterator<std::string> out(std::cout, "\n");
  std::copy(args.begin(), args.end(), out);
}
