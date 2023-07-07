/*
 * Copyright (C) 2023 Guillaume Perez
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
 *
 * From the code of Laurent Condat: https://lcondat.github.io
 */

#include <limits>
#include <random>

namespace proj {

inline void FillRandMatrix(double* mt, const int nrows, const int ncols) {
  for (std::size_t i = 0; i < nrows; i++) {
    for (std::size_t j = 0; j < ncols; j++) {
      std::size_t id = i * ncols + j;
      mt[id] = ((double)rand()) / std::numeric_limits<int>::max();
    }
  }
}

inline void Transpose(double* y, double* y_t, const int nrows,
                      const int ncols) {
  for (std::size_t i = 0; i < nrows; i++) {
    for (std::size_t j = 0; j < ncols; j++) {
      std::size_t id = i * ncols + j;
      std::size_t id_t = j * nrows + i;
      y_t[id_t] = y[id];
    }
  }
}

inline double NormL2(double* y, const int nrows, const int ncols) {
  double sum = 0.;
  for (std::size_t i = 0; i < nrows; i++) {
    for (std::size_t j = 0; j < ncols; j++) {
      std::size_t id = i * ncols + j;
      sum += y[id] * y[id];
    }
  }
  return sqrt(sum);
}

inline double NormL2Diff(double* y, double* x, const int nrows,
                         const int ncols) {
  double sum = 0.;
  for (std::size_t i = 0; i < nrows; i++) {
    for (std::size_t j = 0; j < ncols; j++) {
      std::size_t id = i * ncols + j;
      double v = y[id] - x[id];
      sum += v * v;
    }
  }
  return sqrt(sum);
}

inline double RowSparsity(double* y, const int nrows, const int ncols) {
  int nb_zeroed = 0;
  for (std::size_t i = 0; i < nrows; i++) {
    double sum = 0.;
    for (std::size_t j = 0; j < ncols; j++) {
      std::size_t id = i * ncols + j;
      sum += fabs(y[id]);
    }
    if (sum <= 1e-6) {
      nb_zeroed++;
    }
  }
  return static_cast<double>(nb_zeroed)/nrows;
}


}  // namespace proj