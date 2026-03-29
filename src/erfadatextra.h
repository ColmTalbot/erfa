/*
** Copyright (C) 2019, NumFOCUS Foundation.
**
** Licensed under a 3-clause BSD style license - see LICENSE
**
** This file is NOT derived from SOFA sources.
**
*/


#ifndef _ERFA_DAT_EXTRA_H
#define _ERFA_DAT_EXTRA_H

#include "erfaextra.h"

/*
**  Get the leap second table, initializing it to the built-in version
**  if necessary.
**
**  This function is for internal use in dat.c only and should
**  not be used elsewhere.
*/
int eraDatini(eraLEAPSECOND **leapseconds);

/* Dates and Delta(AT)s */
static const eraLEAPSECOND builtin_changes[] = {
   { 1960,  1,  1.4178180 },
   { 1961,  1,  1.4228180 },
   { 1961,  8,  1.3728180 },
   { 1962,  1,  1.8458580 },
   { 1963, 11,  1.9458580 },
   { 1964,  1,  3.2401300 },
   { 1964,  4,  3.3401300 },
   { 1964,  9,  3.4401300 },
   { 1965,  1,  3.5401300 },
   { 1965,  3,  3.6401300 },
   { 1965,  7,  3.7401300 },
   { 1965,  9,  3.8401300 },
   { 1966,  1,  4.3131700 },
   { 1968,  2,  4.2131700 },
   { 1972,  1, 10.0       },
   { 1972,  7, 11.0       },
   { 1973,  1, 12.0       },
   { 1974,  1, 13.0       },
   { 1975,  1, 14.0       },
   { 1976,  1, 15.0       },
   { 1977,  1, 16.0       },
   { 1978,  1, 17.0       },
   { 1979,  1, 18.0       },
   { 1980,  1, 19.0       },
   { 1981,  7, 20.0       },
   { 1982,  7, 21.0       },
   { 1983,  7, 22.0       },
   { 1985,  7, 23.0       },
   { 1988,  1, 24.0       },
   { 1990,  1, 25.0       },
   { 1991,  1, 26.0       },
   { 1992,  7, 27.0       },
   { 1993,  7, 28.0       },
   { 1994,  7, 29.0       },
   { 1996,  1, 30.0       },
   { 1997,  7, 31.0       },
   { 1999,  1, 32.0       },
   { 2006,  1, 33.0       },
   { 2009,  1, 34.0       },
   { 2012,  7, 35.0       },
   { 2015,  7, 36.0       },
   { 2017,  1, 37.0       }
};
static const int n_builtin_changes = 42;

/*
** For thread safety we want a way to define thread-local variables.
** If no TLS is available, fall back to ordinary storage and disable
** thread safety for those variables.
*/
#if defined(_MSC_VER)
#  define ERFA_THREAD_LOCAL __declspec(thread)
#  define ERFA_HAS_THREAD_LOCAL 1
#elif defined(__cplusplus) && __cplusplus >= 201103L
#  define ERFA_THREAD_LOCAL thread_local
#  define ERFA_HAS_THREAD_LOCAL 1
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#  define ERFA_THREAD_LOCAL _Thread_local
#  define ERFA_HAS_THREAD_LOCAL 1
#elif defined(__GNUC__) || defined(__clang__)
#  define ERFA_THREAD_LOCAL __thread
#  define ERFA_HAS_THREAD_LOCAL 1
#else
#  define ERFA_THREAD_LOCAL
#  define ERFA_HAS_THREAD_LOCAL 0
#endif

#endif
