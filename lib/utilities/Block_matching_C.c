#include <mex.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*
 * File: rtwtypes.h
*/

#ifndef RTWTYPES_H
#define RTWTYPES_H
#ifndef __TMWTYPES__
#define __TMWTYPES__

typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef long long int64_T;
typedef unsigned long long uint64_T;
typedef float real32_T;
typedef double real64_T;

typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef unsigned long long ulonglong_T;
typedef char char_T;
typedef char_T byte_T;

/*===========================================================================*
 * Complex number type definitions                                           *
 *===========================================================================*/
#define CREAL_T

typedef struct {
  real32_T re;
  real32_T im;
} creal32_T;

typedef struct {
  real64_T re;
  real64_T im;
} creal64_T;

typedef struct {
  real_T re;
  real_T im;
} creal_T;

typedef struct {
  int8_T re;
  int8_T im;
} cint8_T;

typedef struct {
  uint8_T re;
  uint8_T im;
} cuint8_T;

typedef struct {
  int16_T re;
  int16_T im;
} cint16_T;

typedef struct {
  uint16_T re;
  uint16_T im;
} cuint16_T;

typedef struct {
  int32_T re;
  int32_T im;
} cint32_T;

typedef struct {
  uint32_T re;
  uint32_T im;
} cuint32_T;

typedef struct {
  int64_T re;
  int64_T im;
} cint64_T;

typedef struct {
  uint64_T re;
  uint64_T im;
} cuint64_T;

#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255))
#define MIN_uint8_T                    ((uint8_T)(0))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535))
#define MIN_uint16_T                   ((uint16_T)(0))
#define MAX_int32_T                    ((int32_T)(2147483647))
#define MIN_int32_T                    ((int32_T)(-2147483647-1))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))
#define MIN_uint32_T                   ((uint32_T)(0))
#define MAX_int64_T                    ((int64_T)(9223372036854775807LL))
#define MIN_int64_T                    ((int64_T)(-9223372036854775807LL-1LL))
#define MAX_uint64_T                   ((uint64_T)(0xFFFFFFFFFFFFFFFFULL))
#define MIN_uint64_T                   ((uint64_T)(0ULL))

/* Logical type definitions */
#if !defined(__cplusplus) && !defined(__true_false_are_keywords)
#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif
#endif

#define TMW_NAME_LENGTH_MAX            64
#endif
#endif

/*
 * File trailer for rtwtypes.h
 *
 * [EOF]
 */

#ifndef BLOCK_MATCHING_C_TYPES_H
#define BLOCK_MATCHING_C_TYPES_H

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  float *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T

typedef struct emxArray_real32_T emxArray_real32_T;

#endif                                 /*typedef_emxArray_real32_T*/
#endif

/*
 * File trailer for Block_matching_C_types.h
 *
 * [EOF]
 */

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/* Function: rt_InitInfAndNaN ==================================================
 * Abstract:
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */


/* Function: rtIsInf ==================================================
 * Abstract:
 * Test if value is infinite
 */
