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
int eraDatini(const eraLEAPSECOND *builtin, int n_builtin,
              eraLEAPSECOND **leapseconds);

/*
** For thread safety we want a way to define thread-local variables.
** If no TLS is available, fall back to ordinary storage and disable
** thread safety for those variables.
*/
#if defined(_MSC_VER)
#  define ERFA_THREAD_LOCAL __declspec(thread)
#elif defined(__cplusplus) && __cplusplus >= 201103L
#  define ERFA_THREAD_LOCAL thread_local
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#  define ERFA_THREAD_LOCAL _Thread_local
#elif defined(__GNUC__) || defined(__clang__)
#  define ERFA_THREAD_LOCAL __thread
#else
#  define ERFA_THREAD_LOCAL
#endif

#endif
