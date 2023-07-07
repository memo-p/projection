/*
 * Copyright (C) 2020 Guillaume Perez
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
#pragma once

#include <armadillo>

#include "l1/bucket.hpp"
#include "l1/bucket_filter.hpp"
#include "l1/condat.hpp"

namespace proj {
namespace l1 {

inline double norm(double* y, int dimension) {
  double s = 0;
  for (size_t i = 0; i < dimension; i++)  {
    s += abs(y[i]);
  }
  return s;
}

inline void project(double* y, double* x, int dimension, const double a) {
  ProjC(y, x, dimension, a);
}

inline void project(arma::vec& y, arma::vec& x, const double a) {
  arma::vec yabs = arma::abs(y);
  arma::vec signY = arma::sign(y);
  project(yabs.memptr(), x.memptr(), yabs.n_elem, a);
  x %= signY;
}

}  // namespace l1
} // namespace proj