boolean_T rtIsInf(real_T value)
{
  return ((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Function: rtIsInfF =================================================
 * Abstract:
 * Test if single-precision value is infinite
 */
boolean_T rtIsInfF(real32_T value)
{
  return(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Function: rtIsNaN ==================================================
 * Abstract:
 * Test if value is not a number
 */
boolean_T rtIsNaN(real_T value)
{

#if defined(_MSC_VER) && (_MSC_VER <= 1200)

  return _isnan(value)? TRUE:FALSE;

#else

  return (value!=value)? 1U:0U;

#endif

}

/* Function: rtIsNaNF =================================================
 * Abstract:
 * Test if single-precision value is not a number
 */
boolean_T rtIsNaNF(real32_T value)
{

#if defined(_MSC_VER) && (_MSC_VER <= 1200)

  return _isnan((real_T)value)? true:false;

#else

  return (value!=value)? 1U:0U;

#endif

}

/*
 * File trailer for rt_nonfinite.c
 *
 * [EOF]
 */


#ifndef RT_NONFINITE_H
#define RT_NONFINITE_H
#if defined(_MSC_VER) && (_MSC_VER <= 1200)
#include <float.h>
#endif

#include <stddef.h>

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

#endif

/*
 * File trailer for rt_nonfinite.h
 *
 * [EOF]
 */



#define NumBitsPerChar                 8U



/* Function: rtGetInfF ==================================================
 * Abstract:
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/* Function: rtGetInf ==================================================
 * Abstract:
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    uint16_T one = 1U;
    enum {
      LittleEndian,
      BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
    switch (machByteOrder) {
     case LittleEndian:
      {
        union {
          LittleEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0x7FF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        inf = tmpVal.fltVal;
        break;
      }

     case BigEndian:
      {
        union {
          BigEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0x7FF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        inf = tmpVal.fltVal;
        break;
      }
    }
  }

  return inf;
}
/* Function: rtGetMinusInfF ==================================================
 * Abstract:
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/* Function: rtGetMinusInf ==================================================
 * Abstract:
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    uint16_T one = 1U;
    enum {
      LittleEndian,
      BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
    switch (machByteOrder) {
     case LittleEndian:
      {
        union {
          LittleEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0xFFF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        minf = tmpVal.fltVal;
        break;
      }

     case BigEndian:
      {
        union {
          BigEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0xFFF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        minf = tmpVal.fltVal;
        break;
      }
    }
  }

  return minf;
}


/*
 * File trailer for rtGetInf.c
 *
 * [EOF]
 */

/* Function: rtGetNaN ==================================================
 * Abstract:
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
/* Function: rtGetNaNF ==================================================
 * Abstract:
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  uint16_T one = 1U;
  enum {
    LittleEndian,
    BigEndian
  } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
  switch (machByteOrder) {
   case LittleEndian:
    {
      nanF.wordL.wordLuint = 0xFFC00000U;
      break;
    }

   case BigEndian:
    {
      nanF.wordL.wordLuint = 0x7FFFFFFFU;
      break;
    }
  }

  return nanF.wordL.wordLreal;
}


real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    uint16_T one = 1U;
    enum {
      LittleEndian,
      BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;
    switch (machByteOrder) {
     case LittleEndian:
      {
        union {
          LittleEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0xFFF80000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        nan = tmpVal.fltVal;
        break;
      }

     case BigEndian:
      {
        union {
          BigEndianIEEEDouble bitVal;
          real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0x7FFFFFFFU;
        tmpVal.bitVal.words.wordL = 0xFFFFFFFFU;
        nan = tmpVal.fltVal;
        break;
      }
    }
  }

  return nan;
}


/*
 * File trailer for rtGetNaN.c
 *
 * [EOF]
 */

void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, unsigned int
  elementSize)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, elementSize * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real32_T(emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (float *)NULL) && (*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions)
{
  emxArray_real32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
  emxArray = *pEmxArray;
  emxArray->data = (float *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real32_T1(emxArray_real32_T **pEmxArray, int numDimensions)
{
  emxArray_real32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
  emxArray = *pEmxArray;
  emxArray->data = (float *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * File trailer for Block_matching_C_emxutil.c
 *
 * [EOF]
 */

/* Function Declarations */
static void merge(emxArray_int32_T *idx, emxArray_real32_T *x, int offset, int
                  np, int nq, emxArray_int32_T *iwork, emxArray_real32_T *xwork);
static void merge_block(emxArray_int32_T *idx, emxArray_real32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real32_T *xwork);
static void merge_pow2_block(emxArray_int32_T *idx, emxArray_real32_T *x, int
  offset);

/* Function Definitions */

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real32_T *x
 *                int offset
 *                int np
 *                int nq
 *                emxArray_int32_T *iwork
 *                emxArray_real32_T *xwork
 * Return Type  : void
 */
static void merge(emxArray_int32_T *idx, emxArray_real32_T *x, int offset, int
                  np, int nq, emxArray_int32_T *iwork, emxArray_real32_T *xwork)
{
  int n;
  int qend;
  int p;
  int iout;
  int exitg1;
  if (nq != 0) {
    n = np + nq;
    for (qend = 0; qend + 1 <= n; qend++) {
      iwork->data[qend] = idx->data[offset + qend];
      xwork->data[qend] = x->data[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[n]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[n];
        x->data[iout] = xwork->data[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          while (p + 1 <= np) {
            idx->data[n + p] = iwork->data[p];
            x->data[n + p] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real32_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 *                emxArray_int32_T *iwork
 *                emxArray_real32_T *xwork
 * Return Type  : void
 */
static void merge_block(emxArray_int32_T *idx, emxArray_real32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real32_T *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      merge(idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real32_T *x
 *                int offset
 * Return Type  : void
 */
static void merge_pow2_block(emxArray_int32_T *idx, emxArray_real32_T *x, int
  offset)
{
  int b;
  int bLen;
  int bLen2;
  int nPairs;
  int k;
  int blockOffset;
  int q;
  int p;
  int iwork[256];
  float xwork[256];
  int exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 1; k <= nPairs; k++) {
      blockOffset = (offset + (k - 1) * bLen2) - 1;
      for (q = 1; q <= bLen2; q++) {
        iwork[q - 1] = idx->data[blockOffset + q];
        xwork[q - 1] = x->data[blockOffset + q];
      }

      p = 0;
      q = bLen;
      do {
        exitg1 = 0;
        blockOffset++;
        if (xwork[p] <= xwork[q]) {
          idx->data[blockOffset] = iwork[p];
          x->data[blockOffset] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx->data[blockOffset] = iwork[q];
          x->data[blockOffset] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            q = blockOffset - p;
            while (p + 1 <= bLen) {
              idx->data[(q + p) + 1] = iwork[p];
              x->data[(q + p) + 1] = xwork[p];
              p++;
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

/*
 * Arguments    : emxArray_real32_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void sortIdx(emxArray_real32_T *x, emxArray_int32_T *idx)
{
  int ib;
  int i;
  int n;
  int b_n;
  emxArray_int32_T *iwork;
  float x4[4];
  int idx4[4];
  emxArray_real32_T *xwork;
  int nNaNs;
  int k;
  int wOffset;
  signed char perm[4];
  int i3;
  int i4;
  ib = x->size[0];
  i = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity((emxArray__common *)idx, i, sizeof(int));
  for (i = 0; i < ib; i++) {
    idx->data[i] = 0;
  }

  n = x->size[0];
  b_n = x->size[0];
  for (i = 0; i < 4; i++) {
    x4[i] = 0.0F;
    idx4[i] = 0;
  }

  emxInit_int32_T1(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = ib;
  emxEnsureCapacity((emxArray__common *)iwork, i, sizeof(int));
  ib = iwork->size[0];
  i = iwork->size[0];
  iwork->size[0] = ib;
  emxEnsureCapacity((emxArray__common *)iwork, i, sizeof(int));
  for (i = 0; i < ib; i++) {
    iwork->data[i] = 0;
  }

  emxInit_real32_T1(&xwork, 1);
  ib = x->size[0];
  i = xwork->size[0];
  xwork->size[0] = ib;
  emxEnsureCapacity((emxArray__common *)xwork, i, sizeof(float));
  ib = xwork->size[0];
  i = xwork->size[0];
  xwork->size[0] = ib;
  emxEnsureCapacity((emxArray__common *)xwork, i, sizeof(float));
  for (i = 0; i < ib; i++) {
    xwork->data[i] = 0.0F;
  }

  nNaNs = 1;
  ib = 0;
  for (k = 0; k + 1 <= b_n; k++) {
    if (rtIsNaNF(x->data[k])) {
      idx->data[b_n - nNaNs] = k + 1;
      xwork->data[b_n - nNaNs] = x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = x->data[k];
      if (ib == 4) {
        i = k - nNaNs;
        if (x4[0] <= x4[1]) {
          ib = 1;
          wOffset = 2;
        } else {
          ib = 2;
          wOffset = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        if (x4[ib - 1] <= x4[i3 - 1]) {
          if (x4[wOffset - 1] <= x4[i3 - 1]) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)wOffset;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (x4[wOffset - 1] <= x4[i4 - 1]) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)wOffset;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)wOffset;
          }
        } else if (x4[ib - 1] <= x4[i4 - 1]) {
          if (x4[wOffset - 1] <= x4[i4 - 1]) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)wOffset;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)wOffset;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)ib;
          perm[3] = (signed char)wOffset;
        }

        idx->data[i - 2] = idx4[perm[0] - 1];
        idx->data[i - 1] = idx4[perm[1] - 1];
        idx->data[i] = idx4[perm[2] - 1];
        idx->data[i + 1] = idx4[perm[3] - 1];
        x->data[i - 2] = x4[perm[0] - 1];
        x->data[i - 1] = x4[perm[1] - 1];
        x->data[i] = x4[perm[2] - 1];
        x->data[i + 1] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = b_n - nNaNs;
  if (ib > 0) {
    for (i = 0; i < 4; i++) {
      perm[i] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 1; k <= ib; k++) {
      idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  i = (nNaNs - 1) >> 1;
  for (k = 1; k <= i; k++) {
    ib = idx->data[wOffset + k];
    idx->data[wOffset + k] = idx->data[b_n - k];
    idx->data[b_n - k] = ib;
    x->data[wOffset + k] = xwork->data[b_n - k];
    x->data[b_n - k] = xwork->data[wOffset + k];
  }

  if (((nNaNs - 1) & 1) != 0) {
    x->data[(wOffset + i) + 1] = xwork->data[(wOffset + i) + 1];
  }

  wOffset = (n - nNaNs) + 1;
  ib = 2;
  if (wOffset > 1) {
    if (n >= 256) {
      i = wOffset >> 8;
      if (i > 0) {
        for (ib = 1; ib <= i; ib++) {
          merge_pow2_block(idx, x, (ib - 1) << 8);
        }

        ib = i << 8;
        i = wOffset - ib;
        if (i > 0) {
          merge_block(idx, x, ib, i, 2, iwork, xwork);
        }

        ib = 8;
      }
    }

    merge_block(idx, x, 0, wOffset, ib, iwork, xwork);
  }

  emxFree_real32_T(&xwork);
  emxFree_int32_T(&iwork);
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */




void sort(emxArray_real32_T *x, emxArray_int32_T *idx)
{
  emxArray_real32_T *vwork;
  int i1;
  int x_idx_0;
  int i2;
  emxArray_int32_T *iidx;
  emxInit_real32_T1(&vwork, 1);
  i1 = x->size[1];
  x_idx_0 = x->size[1];
  i2 = vwork->size[0];
  vwork->size[0] = x_idx_0;
  emxEnsureCapacity((emxArray__common *)vwork, i2, sizeof(float));
  i2 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)idx, i2, sizeof(int));
  for (x_idx_0 = 0; x_idx_0 + 1 <= i1; x_idx_0++) {
    vwork->data[x_idx_0] = x->data[x_idx_0];
  }

  emxInit_int32_T1(&iidx, 1);
  sortIdx(vwork, iidx);
  for (x_idx_0 = 0; x_idx_0 + 1 <= i1; x_idx_0++) {
    x->data[x_idx_0] = vwork->data[x_idx_0];
    idx->data[x_idx_0] = iidx->data[x_idx_0];
  }

  emxFree_int32_T(&iidx);
  emxFree_real32_T(&vwork);
}

/*
 * File trailer for sort1.c
 *
 * [EOF]
 */






void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{   

    float *X;
    X =  (float *) mxGetPr(prhs[0]);
    double Patnum = mxGetScalar(prhs[1]);
    int *NeighborH;
    NeighborH = (int *) mxGetPr(prhs[2]);
    int *NeighborW;
    NeighborW = (int *) mxGetPr(prhs[3]);
    int *NumH;
    NumH = (int *) mxGetPr(prhs[4]);
    int *NumW;
    NumW = (int *) mxGetPr(prhs[5]);
    int *SelfH;
    SelfH = (int *) mxGetPr(prhs[6]);
    int *SelfW;
    SelfW = (int *) mxGetPr(prhs[7]);
    double R_GridH  = mxGetN(prhs[6]);
    double C_GridW = mxGetN(prhs[7]);

    plhs[0] = mxCreateDoubleMatrix(Patnum,(int)R_GridH*C_GridW,mxREAL);
    double *Init_Index;
    Init_Index = (double *) mxGetPr(plhs[0]);

    int M_NeighborH;
    M_NeighborH = mxGetM(prhs[2]);
    int M_NeighborW;
    M_NeighborW = mxGetM(prhs[3]);
    int Dim;
    Dim = mxGetM(prhs[0]);


    emxArray_int32_T *Neighbor_arr_temp;
    emxArray_real32_T *Dist;
    emxArray_int32_T *iidx;
    
    int i0;
    int loop_ub;
    int k;
    int j;
    int i;
    int xoffset;
    int offset_n;
    int offset_p;
    int ntilerows;
    int ii;
    int jj;
    int kk;

    int NumW_j;
    int NumH_i;
    double Offset2;
    double s;
    double t;
    double t_temp1;
    double t_temp2;
    double a_temp;
    int Neighbor_arr_temp_index;
  
  k = 0;
  emxInit_int32_T(&Neighbor_arr_temp, 2);
  emxInit_real32_T(&Dist, 2);
  emxInit_int32_T(&iidx, 2);
      
    for (j = 0; j < (int)C_GridW; j++){
        NumW_j = NumW[j];
        Offset2 = (double) j*R_GridH;
        for (i = 0; i < (int)R_GridH; i++) {
            NumH_i = NumH[i];
            ntilerows = NumW_j*NumH_i;
            i0 = Neighbor_arr_temp->size[0] * Neighbor_arr_temp->size[1];
            Neighbor_arr_temp->size[0] = 1;
            Neighbor_arr_temp->size[1] = ntilerows;
            emxEnsureCapacity((emxArray__common *)Neighbor_arr_temp, i0, sizeof(int));
      
            i0 = Dist->size[0] * Dist->size[1];
            Dist->size[0] = 1;
            Dist->size[1] = ntilerows;
            emxEnsureCapacity((emxArray__common *)Dist, i0, sizeof(float));
      
            offset_p = Dim * (SelfW[j] + SelfH[i] - 1);

                t_temp1 = 0;
                for (jj = 0; jj < NumW_j; jj++) {
                    t_temp2 = t_temp1 + NeighborW[jj + M_NeighborW * j ];
                    for (ii = 0; ii < NumH_i; ii++) {
                        t = t_temp2 + NeighborH[ii + M_NeighborH * i];
                        s = 0.0F;
                        offset_n = Dim * (t - 1);
                        for (xoffset = 0; xoffset < Dim; xoffset++) {
                            a_temp = X[xoffset + offset_p] - X[xoffset + offset_n];
                            s += a_temp*a_temp;
                        }
                        Dist->data[(kk*NumW_j+jj)*NumH_i+ii ] = s;
                        Neighbor_arr_temp->data[(kk*NumW_j+jj)*NumH_i+ii] = t;
                        
                    }
                }
            
            sort(Dist, iidx);
            i0 = (int)( Offset2 + (double)i);
            loop_ub = Patnum;
            for (xoffset = 0; xoffset < loop_ub; xoffset++) {
                Neighbor_arr_temp_index = iidx->data[xoffset] - 1;
                Init_Index[xoffset + (int)Patnum * i0] = Neighbor_arr_temp->data[Neighbor_arr_temp_index];
            }    
        }
    }


  emxFree_int32_T(&iidx);
  emxFree_real32_T(&Dist);
  emxFree_int32_T(&Neighbor_arr_temp);

}

/*
 * File trailer for Block_matching_C.c
 *
 * [EOF]
 */


