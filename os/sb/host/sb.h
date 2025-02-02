/*
    ChibiOS - Copyright (C) 2006,2007,2008,2009,2010,2011,2012,2013,2014,
              2015,2016,2017,2018,2019,2020,2021 Giovanni Di Sirio.

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation version 3 of the License.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    sb/host/sb.h
 * @brief   ARM SandBox macros and structures.
 *
 * @addtogroup ARM_SANDBOX
 * @{
 */

#ifndef SB_H
#define SB_H

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   ChibiOS/SB identification macro.
 */
#define __CHIBIOS_SB__

/**
 * @brief   Stable release flag.
 */
#define CH_SB_STABLE            0

/**
 * @name    ChibiOS/SE version identification
 * @{
 */
/**
 * @brief   Safety Extensions version string.
 */
#define CH_SB_VERSION           "3.0.0"

/**
 * @brief   Safety Extensions version major number.
 */
#define CH_SB_MAJOR             3

/**
 * @brief   Safety Extensions version minor number.
 */
#define CH_SB_MINOR             0

/**
 * @brief   Safety Extensions version patch number.
 */
#define CH_SB_PATCH             0
/** @} */

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

#include "sbconf.h"

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !defined(__CHIBIOS_SB_CONF__)
#error "missing or wrong configuration file"
#endif

#if !defined(__CHIBIOS_SB_CONF_VER_3_0__)
#error "obsolete or unknown configuration file"
#endif

/* Checks on configuration options.*/
#if !defined(SB_CFG_NUM_REGIONS) || defined(__DOXYGEN__)
#error "SB_CFG_NUM_REGIONS not defined in sbconf.h"
#endif

#if !defined(SB_CFG_ENABLE_VFS) || defined(__DOXYGEN__)
#error "SB_CFG_ENABLE_VFS not defined in sbconf.h"
#endif

#if !defined(SB_CFG_FD_NUM) || defined(__DOXYGEN__)
#error "SB_CFG_FD_NUM not defined in sbconf.h"
#endif

/* License checks.*/
#if !defined(CH_CUSTOMER_LIC_SB) || !defined(CH_LICENSE_FEATURES)
#error "malformed chlicense.h"
#endif

#if CH_CUSTOMER_LIC_SB == FALSE
#error "ChibiOS/SB not licensed"
#endif

#if (CH_LICENSE_FEATURES != CH_FEATURES_FULL) &&                            \
    (CH_LICENSE_FEATURES != CH_FEATURES_INTERMEDIATE) &&                    \
    (CH_LICENSE_FEATURES != CH_FEATURES_BASIC)
#error "invalid CH_LICENSE_FEATURES setting"
#endif

#if CH_LICENSE_FEATURES != CH_FEATURES_FULL
#error "ChibiOS/SB insufficient features level"
#endif

#if CH_CFG_ST_RESOLUTION != 32
#error "SandBox requires CH_CFG_ST_RESOLUTION == 32"
#endif

#if CH_CFG_INTERVALS_SIZE != 32
#error "SandBox requires CH_CFG_INTERVALS_SIZE == 32"
#endif

#if CH_CFG_USE_MEMCHECKS == FALSE
#error "SandBox requires CH_CFG_USE_MEMCHECKS == TRUE"
#endif

#if PORT_USE_SYSCALL == FALSE
#error "SandBox requires PORT_USE_SYSCALL == TRUE"
#endif

#if (SB_CFG_NUM_REGIONS < 1) || (SB_CFG_NUM_REGIONS > 4)
#error "invalid SB_CFG_NUM_REGIONS value"
#endif

#if (PORT_SWITCHED_REGIONS_NUMBER > 0) &&                                   \
    (PORT_SWITCHED_REGIONS_NUMBER != SB_CFG_NUM_REGIONS)
#error "SB_CFG_NUM_REGIONS not matching PORT_SWITCHED_REGIONS_NUMBER"
#endif

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

#include "hal.h"
#include "errcodes.h"

#include "sbsysc.h"
#include "sbposix.h"
#include "sbapi.h"
#include "sbhost.h"

#endif /* SBHOST_H */

/** @} */
