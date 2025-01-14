/* Test floating-point conversions.  Standard types and long double.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do run } */
/* { dg-options "" } */
/* { dg-options "-mcmodel=small" { target ia16-*-* } } */

#include <float.h>
#include "fp-int-convert.h"

int
main (void)
{
  TEST_I_F(signed char, unsigned char, long double, LDBL_MANT_DIG);
  TEST_I_F(signed short, unsigned short, long double, LDBL_MANT_DIG);
  TEST_I_F(signed int, unsigned int, long double, LDBL_MANT_DIG);
  TEST_I_F(signed long, unsigned long, long double, LDBL_MANT_DIG);
  TEST_I_F(signed long long, unsigned long long, long double, LDBL_MANT_DIG);
  exit (0);
}
