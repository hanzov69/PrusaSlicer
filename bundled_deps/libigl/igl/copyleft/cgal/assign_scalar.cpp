// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2015 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "assign_scalar.h"

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Epeck::FT & cgal,
  CGAL::Epeck::FT & d)
{
  d = cgal;
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Epeck::FT & _cgal,
  double & d)
{
  // FORCE evaluation of the exact type otherwise interval might be huge.
  const CGAL::Epeck::FT cgal = _cgal.exact();
  const auto interval = CGAL::to_interval(cgal);
  d = interval.first;
  do {
      const double next = nextafter(d, interval.second);
      if (CGAL::abs(cgal-d) < CGAL::abs(cgal-next)) break;
      d = next;
  } while (d < interval.second);
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Epeck::FT & _cgal,
  float& d)
{
  // FORCE evaluation of the exact type otherwise interval might be huge.
  const CGAL::Epeck::FT cgal = _cgal.exact();
  const auto interval = CGAL::to_interval(cgal);
  d = interval.first;
  do {
      const float next = nextafter(d, float(interval.second));
      if (CGAL::abs(cgal-d) < CGAL::abs(cgal-next)) break;
      d = next;
  } while (d < float(interval.second));
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const double & c,
  double & d)
{
  d = c;
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const float& c,
  float& d)
{
  d = c;
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const float& c,
  double& d)
{
  d = c;
}

// The Exact_predicates_exact_constructions_kernel_with_sqrt typedef is only
// available when CGAL is built against LEDA or CORE. With CGAL_DISABLE_GMP=ON
// (Boost.Multiprecision backend), neither is present and these overloads must
// be elided so the file still compiles.
#if defined(CGAL_USE_LEDA) || defined(CGAL_USE_CORE)
IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT & cgal,
  CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT & d)
{
  d = cgal;
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT & cgal,
  double & d)
{
  const auto interval = CGAL::to_interval(cgal);
  d = interval.first;
  do {
      const double next = nextafter(d, interval.second);
      if (CGAL::abs(cgal-d) < CGAL::abs(cgal-next)) break;
      d = next;
  } while (d < interval.second);
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt::FT & cgal,
  float& d)
{
  const auto interval = CGAL::to_interval(cgal);
  d = interval.first;
  do {
      const float next = nextafter(d, float(interval.second));
      if (CGAL::abs(cgal-d) < CGAL::abs(cgal-next)) break;
      d = next;
  } while (d < float(interval.second));
}
#endif

#ifndef WIN32

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Simple_cartesian<mpq_class>::FT & cgal,
  CGAL::Simple_cartesian<mpq_class>::FT & d)
{
  d = cgal;
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Simple_cartesian<mpq_class>::FT & cgal,
  double & d)
{
  const auto interval = CGAL::to_interval(cgal);
  d = interval.first;
  do {
      const double next = nextafter(d, interval.second);
      if (CGAL::abs(cgal-d) < CGAL::abs(cgal-next)) break;
      d = next;
  } while (d < interval.second);
}

IGL_INLINE void igl::copyleft::cgal::assign_scalar(
  const CGAL::Simple_cartesian<mpq_class>::FT & cgal,
  float& d)
{
  const auto interval = CGAL::to_interval(cgal);
  d = interval.first;
  do {
      const float next = nextafter(d, float(interval.second));
      if (CGAL::abs(cgal-d) < CGAL::abs(cgal-next)) break;
      d = next;
  } while (d < float(interval.second));
}

#endif // WIN32
