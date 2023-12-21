#ifndef __S21_MATRIX_OOP_H__
#define __S21_MATRIX_OOP_H__

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace s21 {

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& o);
  S21Matrix(S21Matrix&& o) noexcept;
  ~S21Matrix();

  S21Matrix& operator=(S21Matrix&& o);
  S21Matrix& operator=(const S21Matrix& o);

  S21Matrix operator*(double v);
  S21Matrix& operator*=(double v);

  S21Matrix operator*(const S21Matrix& o);
  S21Matrix& operator*=(const S21Matrix& o);

  S21Matrix operator+(const S21Matrix& o);
  S21Matrix& operator+=(const S21Matrix& o);

  S21Matrix operator-(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);

  bool operator==(const S21Matrix& o);
  double& operator()(int row, int col);
  double& operator()(int row, int col) const;

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  double Determinant();

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  int get_cols();
  int get_rows();

  void set_rows(int n);
  void set_cols(int n);

  void print_m();
  void fill_m(double s);

 private:
  int rows_, cols_;
  double** matrix_;

  void create(int r, int c);
  void resize(int r, int c);

  void crt_copy(const S21Matrix& o);
  void minor_calc(const S21Matrix& o, int i, int j);
};

}  // namespace s21

#endif  // __S21_MATRIX_OOP_H__