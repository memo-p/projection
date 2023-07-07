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

#include <algorithm>
#include <armadillo>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include "l1w/bucket.hpp"
#include "l1w/bucket_filter.hpp"
#include "l1w/sort.hpp"
#include "l1w/split.hpp"

namespace proj {
namespace l1w {

inline double norm(double* y, double* w, int dimension) {
  double s = 0;
  for (size_t i = 0; i < dimension; i++)  {
    s += abs(y[i])*w[i];
  }
  return s;
}

inline void project(double* y, double* w, double* x, int dimension, const double a) {
  ProjWSplit(y, w, x, dimension, a);
}

void project(arma::vec& y, arma::vec& w, arma::vec& x, const double a) {
  arma::vec yabs = arma::abs(y);
  arma::vec signY = arma::sign(y);
  ProjWSplit(yabs.memptr(), w.memptr(), x.memptr(), yabs.n_elem, a);
  x %= signY;
}

}  // namespace l1w
}  // namespace proj
