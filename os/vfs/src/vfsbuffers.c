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
 * @file    vfs/src/vfsbuffers.c
 * @brief   VFS shared path buffers code.
 *
 * @addtogroup VFS_BUFFERS
 * @{
 */

#include "vfs.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/**
 * @brief   VFS static data.
 */
static struct {
  /**
   * @brief   Guarded pool of path buffers.
   */
  guarded_memory_pool_t             path_buffers_pool;
  /**
   * @brief   Shared path buffers.
   */
  char                              path_buffers[VFS_CFG_PATHBUFS_NUM]
                                                [VFS_CFG_PATHLEN_MAX + 1];
} vfs_buffers_static;

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   VFS path buffers initialization.
 *
 * @init
 */
void __vfs_buffers_init(void) {

  chGuardedPoolObjectInit(&vfs_buffers_static.path_buffers_pool,
                          VFS_CFG_PATHLEN_MAX + 1);
  chGuardedPoolLoadArray(&vfs_buffers_static.path_buffers_pool,
                         &vfs_buffers_static.path_buffers[0],
                         VFS_CFG_PATHBUFS_NUM);
}

/**
 * @brief   Claims a path buffer, waiting if not available.
 *
 * @return                      Pointer to the taken buffer.
 */
char *vfs_buffer_take(void) {

  return (char *)chGuardedPoolAllocTimeout(&vfs_buffers_static.path_buffers_pool,
                                           TIME_INFINITE);
}

/**
 * @brief   Releases a path buffer.
 *
 * @param[in] buf               Buffer to be released.
 */
void vfs_buffer_release(char *buf) {

  chGuardedPoolFree(&vfs_buffers_static.path_buffers_pool, (void *)buf);
}

/** @} */
