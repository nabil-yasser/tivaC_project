/******************************************************************************
 * @file    std_types.h
 *
 * @date    11 Feb 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 * @brief   Includes standard types definitions
 *
 *****************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include <stdbool.h>

/* ========================================================================= */
/* ================          GLOBAL CONSTANT MACROS         ================ */
/* ========================================================================= */

#define NULL ((void *)0)

/* ========================================================================= */
/* ================     GLOBAL DATA TYPES AND STRUCTURES    ================ */
/* ========================================================================= */

typedef unsigned char uint8;       // 0 .. 255
typedef unsigned short uint16;     // 0 .. 65,535
typedef unsigned long uint32;      // 0 .. 4,294,967,295
typedef unsigned long long uint64; // 0 .. 18,446,744,073,709,551,615

typedef signed char sint8; // -128 .. +127
typedef short sint16;      // -32,768 .. +32,767
typedef long sint32;       // -2,147,483,648 .. +2,147,483,647
typedef long long sint64;  /* -9,223,372,036,854,775,808 ..
                              +9,223,372,036,854,775,807 */

typedef float float32;
typedef double float64;

typedef enum
{
    E_OK,              ///< 0
    E_NOT_OK,          ///< 1
    E_WRONG_PARAMETERS ///< 2
} errState_et;

#endif /* STD_TYPES_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
