/* This file is part of the 'stringi' package for R.
 * Copyright (C) 2013-2014 Marek Gagolewski, Bartek Tartanus
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#ifndef uconfig_local_h
#define uconfig_local_h

#define U_DISABLE_RENAMING 1



/* localtime_r is not a C++98 nor C99 function: it is POSIX.  Solaris has
   it, but only for C (thanks to Kurt Hornik for pointing this out) */
#if U_PLATFORM == U_PF_SOLARIS
/*extern struct tm *localtime_r(const time_t *, struct tm *); */
#ifndef _REENTRANT
#define _REENTRANT 1
#endif

/* avoid feature_tests.h errors */
#if defined(_STDC_C99) && (defined(__XOPEN_OR_POSIX) && !defined(_XPG6))
#define _XPG6
#elif !defined(_STDC_C99) && (defined(__XOPEN_OR_POSIX) && defined(_XPG6))
#undef _XPG6
#endif

#endif


#endif
