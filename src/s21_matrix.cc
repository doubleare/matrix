#include "s21_matrix_oop.h"

s21::S21Matrix::S21Matrix() { this->create(3, 3); }

s21::S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  this->create(rows_, cols_);
}

void s21::S21Matrix::crt_copy(const S21Matrix& o) {
  this->create(o.rows_, o.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) matrix_[i][j] = o.matrix_[i][j];
  }
}

s21::S21Matrix::S21Matrix(const S21Matrix& o) { this->crt_copy(o); }

s21::S21Matrix& s21::S21Matrix::operator=(const S21Matrix& o) {
  if (this != &o) {
    this->~S21Matrix();
    this->crt_copy(o);
  }
  return *this;
}

s21::S21Matrix::S21Matrix(S21Matrix&& o) noexcept { *this = o; }

s21::S21Matrix& s21::S21Matrix::operator=(S21Matrix&& o) {
  if (this != &o) {
    this->~S21Matrix();
    this->crt_copy(o);
  }
  return *this;
}

s21::S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
  delete[] matrix_;
}

void s21::S21Matrix::create(int r, int c) {
  try {
    rows_ = r;
    cols_ = c;
    if (rows_ > 0 && cols_ > 0) {
      matrix_ = new double* [rows_] {};
      for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]{};
    } else {
      throw std::out_of_range("matrix rows and cols must be greater then 0");
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
    exit(1);
  }
}

int s21::S21Matrix::get_rows() { return rows_; }

int s21::S21Matrix::get_cols() { return cols_; }

void s21::S21Matrix::resize(int r, int c) {
  S21Matrix res(r, c);
  for (auto i = 0; i < rows_ && i < r; i++) {
    for (auto j = 0; j < cols_ && j < c; j++) res.matrix_[i][j] = matrix_[i][j];
  }
  *this = res;
}

void s21::S21Matrix::set_rows(int n) {
  if (rows_ != n && n > 0) this->resize(n, cols_);
}

void s21::S21Matrix::set_cols(int n) {
  if (cols_ != n && n > 0) this->resize(rows_, n);
}

void s21::S21Matrix::minor_calc(const S21Matrix& o, int i, int j) {
  for (int r = 0, rt = 0; r < rows_; r++) {
    if (r == j) continue;
    for (int c = 0, ct = 0; c < cols_; c++) {
      if (c == i) continue;
      o.matrix_[rt][ct++] = matrix_[r][c];
    }
    rt++;
  }
}

// function for test.

void s21::S21Matrix::fill_m(double s) {
  double v = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++, v += s) matrix_[i][j] = v;
  }
}