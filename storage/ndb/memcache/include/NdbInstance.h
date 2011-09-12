/*
 Copyright (c) 2011, Oracle and/or its affiliates. All rights
 reserved.
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; version 2 of
 the License.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 02110-1301  USA
 */
#ifndef NDBMEMCACHE_NDBINSTANCE_H
#define NDBMEMCACHE_NDBINSTANCE_H

#ifndef __cplusplus
#error "This file is for C++ only"
#endif

#include <pthread.h>
#include "NdbApi.hpp"

#include "ndbmemcache_config.h"
#include "KeyPrefix.h"
#include "QueryPlan.h"

struct workitem;

#define VPSZ sizeof(void *)
#define ISZ  sizeof(int)
#define TOTAL_SZ (ISZ + (4 * VPSZ))
#define PADDING (64 - TOTAL_SZ)


class NdbInstance {
public:
  /* Public Methods */
  NdbInstance(Ndb_cluster_connection *, int, int);
  ~NdbInstance();
  QueryPlan * getPlanForPrefix(const KeyPrefix *);

  /* Public Instance Variables */  
  Ndb *db;
  NdbInstance *next;
  workitem *wqitem;
  int sched_gen_number;
 
private:
  int nplans;
  QueryPlan **plans;  
  char cache_line_padding[PADDING];
};


#endif
