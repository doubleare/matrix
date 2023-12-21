#include "s21_matrix_oop.h"

bool s21::S21Matrix::operator==(const S21Matrix& o) {
  bool ret = false;
  if (cols_ == o.cols_ && rows_ == o.rows_) {
    ret = true;
    for (int i = 0; i < rows_ && ret == true; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - o.matrix_[i][j]) > 9e-7) ret = false;
      }
    }
  }
  return ret;
}

s21::S21Matrix s21::S21Matrix::operator*(double v) {
  S21Matrix r = *this;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      r.matrix_[i][j] *= v;
    }
  }
  return r;
}

s21::S21Matrix& s21::S21Matrix::operator*=(double v) {
  return *this = *this * v;
}

s21::S21Matrix s21::S21Matrix::operator*(const S21Matrix& o) {
  S21Matrix res = *this;
  try {
    if (cols_ == o.rows_) {
      res = S21Matrix(rows_, o.cols_);
      for (int i = 0; i < rows_; i++) {
        for (int c = 0; c < o.cols_; c++) {
          double sum = 0;
          for (int r = 0, j = 0; r < o.rows_; r++, j++) {
            sum += matrix_[i][j] * o.matrix_[r][c];
          }
          res.matrix_[i][c] = sum;
        }
      }
    } else {
      throw std::out_of_range(
          "column count of first m != rows count of second m");
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
    exit(1);
  }

  return res;
}

s21::S21Matrix& s21::S21Matrix::operator*=(const S21Matrix& o) {
  return *this = *this * o;
}

s21::S21Matrix s21::S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix r = *this;
  try {
    if (cols_ == o.cols_ && rows_ == o.rows_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          r.matrix_[i][j] += o.matrix_[i][j];
        }
      }
    } else {
      throw std::out_of_range("diff size of matrix");
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
    exit(1);
  }
  return r;
}

s21::S21Matrix& s21::S21Matrix::operator+=(const S21Matrix& o) {
  return *this = *this + o;
}

s21::S21Matrix s21::S21Matrix::operator-(const S21Matrix& o) {
  S21Matrix r = *this;
  try {
    if (cols_ == o.cols_ && rows_ == o.rows_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          r.matrix_[i][j] -= o.matrix_[i][j];
        }
      }
    } else {
      throw std::out_of_range("diff size of matrix");
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    exit(1);
  }
  return r;
}

s21::S21Matrix& s21::S21Matrix::operator-=(const S21Matrix& o) {
  return *this = *this - o;
}

double& s21::S21Matrix::operator()(int r, int c) {
  try {
    if (rows_ <= r || cols_ <= c)
      throw std::out_of_range("Incorrect input, index is out of range");
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    exit(1);
  }
  return matrix_[r][c];
}

double& s21::S21Matrix::operator()(int r, int c) const {
  try {
    if (rows_ <= r || cols_ <= c)
      throw std::out_of_range("Incorrect input, index is out of range");
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    exit(1);
  }
  return matrix_[r][c];
}