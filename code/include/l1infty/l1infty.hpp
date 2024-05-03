/*
 * Copyright (C) 2024 Guillaume Perez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROJCODE_INCLUDE_L1INFTY_L1INFTY_HPP
#define PROJCODE_INCLUDE_L1INFTY_L1INFTY_HPP

#include "l1infty/naive.hpp"
#include "l1infty/sortedRows.hpp"
#include "l1infty/heapRows.hpp"
#include "l1infty/sortedRowsCols.hpp"
#include "l1infty/sortedRowsColsInv.hpp"
#include "l1infty/heapRowsCols.hpp"
#include "l1infty/heapRowsheapCols.hpp"
#include "l1infty/heapRowsheapColsInv.hpp"
#include "l1infty/quat.hpp"
#include "l1infty/semismooth.hpp"
#include "l1infty/Bejar.hpp"
#include "l1infty/bilevel.hpp"
#include "l1infty/bilevelParallel.hpp"
#include "utils/gen.hpp"

namespace proj {
namespace l1infty {

inline double norm(double* y, int nrows, int ncols) {
  double s = 0;
  double max_v = 0;
  for (size_t i = 0; i < nrows * ncols; i++) {
    if (i % ncols == 0) {
      s += max_v;
      max_v = 0;
    }
    max_v = fmax(abs(*y), max_v);
    y++;
  }
  s += max_v;
  return s;
}


inline double normColumns(double* y, int nrows, int ncols) {
  double s = 0;
  double max_v = 0;
  for (size_t j = 0; j < ncols; j++) {
    max_v = 0;
    for (size_t i = 0; i < nrows; i++) {
      max_v = fmax(abs(y[i*ncols + j]), max_v);
    }
    s += max_v;
  }
  return s;
}

inline void project(double* y, double* x, int nrows, int ncols,
                    const double C) {
  DJCHU(y, x, nrows, ncols, C);
}

inline void projectColumns(double* y, double* x, int nrows, int ncols,
                    const double C) {
  double * y_t = new double[nrows*ncols];
  double * x_t = new double[nrows*ncols];
  Transpose(y, y_t, nrows, ncols);
  DJCHU(y_t, x_t, ncols, nrows, C);
  Transpose(x_t, x, ncols, nrows);
  delete y_t;
  delete x_t;
}

inline void projectBilevel(double* y, double* x, int nrows, int ncols,
                    const double C) {
  Bilevel(y, x, nrows, ncols, C);
}

inline void projectBilevelColumns(double* y, double* x, int nrows, int ncols,
                    const double C) {
  double * y_t = new double[nrows*ncols];
  double * x_t = new double[nrows*ncols];
  Transpose(y, y_t, nrows, ncols);
  Bilevel(y_t, x_t, ncols, nrows, C);
  Transpose(x_t, x, ncols, nrows);
  delete y_t;
  delete x_t;
}

inline void projectBilevelParallel(double* y, double* x, int nrows, int ncols,
                    const double C, int nb_workers) {
  ThreadPool tp(nb_workers);
  BilevelParallel(y, x, nrows, ncols, C, nb_workers, tp);
}

}  // namespace l1infty
}  // namespace proj


#endif /* PROJCODE_INCLUDE_L1INFTY_L1INFTY_HPP */
