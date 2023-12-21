#include "s21_matrix_oop.h"

bool s21::S21Matrix::EqMatrix(const S21Matrix& other) {
  return (*this == other);
}

void s21::S21Matrix::SumMatrix(const S21Matrix& other) { *this += other; }

void s21::S21Matrix::SubMatrix(const S21Matrix& other) { *this -= other; }

void s21::S21Matrix::MulNumber(const double num) { *this *= num; }

void s21::S21Matrix::MulMatrix(const S21Matrix& other) { *this *= other; }

double s21::S21Matrix::Determinant() {
  double res = 0;
  try {
    if (rows_ == cols_) {
      if (rows_ == 1) {
        res = matrix_[0][0];
      } else if (rows_ == 2) {
        res = (matrix_[0][0] * matrix_[1][1]) - (matrix_[0][1] * matrix_[1][0]);
      } else {
        S21Matrix tmp(rows_ - 1, cols_ - 1);
        for (int i = 0; i < cols_; i++) {
          double xsum = 0;
          this->minor_calc(tmp, i, 0);
          xsum = tmp.Determinant();
          res += (i % 2 == 0 ? matrix_[0][i] : -(matrix_[0][i])) * xsum;
        }
      }
    } else {
      throw std::out_of_range("matrix is ​​not square");
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
    exit(1);
  }
  return res;
}

s21::S21Matrix s21::S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) res.matrix_[i][j] = matrix_[j][i];
  }
  return res;
}

s21::S21Matrix s21::S21Matrix::CalcComplements() {
  S21Matrix res(rows_, cols_);
  try {
    if (rows_ == cols_ && rows_ > 1) {
      S21Matrix tmp(rows_ - 1, cols_ - 1);
      for (int r = 0; r < rows_; r++) {
        for (int i = 0; i < cols_; i++) {
          double xsum = 0;
          this->minor_calc(tmp, i, r);
          xsum = tmp.Determinant();
          res.matrix_[r][i] = (i + r) % 2 == 0 ? xsum : -xsum;
        }
      }
    } else {
      throw std::out_of_range("matrix is not square");
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
    exit(1);
  }
  return res;
}

s21::S21Matrix s21::S21Matrix::InverseMatrix() {
  S21Matrix res(rows_, cols_);
  try {
    if (this->Determinant() != 0) {
      res = this->CalcComplements().Transpose() * (1 / this->Determinant());
    } else {
      throw std::out_of_range("invers matrix does not exist");
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n\n";
    exit(1);
  }
  return res;
}
