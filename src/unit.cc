#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

s21::S21Matrix m1, m2, m3, m4, res;

TEST(MatrixTest, EQ_matrix) {
  m1.fill_m(1);
  m2.fill_m(1);

  EXPECT_EQ(m1.EqMatrix(m2), true);
  EXPECT_EQ(m1 == m2, true);

  m1(1, 1) = 26;
  m2(1, 1) = 26.1;

  EXPECT_EQ(m1.EqMatrix(m2), false);
  EXPECT_EQ(m1 == m2, false);
}

TEST(MatrixTest, SUM_matrix) {
  m1.fill_m(1.5);
  m2.fill_m(1.5);
  m3.fill_m(0.345344);
  m4.fill_m(0.345344);

  EXPECT_EQ((m1 + m3) == (m2 + m4), true);

  m1 += m3;
  m2 += m4;

  EXPECT_EQ(m1 == m2, true);

  m1.SumMatrix(m3);
  m2.SumMatrix(m4);

  EXPECT_EQ(m1 == m2, true);
}

TEST(MatrixTest, SUB_matrix) {
  m1.fill_m(1.5);
  m2.fill_m(1.5);

  EXPECT_EQ((m1 - m3) == (m2 - m4), true);

  m1 -= m3;
  m2 -= m4;

  EXPECT_EQ(m1 == m2, true);

  m1.SubMatrix(m3);
  m2.SubMatrix(m4);

  EXPECT_EQ(m1 == m2, true);
}

TEST(MatrixTest, mult_matrix) {
  m1.set_rows(3);
  m1.set_cols(2);

  m2.set_rows(2);
  m2.set_cols(3);

  res(0, 0) = 9;
  res(0, 1) = 11;
  res(0, 2) = 17;
  res(1, 0) = 12;
  res(1, 1) = 13;
  res(1, 2) = 22;
  res(2, 0) = 15;
  res(2, 1) = 15;
  res(2, 2) = 27;

  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;
  m1(2, 0) = 3;
  m1(2, 1) = 6;

  m2(0, 0) = 1;
  m2(0, 1) = -1;
  m2(0, 2) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  m2(1, 2) = 4;

  EXPECT_EQ(m1 * m2 == res, true);

  m1.MulMatrix(m2);

  EXPECT_EQ(m1 == res, true);
}

TEST(MatrixTest, mult_number_matrix) {
  res.set_rows(1);
  res.set_cols(3);

  res.fill_m(0.5);
  res.MulNumber(2.2);

  EXPECT_DOUBLE_EQ(res(0, 0), 0);
  EXPECT_DOUBLE_EQ(res(0, 1), 1.1);
  EXPECT_DOUBLE_EQ(res(0, 2), 2.2);

  res *= 3;

  EXPECT_DOUBLE_EQ(res(0, 0), 0);
  EXPECT_DOUBLE_EQ(res(0, 1), 3.3);
  EXPECT_DOUBLE_EQ(res(0, 2), 6.6);
}

TEST(MatrixTest, Determinant) {
  m3(0, 0) = 2;
  m3(0, 1) = 5;
  m3(0, 2) = 7;
  m3(1, 0) = 6;
  m3(1, 1) = 3;
  m3(1, 2) = 4;
  m3(2, 0) = 5;
  m3(2, 1) = -2;
  m3(2, 2) = -3;

  EXPECT_EQ(m3.Determinant(), -1);

  m3.fill_m(1);

  EXPECT_EQ(m3.Determinant(), 0);
}

TEST(MatrixTest, Transpose) {
  res.set_rows(2);
  res.set_cols(3);

  res(0, 0) = 1;
  res(0, 1) = 2;
  res(0, 2) = 3;
  res(1, 0) = 4;
  res(1, 1) = 5;
  res(1, 2) = 6;

  m1.set_rows(3);
  m1.set_cols(2);

  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;
  m1(2, 0) = 3;
  m1(2, 1) = 6;

  EXPECT_EQ(m1.Transpose() == res, true);
}

TEST(MatrixTest, CalcComplements) {
  res.set_rows(3);

  res(0, 0) = 0;
  res(0, 1) = 10;
  res(0, 2) = -20;
  res(1, 0) = 4;
  res(1, 1) = -14;
  res(1, 2) = 8;
  res(2, 0) = -8;
  res(2, 1) = -2;
  res(2, 2) = 4;

  m3(0, 0) = 1;
  m3(0, 1) = 2;
  m3(0, 2) = 3;
  m3(1, 0) = 0;
  m3(1, 1) = 4;
  m3(1, 2) = 2;
  m3(2, 0) = 5;
  m3(2, 1) = 2;
  m3(2, 2) = 1;

  EXPECT_EQ(m3.CalcComplements() == res, true);
}

TEST(MatrixTest, InverseMatrix) {
  res(0, 0) = 1;
  res(0, 1) = -1;
  res(0, 2) = 1;
  res(1, 0) = -38;
  res(1, 1) = 41;
  res(1, 2) = -34;
  res(2, 0) = 27;
  res(2, 1) = -29;
  res(2, 2) = 24;

  m3(0, 0) = 2;
  m3(0, 1) = 5;
  m3(0, 2) = 7;
  m3(1, 0) = 6;
  m3(1, 1) = 3;
  m3(1, 2) = 4;
  m3(2, 0) = 5;
  m3(2, 1) = -2;
  m3(2, 2) = -3;

  EXPECT_EQ(m3.InverseMatrix() == res, true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}