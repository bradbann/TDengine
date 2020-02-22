/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TBASE_MNODE_TABLE_H
#define TBASE_MNODE_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mnode.h"

int32_t     mgmtInitTables();
STableInfo* mgmtGetTable(char *tableId);
STableInfo* mgmtGetTableByPos(uint32_t dnodeIp, int32_t vnode, int32_t sid);

int32_t  mgmtRetrieveMetricMeta(SConnObj *pConn, char **pStart, SSuperTableMetaMsg *pInfo);
int32_t  mgmtCreateTable(SDbObj *pDb, SCreateTableMsg *pCreate);
int32_t  mgmtDropTable(SDbObj *pDb, char *meterId, int32_t ignore);
int32_t  mgmtAlterTable(SDbObj *pDb, SAlterTableMsg *pAlter);
int32_t  mgmtGetTableMeta(SMeterMeta *pMeta, SShowObj *pShow, SConnObj *pConn);
int32_t  mgmtRetrieveTables(SShowObj *pShow, char *data, int32_t rows, SConnObj *pConn);
void     mgmtCleanUpMeters();

void    mgmtAddTableIntoSuperTable(SSuperTableObj *pStable);
void    mgmtRemoveTableFromSuperTable(SSuperTableObj *pStable);
int32_t mgmtGetSuperTableMeta(SMeterMeta *pMeta, SShowObj *pShow, SConnObj *pConn);
int32_t mgmtRetrieveSuperTables(SShowObj *pShow, char *data, int32_t rows, SConnObj *pConn);



#ifdef __cplusplus
}
#endif

#endif