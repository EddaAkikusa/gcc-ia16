/* Test for diagnostics for implicit conversions between integer types
   C++ equivalent of gcc/testsuite/gcc.dg/Wconversion-integer.c  */

// { dg-do compile { target { stdint_types } } } 
// { dg-options "-fsigned-char -Wconversion" } 

#include <stdint.h>
#include <limits.h>

void fsc (signed char sc);
void fuc (unsigned char uc);
unsigned fui (uint_least32_t ui);
void fsi (int_least32_t ui);

void h (int x)
{
  uint_least32_t ui = 3;
  int_least32_t   si = 3;
  unsigned char uc = 3;
  signed char   sc = 3;

  uc = ui; /* { dg-warning "conversion" } */
  uc = si; /* { dg-warning "conversion" } */
  sc = ui; /* { dg-warning "conversion" } */
  sc = si; /* { dg-warning "conversion" } */
  fuc (ui); /* { dg-warning "conversion" } */
  fuc (si); /* { dg-warning "conversion" } */
  fsc (ui); /* { dg-warning "conversion" } */
  fsc (si); /* { dg-warning "conversion" } */

  fsi (si);
  fui (ui);
  fsi (uc);
  si = uc;
  fui (uc);
  ui = uc;
  fui ('A');
  ui = 'A';
  fsi ('A');
  si = 'A';
  fuc ('A');
  uc = 'A';

  uc = x ? 1U : -1; /* { dg-warning "conversion" } */
  uc = x ? SCHAR_MIN : 1U; /* { dg-warning "conversion" } */
  uc = x ? 1 : -1; /* Warned by -Wsign-conversion.  */
  uc = x ? SCHAR_MIN : 1; /* Warned by -Wsign-conversion.  */
  ui = x ? 1U : -1; /* Warned by -Wsign-conversion.  */
  ui = x ? INT_MIN : 1U; /* Warned by -Wsign-conversion.  */
  ui = ui ? SCHAR_MIN : 1U; /* Warned by -Wsign-conversion.  */
  ui = 1U * -1; /* Warned by -Wsign-conversion.  */
  ui = ui + INT_MIN; /* Warned by -Wsign-conversion.  */
  ui = x ? 1 : -1; /* Warned by -Wsign-conversion.  */
  ui = ui ? SCHAR_MIN : 1; /* Warned by -Wsign-conversion.  */

  fuc (-1); /* Warned by -Wsign-conversion.  */
  uc = -1; /* Warned by -Wsign-conversion.  */
  fui (-1); /* Warned by -Wsign-conversion.  */
  ui = -1; /* Warned by -Wsign-conversion.  */
  fuc ('\xa0'); /* Warned by -Wsign-conversion.  */
  uc = '\xa0'; /* Warned by -Wsign-conversion.  */
  fui ('\xa0'); /* Warned by -Wsign-conversion.  */
  ui = '\xa0';  /* Warned by -Wsign-conversion.  */
  fsi (0x80000000); /* Warned by -Wsign-conversion.  */
  si = 0x80000000;  /* Warned by -Wsign-conversion.  */


  fsi (UINT_MAX - 1);  /* Warned by -Wsign-conversion.  */
  si = UINT_MAX - 1;   /* Warned by -Wsign-conversion.  */
  fsi (UINT_MAX - 1U); /* Warned by -Wsign-conversion.  */
  si = UINT_MAX - 1U;  /* Warned by -Wsign-conversion.  */
  fsi (UINT_MAX/3U);
  si = UINT_MAX/3U;
  fsi (UINT_MAX/3);
  si = UINT_MAX/3;
  fui (UINT_MAX - 1);
  ui = UINT_MAX - 1;

  uc = (unsigned char) -1;
  ui = -1 * (1 * -1);
  ui = (unsigned) -1;

  fsc (uc); /* Warned by -Wsign-conversion.  */
  sc = uc;  /* Warned by -Wsign-conversion.  */
  fuc (sc); /* Warned by -Wsign-conversion.  */
  uc = sc;  /* Warned by -Wsign-conversion.  */
  fsi (ui); /* Warned by -Wsign-conversion.  */
  si = ui;  /* Warned by -Wsign-conversion.  */
  fui (si); /* Warned by -Wsign-conversion.  */ 
  ui = si;  /* Warned by -Wsign-conversion.  */ 
  fui (sc); /* Warned by -Wsign-conversion.  */
  ui = sc;  /* Warned by -Wsign-conversion.  */
}

unsigned fui (unsigned a) { return a + -1; } /* Warned by -Wsign-conversion.  */
