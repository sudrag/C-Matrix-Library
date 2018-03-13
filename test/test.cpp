/** MIT License
Copyright (c) 2018 Sudarshan Raghunathan
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *@copyright Copyright 2018 Sudarshan Raghunathan
 *@file test.cpp
 *@author Sudarshan Raghunathan
 *@brief Test cases for code coverage.
 */


#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <../include/matrix_functions.hpp>
using namespace std;
/**
*@brief Test function to verify the output matrix indices 
*@return 1 if multiplication went successfully
*/
int testing_multiplication() {
  vector<vector<int> > ar = { { { 1, 5, 2 }, { 3, 3, 1 } } };
  vector<vector<int> > cr = { { { 0, 0 }, { 0, 0 }, { 0, 0 } } };
  vector<vector<int> > br = { };
  Matrix<int, 2, 3> a(ar);
  Matrix<int, 3, 2> c(cr);
  Matrix<int, 2, 2> b(br);
  b=a*c;
  if(b.nrow==a.nrow && b.ncol==c.ncol){
    return 1;
  }
  else 
    return 0;
}
/**
*@brief Test function to see if output of multiplication occurs only if two matrices have correct indices
*@return true if multiplication went successfully
*/

bool testing_multi_index1() {
  vector<vector<int> > ar = { { { 1, 5, 2 }, { 3, 3, 1 } } };
  vector<vector<int> > cr = { { { 0, 0 }, { 0, 0 }, { 0, 0 } } };
  vector<vector<int> > br = { };
  Matrix<int, 2, 3> a(ar);
  Matrix<int, 3, 2> c(cr);
  Matrix<int, 2, 2> b(br);
  b=a*c;
  if(a.ncol==c.nrow){
    return true;
  }
  else 
    return false;
}
/**
*@brief Test function to see if one of the indices are negative
*@return flag1 is false if one of the input indices is negative
*/
bool testing_negindex() {
  vector<vector<int> > ar = { { { 1, 5, 2 }, { 3, 3, 1 } } };
  Matrix<int, -2, 3> a(ar);
  return a.flag1;
}
/**
*@brief Test multiplication if indices are wrong 
*@return flag2 returns false when indices are wrong
*/
bool testing_multi_index() {
  vector<vector<int> > ar = { { { 1, 5 }, { 3, 3} } };
  vector<vector<int> > cr = { { { 0, 0 }, { 0, 0 }, { 0, 0 } } };
  vector<vector<int> > br = { };
  Matrix<int, 2, 2> a(ar);
  Matrix<int, 3, 2> c(cr);
  Matrix<int, 2, 2> b(br);
  b=a*c;
  b.print();
  return b.flag2;
}
/**
*@brief Function to test successful transpose 
*@return 1 if transpose is successful
*/
int testing_transpose(){
  vector<vector<int> > ar = { { { 1, 5, 2 }, { 3, 3, 1 } } };
  vector<vector<int> > cr = { { { 0, 0 }, { 0, 0 }, { 0, 0 } } };
  Matrix<int, 2, 3> a(ar);
  Matrix<int, 3, 2> c(cr);
  if(a.nrow == c.ncol && a.ncol == c.nrow)
    return 1;
  else
    return 0;

}

/**
 *@brief Test case to ensure correct multiplication output
 */
TEST(MatrixTest, multiplication_output_index) {
  EXPECT_EQ(testing_multiplication(), 1);
}

/**
 *@brief Test case to check if any indices are negative
 */
TEST(MatrixTest, negative_index_check) {
  EXPECT_EQ(testing_negindex(), false);
}

/**
 *@brief Test case to ensure correct multiplication input
 */
TEST(MatrixTest, multiplication_index_check_fail) {
  EXPECT_EQ(testing_multi_index(), false);
}
/**
 *@brief Test case to see if it fails for bad multiplication inputs
 */
TEST(MatrixTest, multiplication_index_check_pass) {
  EXPECT_EQ(testing_multi_index1(), true);
}
/**
 *@brief Test case to ensure correct transposition
 */
TEST(MatrixTest, transpose_output_test) {
  EXPECT_EQ(testing_transpose(), 1);
}

