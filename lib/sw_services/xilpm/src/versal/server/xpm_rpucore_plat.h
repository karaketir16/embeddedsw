/******************************************************************************
* Copyright (c) 2018 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/


#ifndef XPM_RPUCORE_PLAT_H_
#define XPM_RPUCORE_PLAT_H_

#include "xpm_core.h"

#ifdef __cplusplus
extern "C" {
#endif

#define XPM_PROC_RPU_HIVEC_ADDR		0xFFFC0000U
#define XPM_RPU_NCPUHALT_MASK		BIT(0)
#define XPM_RPU_VINITHI_MASK		BIT(2)
#define XPM_RPU_SLSPLIT_MASK		BIT(3)
#define XPM_RPU_TCM_COMB_MASK		BIT(6)
#define XPM_RPU_SLCLAMP_MASK		BIT(4)
#define XPM_RPU0_0_PWR_CTRL_MASK	BIT(4)
#define XPM_RPU0_1_PWR_CTRL_MASK	BIT(5)
#define XPM_RPU_0_CPUPWRDWNREQ_MASK  BIT(0)
#define XPM_RPU_1_CPUPWRDWNREQ_MASK  BIT(0)
#define XPM_RPU_CORE_HALT(ResumeCfg)		PmRmw32(ResumeCfg, XPM_RPU_NCPUHALT_MASK,\
						~XPM_RPU_NCPUHALT_MASK)
#define XPM_RPU_CORE_RUN(ResumeCfg)		PmRmw32(ResumeCfg, XPM_RPU_NCPUHALT_MASK,\
						XPM_RPU_NCPUHALT_MASK)
#define XPM_GET_CORE_ID(Rpu0, Rpu1, DeviceId)	((Rpu0) = PM_DEV_RPU0_0, \
						(Rpu1) = PM_DEV_RPU0_1)

typedef struct XPm_RpuCore XPm_RpuCore;
/************************** Function Prototypes ******************************/
void XPmRpuCore_AssignRegAddr(struct XPm_RpuCore *RpuCore, const u32 Id, const u32 *BaseAddress);
XStatus XPm_RpuRstComparators(const u32 DeviceId);
XStatus XPm_RpuTcmCombConfig(const u32 DeviceId, const u32 Config);
void XPm_PlatRpuSetOperMode(const struct XPm_RpuCore *RpuCore, const u32 Mode, u32 *Val);
XStatus XPm_PlatRpuBootAddrConfig(const struct XPm_RpuCore *RpuCore, const u32 BootAddr);
u32 XPm_PlatRpuGetOperMode(const struct XPm_RpuCore *RpuCore);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* XPM_RPUCORE_PLAT_H_ */
