/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2023 Min Yao <min.yao@airoha.com>
 * Copyright (C) 2024 Christian Marangi <ansuelsmth@gmail.com>
 */

#ifndef __AN8855_H
#define __AN8855_H

#include <linux/bitfield.h>

#define AN8855_NUM_PORTS		6
#define AN8855_CPU_PORT			5
#define AN8855_NUM_FDB_RECORDS		2048
#define AN8855_GPHY_SMI_ADDR_DEFAULT	1
#define AN8855_PORT_VID_DEFAULT		0

#define MTK_TAG_LEN			4
#define AN8855_MAX_MTU			(15360 - ETH_HLEN - ETH_FCS_LEN - MTK_TAG_LEN)

#define AN8855_L2_AGING_MS_CONSTANT	1024

#define AN8855_PHY_FLAGS_EN_CALIBRATION	BIT(0)

/*	AN8855_SCU			0x10000000 */
#define AN8855_RG_GPIO_LED_MODE		0x10000054
#define AN8855_RG_GPIO_LED_SEL(i)	(0x10000000 + (0x0058 + ((i) * 4)))
#define AN8855_RG_INTB_MODE		0x10000080
#define AN8855_RG_RGMII_TXCK_C		0x100001d0

#define AN8855_PKG_SEL			0x10000094
#define   AN8855_PAG_SEL_AN8855H	0x2

/* Register for hw trap status */
#define AN8855_HWTRAP			0x1000009c

#define AN8855_RG_GPIO_L_INV		0x10000010
#define AN8855_RG_GPIO_CTRL		0x1000a300
#define AN8855_RG_GPIO_DATA		0x1000a304
#define AN8855_RG_GPIO_OE		0x1000a314

#define AN8855_CREV			0x10005000
#define   AN8855_ID			0x8855

/* Register for system reset */
#define AN8855_RST_CTRL			0x100050c0
#define   AN8855_SYS_CTRL_SYS_RST	BIT(31)

#define AN8855_INT_MASK			0x100050f0
#define   AN8855_INT_SYS		BIT(15)

#define AN8855_RG_CLK_CPU_ICG		0x10005034
#define   AN8855_MCU_ENABLE		BIT(3)

#define AN8855_RG_TIMER_CTL		0x1000a100
#define   AN8855_WDOG_ENABLE		BIT(25)

#define AN8855_RG_GDMP_RAM		0x10010000

/* Registers to mac forward control for unknown frames */
#define AN8855_MFC			0x10200010
#define   AN8855_CPU_EN			BIT(15)
#define   AN8855_CPU_PORT_IDX		GENMASK(12, 8)

#define AN8855_PAC			0x10200024
#define   AN8855_TAG_PAE_MANG_FR	BIT(30)
#define   AN8855_TAG_PAE_BPDU_FR	BIT(28)
#define   AN8855_TAG_PAE_EG_TAG		GENMASK(27, 25)
#define   AN8855_TAG_PAE_LKY_VLAN	BIT(24)
#define   AN8855_TAG_PAE_PRI_HIGH	BIT(23)
#define   AN8855_TAG_PAE_MIR		GENMASK(20, 19)
#define   AN8855_TAG_PAE_PORT_FW	GENMASK(18, 16)
#define   AN8855_PAE_MANG_FR		BIT(14)
#define   AN8855_PAE_BPDU_FR		BIT(12)
#define   AN8855_PAE_EG_TAG		GENMASK(11, 9)
#define   AN8855_PAE_LKY_VLAN		BIT(8)
#define   AN8855_PAE_PRI_HIGH		BIT(7)
#define   AN8855_PAE_MIR		GENMASK(4, 3)
#define   AN8855_PAE_PORT_FW		GENMASK(2, 0)

#define AN8855_RGAC1			0x10200028
#define   AN8855_R02_MANG_FR		BIT(30)
#define   AN8855_R02_BPDU_FR		BIT(28)
#define   AN8855_R02_EG_TAG		GENMASK(27, 25)
#define   AN8855_R02_LKY_VLAN		BIT(24)
#define   AN8855_R02_PRI_HIGH		BIT(23)
#define   AN8855_R02_MIR		GENMASK(20, 19)
#define   AN8855_R02_PORT_FW		GENMASK(18, 16)
#define   AN8855_R01_MANG_FR		BIT(14)
#define   AN8855_R01_BPDU_FR		BIT(12)
#define   AN8855_R01_EG_TAG		GENMASK(11, 9)
#define   AN8855_R01_LKY_VLAN		BIT(8)
#define   AN8855_R01_PRI_HIGH		BIT(7)
#define   AN8855_R01_MIR		GENMASK(4, 3)
#define   AN8855_R01_PORT_FW		GENMASK(2, 0)

#define AN8855_RGAC2			0x1020002c
#define   AN8855_R0E_MANG_FR		BIT(30)
#define   AN8855_R0E_BPDU_FR		BIT(28)
#define   AN8855_R0E_EG_TAG		GENMASK(27, 25)
#define   AN8855_R0E_LKY_VLAN		BIT(24)
#define   AN8855_R0E_PRI_HIGH		BIT(23)
#define   AN8855_R0E_MIR		GENMASK(20, 19)
#define   AN8855_R0E_PORT_FW		GENMASK(18, 16)
#define   AN8855_R03_MANG_FR		BIT(14)
#define   AN8855_R03_BPDU_FR		BIT(12)
#define   AN8855_R03_EG_TAG		GENMASK(11, 9)
#define   AN8855_R03_LKY_VLAN		BIT(8)
#define   AN8855_R03_PRI_HIGH		BIT(7)
#define   AN8855_R03_MIR		GENMASK(4, 3)
#define   AN8855_R03_PORT_FW		GENMASK(2, 0)

#define AN8855_AAC			0x102000a0
#define   AN8855_MAC_AUTO_FLUSH		BIT(28)
/* Control Address Table Age time.
 * (AN8855_AGE_CNT + 1) * ( AN8855_AGE_UNIT + 1 ) * AN8855_L2_AGING_MS_CONSTANT
 */
#define   AN8855_AGE_CNT		GENMASK(20, 12)
/* Value in seconds. Value is always incremented of 1 */
#define   AN8855_AGE_UNIT		GENMASK(10, 0)

/* Registers for ARL Unknown Unicast Forward control */
#define AN8855_UNUF			0x102000b4

/* Registers for ARL Unknown Multicast Forward control */
#define AN8855_UNMF			0x102000b8

/* Registers for ARL Broadcast forward control */
#define AN8855_BCF			0x102000bc

/* Registers for port address age disable */
#define AN8855_AGDIS			0x102000c0

/* Registers for mirror port control */
#define AN8855_MIR			0x102000cc
#define   AN8855_MIRROR_EN		BIT(7)
#define   AN8855_MIRROR_PORT		GENMASK(4, 0)

/* Registers for BPDU and PAE frame control*/
#define AN8855_BPC			0x102000d0
#define   AN8855_BPDU_MANG_FR		BIT(14)
#define   AN8855_BPDU_BPDU_FR		BIT(12)
#define   AN8855_BPDU_EG_TAG		GENMASK(11, 9)
#define   AN8855_BPDU_LKY_VLAN		BIT(8)
#define   AN8855_BPDU_PRI_HIGH		BIT(7)
#define   AN8855_BPDU_MIR		GENMASK(4, 3)
#define   AN8855_BPDU_PORT_FW		GENMASK(2, 0)

/* Registers for IP Unknown Multicast Forward control */
#define AN8855_UNIPMF			0x102000dc

enum an8855_bpdu_port_fw {
	AN8855_BPDU_FOLLOW_MFC = 0,
	AN8855_BPDU_CPU_EXCLUDE = 4,
	AN8855_BPDU_CPU_INCLUDE = 5,
	AN8855_BPDU_CPU_ONLY = 6,
	AN8855_BPDU_DROP = 7,
};

/* Register for address table control */
#define AN8855_ATC			0x10200300
#define   AN8855_ATC_BUSY		BIT(31)
#define   AN8855_ATC_HASH		GENMASK(24, 16)
#define   AN8855_ATC_HIT		GENMASK(15, 12)
#define   AN8855_ATC_MAT_MASK		GENMASK(11, 7)
#define   AN8855_ATC_MAT(x)		FIELD_PREP(AN8855_ATC_MAT_MASK, x)
#define   AN8855_ATC_SAT		GENMASK(5, 4)
#define   AN8855_ATC_CMD		GENMASK(2, 0)

enum an8855_fdb_mat_cmds {
	AND8855_FDB_MAT_ALL = 0,
	AND8855_FDB_MAT_MAC, /* All MAC address */
	AND8855_FDB_MAT_DYNAMIC_MAC, /* All Dynamic MAC address */
	AND8855_FDB_MAT_STATIC_MAC, /* All Static Mac Address */
	AND8855_FDB_MAT_DIP, /* All DIP/GA address */
	AND8855_FDB_MAT_DIP_IPV4, /* All DIP/GA IPv4 address */
	AND8855_FDB_MAT_DIP_IPV6, /* All DIP/GA IPv6 address */
	AND8855_FDB_MAT_DIP_SIP, /* All DIP_SIP address */
	AND8855_FDB_MAT_DIP_SIP_IPV4, /* All DIP_SIP IPv4 address */
	AND8855_FDB_MAT_DIP_SIP_IPV6, /* All DIP_SIP IPv6 address */
	AND8855_FDB_MAT_MAC_CVID, /* All MAC address with CVID */
	AND8855_FDB_MAT_MAC_FID, /* All MAC address with Filter ID */
	AND8855_FDB_MAT_MAC_PORT, /* All MAC address with port */
	AND8855_FDB_MAT_DIP_SIP_DIP_IPV4, /* All DIP_SIP address with DIP_IPV4 */
	AND8855_FDB_MAT_DIP_SIP_SIP_IPV4, /* All DIP_SIP address with SIP_IPV4 */
	AND8855_FDB_MAT_DIP_SIP_DIP_IPV6, /* All DIP_SIP address with DIP_IPV6 */
	AND8855_FDB_MAT_DIP_SIP_SIP_IPV6, /* All DIP_SIP address with SIP_IPV6 */
	/* All MAC address with MAC type (dynamic or static) with CVID */
	AND8855_FDB_MAT_MAC_TYPE_CVID,
	/* All MAC address with MAC type (dynamic or static) with Filter ID */
	AND8855_FDB_MAT_MAC_TYPE_FID,
	/* All MAC address with MAC type (dynamic or static) with port */
	AND8855_FDB_MAT_MAC_TYPE_PORT,
};

enum an8855_fdb_cmds {
	AN8855_FDB_READ = 0,
	AN8855_FDB_WRITE = 1,
	AN8855_FDB_FLUSH = 2,
	AN8855_FDB_START = 4,
	AN8855_FDB_NEXT = 5,
};

/* Registers for address table access */
#define AN8855_ATA1			0x10200304
#define   AN8855_ATA1_MAC0		GENMASK(31, 24)
#define   AN8855_ATA1_MAC1		GENMASK(23, 16)
#define   AN8855_ATA1_MAC2		GENMASK(15, 8)
#define   AN8855_ATA1_MAC3		GENMASK(7, 0)
#define AN8855_ATA2			0x10200308
#define   AN8855_ATA2_MAC4		GENMASK(31, 24)
#define   AN8855_ATA2_MAC5		GENMASK(23, 16)
#define   AN8855_ATA2_UNAUTH		BIT(10)
#define   AN8855_ATA2_TYPE		BIT(9) /* 1: dynamic, 0: static */
#define   AN8855_ATA2_AGE		GENMASK(8, 0)

/* Register for address table write data */
#define AN8855_ATWD			0x10200324
#define   AN8855_ATWD_FID		GENMASK(31, 28)
#define   AN8855_ATWD_VID		GENMASK(27, 16)
#define   AN8855_ATWD_IVL		BIT(15)
#define   AN8855_ATWD_EG_TAG		GENMASK(14, 12)
#define   AN8855_ATWD_SA_MIR		GENMASK(9, 8)
#define   AN8855_ATWD_SA_FWD		GENMASK(7, 5)
#define   AN8855_ATWD_UPRI		GENMASK(4, 2)
#define   AN8855_ATWD_LEAKY		BIT(1)
#define   AN8855_ATWD_VLD		BIT(0) /* vid LOAD */
#define AN8855_ATWD2			0x10200328
#define   AN8855_ATWD2_PORT		GENMASK(7, 0)

/* Registers for table search read address */
#define AN8855_ATRDS			0x10200330
#define   AN8855_ATRD_SEL		GENMASK(1, 0)
#define AN8855_ATRD0			0x10200334
#define   AN8855_ATRD0_FID		GENMASK(28, 25)
#define   AN8855_ATRD0_VID		GENMASK(21, 10)
#define   AN8855_ATRD0_IVL		BIT(9)
#define   AN8855_ATRD0_TYPE		GENMASK(4, 3)
#define   AN8855_ATRD0_ARP		GENMASK(2, 1)
#define   AN8855_ATRD0_LIVE		BIT(0)
#define AN8855_ATRD1			0x10200338
#define   AN8855_ATRD1_MAC4		GENMASK(31, 24)
#define   AN8855_ATRD1_MAC5		GENMASK(23, 16)
#define   AN8855_ATRD1_AGING		GENMASK(11, 3)
#define AN8855_ATRD2			0x1020033c
#define   AN8855_ATRD2_MAC0		GENMASK(31, 24)
#define   AN8855_ATRD2_MAC1		GENMASK(23, 16)
#define   AN8855_ATRD2_MAC2		GENMASK(15, 8)
#define   AN8855_ATRD2_MAC3		GENMASK(7, 0)
#define AN8855_ATRD3			0x10200340
#define   AN8855_ATRD3_PORTMASK		GENMASK(7, 0)

enum an8855_fdb_type {
	AN8855_MAC_TB_TY_MAC = 0,
	AN8855_MAC_TB_TY_DIP = 1,
	AN8855_MAC_TB_TY_DIP_SIP = 2,
};

/* Register for vlan table control */
#define AN8855_VTCR			0x10200600
#define   AN8855_VTCR_BUSY		BIT(31)
#define   AN8855_VTCR_FUNC		GENMASK(15, 12)
#define   AN8855_VTCR_VID		GENMASK(11, 0)

enum an8855_vlan_cmd {
	/* Read/Write the specified VID entry from VAWD register based
	 * on VID.
	 */
	AN8855_VTCR_RD_VID = 0,
	AN8855_VTCR_WR_VID = 1,
};

/* Register for setup vlan write data */
#define AN8855_VAWD0			0x10200604
/* VLAN Member Control */
#define   AN8855_VA0_PORT		GENMASK(31, 26)
/* Egress Tag Control */
#define   AN8855_VA0_ETAG		GENMASK(23, 12)
#define   AN8855_VA0_ETAG_PORT		GENMASK(13, 12)
#define   AN8855_VA0_ETAG_PORT_SHIFT(port) ((port) * 2)
#define   AN8855_VA0_ETAG_PORT_MASK(port) (AN8855_VA0_ETAG_PORT << \
						AN8855_VA0_ETAG_PORT_SHIFT(port))
#define   AN8855_VA0_ETAG_PORT_VAL(port, val) (FIELD_PREP(AN8855_VA0_ETAG_PORT, (val)) << \
						AN8855_VA0_ETAG_PORT_SHIFT(port))
#define   AN8855_VA0_EG_CON		BIT(11)
#define   AN8855_VA0_VTAG_EN		BIT(10) /* Per VLAN Egress Tag Control */
#define   AN8855_VA0_IVL_MAC		BIT(5) /* Independent VLAN Learning */
#define	  AN8855_VA0_FID		GENMASK(4, 1)
#define   AN8855_VA0_VLAN_VALID		BIT(0) /* VLAN Entry Valid */
#define AN8855_VAWD1			0x10200608
#define   AN8855_VA1_PORT_STAG		BIT(1)

enum an8855_fid {
	AN8855_FID_STANDALONE = 0,
	AN8855_FID_BRIDGED = 1,
};

/* Same register field of VAWD0 */
#define AN8855_VARD0			0x10200618

enum an8855_vlan_egress_attr {
	AN8855_VLAN_EGRESS_UNTAG = 0,
	AN8855_VLAN_EGRESS_TAG = 2,
	AN8855_VLAN_EGRESS_STACK = 3,
};

/* Register for port STP state control */
#define AN8855_SSP_P(x)			(0x10208000 + ((x) * 0x200))
/* Up to 16 FID supported, each with the same mask */
#define	  AN8855_FID_PST		GENMASK(1, 0)
#define   AN8855_FID_PST_SHIFT(fid)	(2 * (fid))
#define   AN8855_FID_PST_MASK(fid)	(AN8855_FID_PST << \
						AN8855_FID_PST_SHIFT(fid))
#define   AN8855_FID_PST_VAL(fid, val)	(FIELD_PREP(AN8855_FID_PST, (val)) << \
						AN8855_FID_PST_SHIFT(fid))

enum an8855_stp_state {
	AN8855_STP_DISABLED = 0,
	AN8855_STP_BLOCKING = 1,
	AN8855_STP_LISTENING = AN8855_STP_BLOCKING,
	AN8855_STP_LEARNING = 2,
	AN8855_STP_FORWARDING = 3
};

/* Register for port control */
#define AN8855_PCR_P(x)			(0x10208004 + ((x) * 0x200))
#define   AN8855_EG_TAG			GENMASK(29, 28)
#define   AN8855_PORT_PRI		GENMASK(26, 24)
#define   AN8855_PORT_TX_MIR		BIT(20)
#define   AN8855_PORT_RX_MIR		BIT(16)
#define   AN8855_PORT_VLAN		GENMASK(1, 0)

enum an8855_port_mode {
	/* Port Matrix Mode: Frames are forwarded by the PCR_MATRIX members. */
	AN8855_PORT_MATRIX_MODE = 0,

	/* Fallback Mode: Forward received frames with ingress ports that do
	 * not belong to the VLAN member. Frames whose VID is not listed on
	 * the VLAN table are forwarded by the PCR_MATRIX members.
	 */
	AN8855_PORT_FALLBACK_MODE = 1,

	/* Check Mode: Forward received frames whose ingress do not
	 * belong to the VLAN member. Discard frames if VID ismiddes on the
	 * VLAN table.
	 */
	AN8855_PORT_CHECK_MODE = 2,

	/* Security Mode: Discard any frame due to ingress membership
	 * violation or VID missed on the VLAN table.
	 */
	AN8855_PORT_SECURITY_MODE = 3,
};

/* Register for port security control */
#define AN8855_PSC_P(x)			(0x1020800c + ((x) * 0x200))
#define   AN8855_SA_DIS			BIT(4)

/* Register for port vlan control */
#define AN8855_PVC_P(x)			(0x10208010 + ((x) * 0x200))
#define   AN8855_PORT_SPEC_REPLACE_MODE	BIT(11)
#define   AN8855_PVC_EG_TAG		GENMASK(10, 8)
#define   AN8855_VLAN_ATTR		GENMASK(7, 6)
#define   AN8855_PORT_SPEC_TAG		BIT(5)
#define   AN8855_ACC_FRM		GENMASK(1, 0)

enum an8855_vlan_port_eg_tag {
	AN8855_VLAN_EG_DISABLED = 0,
	AN8855_VLAN_EG_CONSISTENT = 1,
	AN8855_VLAN_EG_UNTAGGED = 4,
	AN8855_VLAN_EG_SWAP = 5,
	AN8855_VLAN_EG_TAGGED = 6,
	AN8855_VLAN_EG_STACK = 7,
};

enum an8855_vlan_port_attr {
	AN8855_VLAN_USER = 0,
	AN8855_VLAN_STACK = 1,
	AN8855_VLAN_TRANSPARENT = 3,
};

enum an8855_vlan_port_acc_frm {
	AN8855_VLAN_ACC_ALL = 0,
	AN8855_VLAN_ACC_TAGGED = 1,
	AN8855_VLAN_ACC_UNTAGGED = 2,
};

#define AN8855_PPBV1_P(x)		(0x10208014 + ((x) * 0x200))
#define   AN8855_PPBV_G0_PORT_VID	GENMASK(11, 0)

#define AN8855_PORTMATRIX_P(x)		(0x10208044 + ((x) * 0x200))
#define   AN8855_PORTMATRIX		GENMASK(5, 0)
/* Port matrix without the CPU port that should never be removed */
#define   AN8855_USER_PORTMATRIX	GENMASK(4, 0)

/* Register for port PVID */
#define AN8855_PVID_P(x)		(0x10208048 + ((x) * 0x200))
#define   AN8855_G0_PORT_VID		GENMASK(11, 0)

/* Register for port MAC control register */
#define AN8855_PMCR_P(x)		(0x10210000 + ((x) * 0x200))
#define   AN8855_PMCR_FORCE_MODE	BIT(31)
#define   AN8855_PMCR_FORCE_SPEED	GENMASK(30, 28)
#define   AN8855_PMCR_FORCE_SPEED_5000	FIELD_PREP_CONST(AN8855_PMCR_FORCE_SPEED, 0x4)
#define   AN8855_PMCR_FORCE_SPEED_2500	FIELD_PREP_CONST(AN8855_PMCR_FORCE_SPEED, 0x3)
#define   AN8855_PMCR_FORCE_SPEED_1000	FIELD_PREP_CONST(AN8855_PMCR_FORCE_SPEED, 0x2)
#define   AN8855_PMCR_FORCE_SPEED_100	FIELD_PREP_CONST(AN8855_PMCR_FORCE_SPEED, 0x1)
#define   AN8855_PMCR_FORCE_SPEED_10	FIELD_PREP_CONST(AN8855_PMCR_FORCE_SPEED, 0x1)
#define   AN8855_PMCR_FORCE_FDX		BIT(25)
#define   AN8855_PMCR_FORCE_LNK		BIT(24)
#define   AN8855_PMCR_IFG_XMIT		GENMASK(21, 20)
#define   AN8855_PMCR_EXT_PHY		BIT(19)
#define   AN8855_PMCR_MAC_MODE		BIT(18)
#define   AN8855_PMCR_TX_EN		BIT(16)
#define   AN8855_PMCR_RX_EN		BIT(15)
#define   AN8855_PMCR_BACKOFF_EN	BIT(12)
#define   AN8855_PMCR_BACKPR_EN		BIT(11)
#define   AN8855_PMCR_FORCE_EEE5G	BIT(9)
#define   AN8855_PMCR_FORCE_EEE2P5G	BIT(8)
#define   AN8855_PMCR_FORCE_EEE1G	BIT(7)
#define   AN8855_PMCR_FORCE_EEE100	BIT(6)
#define   AN8855_PMCR_TX_FC_EN		BIT(5)
#define   AN8855_PMCR_RX_FC_EN		BIT(4)

#define AN8855_PMSR_P(x)		(0x10210010 + (x) * 0x200)
#define   AN8855_PMSR_SPEED		GENMASK(30, 28)
#define   AN8855_PMSR_SPEED_5000	FIELD_PREP_CONST(AN8855_PMSR_SPEED, 0x4)
#define   AN8855_PMSR_SPEED_2500	FIELD_PREP_CONST(AN8855_PMSR_SPEED, 0x3)
#define   AN8855_PMSR_SPEED_1000	FIELD_PREP_CONST(AN8855_PMSR_SPEED, 0x2)
#define   AN8855_PMSR_SPEED_100		FIELD_PREP_CONST(AN8855_PMSR_SPEED, 0x1)
#define   AN8855_PMSR_SPEED_10		FIELD_PREP_CONST(AN8855_PMSR_SPEED, 0x0)
#define   AN8855_PMSR_DPX		BIT(25)
#define   AN8855_PMSR_LNK		BIT(24)
#define   AN8855_PMSR_EEE1G		BIT(7)
#define   AN8855_PMSR_EEE100M		BIT(6)
#define   AN8855_PMSR_RX_FC		BIT(5)
#define   AN8855_PMSR_TX_FC		BIT(4)

#define AN8855_PMEEECR_P(x)		(0x10210004 + (x) * 0x200)
#define   AN8855_LPI_MODE_EN		BIT(31)
#define   AN8855_WAKEUP_TIME_2500	GENMASK(23, 16)
#define   AN8855_WAKEUP_TIME_1000	GENMASK(15, 8)
#define   AN8855_WAKEUP_TIME_100	GENMASK(7, 0)
#define AN8855_PMEEECR2_P(x)		(0x10210008 + (x) * 0x200)
#define   AN8855_WAKEUP_TIME_5000	GENMASK(7, 0)

#define AN8855_GMACCR			0x10213e00
#define   AN8855_MAX_RX_JUMBO		GENMASK(7, 4)
/* 2K for 0x0, 0x1, 0x2 */
#define   AN8855_MAX_RX_JUMBO_2K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x0)
#define   AN8855_MAX_RX_JUMBO_3K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x3)
#define   AN8855_MAX_RX_JUMBO_4K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x4)
#define   AN8855_MAX_RX_JUMBO_5K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x5)
#define   AN8855_MAX_RX_JUMBO_6K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x6)
#define   AN8855_MAX_RX_JUMBO_7K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x7)
#define   AN8855_MAX_RX_JUMBO_8K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x8)
#define   AN8855_MAX_RX_JUMBO_9K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0x9)
#define   AN8855_MAX_RX_JUMBO_12K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0xa)
#define   AN8855_MAX_RX_JUMBO_15K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0xb)
#define   AN8855_MAX_RX_JUMBO_16K	FIELD_PREP_CONST(AN8855_MAX_RX_JUMBO, 0xc)
#define   AN8855_MAX_RX_PKT_LEN		GENMASK(1, 0)
#define   AN8855_MAX_RX_PKT_1518_1522	FIELD_PREP_CONST(AN8855_MAX_RX_PKT_LEN, 0x0)
#define   AN8855_MAX_RX_PKT_1536	FIELD_PREP_CONST(AN8855_MAX_RX_PKT_LEN, 0x1)
#define   AN8855_MAX_RX_PKT_1552	FIELD_PREP_CONST(AN8855_MAX_RX_PKT_LEN, 0x2)
#define   AN8855_MAX_RX_PKT_JUMBO	FIELD_PREP_CONST(AN8855_MAX_RX_PKT_LEN, 0x3)

#define AN8855_CKGCR			0x10213e1c
#define   AN8855_LPI_TXIDLE_THD_MASK	GENMASK(31, 14)
#define   AN8855_CKG_LNKDN_PORT_STOP	BIT(1)
#define   AN8855_CKG_LNKDN_GLB_STOP	BIT(0)

/* Register for MIB */
#define AN8855_PORT_MIB_COUNTER(x)	(0x10214000 + (x) * 0x200)
/* Each define is an offset of AN8855_PORT_MIB_COUNTER */
#define   AN8855_PORT_MIB_TX_DROP	0x00
#define   AN8855_PORT_MIB_TX_CRC_ERR	0x04
#define   AN8855_PORT_MIB_TX_UNICAST	0x08
#define   AN8855_PORT_MIB_TX_MULTICAST	0x0c
#define   AN8855_PORT_MIB_TX_BROADCAST	0x10
#define   AN8855_PORT_MIB_TX_COLLISION	0x14
#define   AN8855_PORT_MIB_TX_SINGLE_COLLISION 0x18
#define   AN8855_PORT_MIB_TX_MULTIPLE_COLLISION 0x1c
#define   AN8855_PORT_MIB_TX_DEFERRED	0x20
#define   AN8855_PORT_MIB_TX_LATE_COLLISION 0x24
#define   AN8855_PORT_MIB_TX_EXCESSIVE_COLLISION 0x28
#define   AN8855_PORT_MIB_TX_PAUSE	0x2c
#define   AN8855_PORT_MIB_TX_PKT_SZ_64	0x30
#define   AN8855_PORT_MIB_TX_PKT_SZ_65_TO_127 0x34
#define   AN8855_PORT_MIB_TX_PKT_SZ_128_TO_255 0x38
#define   AN8855_PORT_MIB_TX_PKT_SZ_256_TO_511 0x3
#define   AN8855_PORT_MIB_TX_PKT_SZ_512_TO_1023 0x40
#define   AN8855_PORT_MIB_TX_PKT_SZ_1024_TO_1518 0x44
#define   AN8855_PORT_MIB_TX_PKT_SZ_1519_TO_MAX 0x48
#define   AN8855_PORT_MIB_TX_BYTES	0x4c /* 64 bytes */
#define   AN8855_PORT_MIB_TX_OVERSIZE_DROP 0x54
#define   AN8855_PORT_MIB_TX_BAD_PKT_BYTES 0x58 /* 64 bytes */
#define   AN8855_PORT_MIB_RX_DROP	0x80
#define   AN8855_PORT_MIB_RX_FILTERING	0x84
#define   AN8855_PORT_MIB_RX_UNICAST	0x88
#define   AN8855_PORT_MIB_RX_MULTICAST	0x8c
#define   AN8855_PORT_MIB_RX_BROADCAST	0x90
#define   AN8855_PORT_MIB_RX_ALIGN_ERR	0x94
#define   AN8855_PORT_MIB_RX_CRC_ERR	0x98
#define   AN8855_PORT_MIB_RX_UNDER_SIZE_ERR 0x9c
#define   AN8855_PORT_MIB_RX_FRAG_ERR	0xa0
#define   AN8855_PORT_MIB_RX_OVER_SZ_ERR 0xa4
#define   AN8855_PORT_MIB_RX_JABBER_ERR	0xa8
#define   AN8855_PORT_MIB_RX_PAUSE	0xac
#define   AN8855_PORT_MIB_RX_PKT_SZ_64	0xb0
#define   AN8855_PORT_MIB_RX_PKT_SZ_65_TO_127 0xb4
#define   AN8855_PORT_MIB_RX_PKT_SZ_128_TO_255 0xb8
#define   AN8855_PORT_MIB_RX_PKT_SZ_256_TO_511 0xbc
#define   AN8855_PORT_MIB_RX_PKT_SZ_512_TO_1023 0xc0
#define   AN8855_PORT_MIB_RX_PKT_SZ_1024_TO_1518 0xc4
#define   AN8855_PORT_MIB_RX_PKT_SZ_1519_TO_MAX 0xc8
#define   AN8855_PORT_MIB_RX_BYTES	0xcc /* 64 bytes */
#define   AN8855_PORT_MIB_RX_CTRL_DROP	0xd4
#define   AN8855_PORT_MIB_RX_INGRESS_DROP 0xd8
#define   AN8855_PORT_MIB_RX_ARL_DROP	0xdc
#define   AN8855_PORT_MIB_FLOW_CONTROL_DROP 0xe0
#define   AN8855_PORT_MIB_WRED_DROP	0xe4
#define   AN8855_PORT_MIB_MIRROR_DROP	0xe8
#define   AN8855_PORT_MIB_RX_BAD_PKT_BYTES 0xec /* 64 bytes */
#define   AN8855_PORT_MIB_RXS_FLOW_SAMPLING_PKT_DROP 0xf4
#define   AN8855_PORT_MIB_RXS_FLOW_TOTAL_PKT_DROP 0xf8
#define   AN8855_PORT_MIB_PORT_CONTROL_DROP 0xfc
#define AN8855_MIB_CCR			0x10213e30
#define   AN8855_CCR_MIB_ENABLE		BIT(31)
#define   AN8855_CCR_RX_OCT_CNT_GOOD	BIT(7)
#define   AN8855_CCR_RX_OCT_CNT_BAD	BIT(6)
#define   AN8855_CCR_TX_OCT_CNT_GOOD	BIT(5)
#define   AN8855_CCR_TX_OCT_CNT_BAD	BIT(4)
#define   AN8855_CCR_RX_OCT_CNT_GOOD_2	BIT(3)
#define   AN8855_CCR_RX_OCT_CNT_BAD_2	BIT(2)
#define   AN8855_CCR_TX_OCT_CNT_GOOD_2	BIT(1)
#define   AN8855_CCR_TX_OCT_CNT_BAD_2	BIT(0)
#define   AN8855_CCR_MIB_ACTIVATE	(AN8855_CCR_MIB_ENABLE | \
					 AN8855_CCR_RX_OCT_CNT_GOOD | \
					 AN8855_CCR_RX_OCT_CNT_BAD | \
					 AN8855_CCR_TX_OCT_CNT_GOOD | \
					 AN8855_CCR_TX_OCT_CNT_BAD | \
					 AN8855_CCR_RX_OCT_CNT_BAD_2 | \
					 AN8855_CCR_TX_OCT_CNT_BAD_2)
#define AN8855_MIB_CLR			0x10213e34
#define   AN8855_MIB_PORT6_CLR		BIT(6)
#define   AN8855_MIB_PORT5_CLR		BIT(5)
#define   AN8855_MIB_PORT4_CLR		BIT(4)
#define   AN8855_MIB_PORT3_CLR		BIT(3)
#define   AN8855_MIB_PORT2_CLR		BIT(2)
#define   AN8855_MIB_PORT1_CLR		BIT(1)
#define   AN8855_MIB_PORT0_CLR		BIT(0)

/* HSGMII/SGMII Configuration register */
/*	AN8855_HSGMII_AN_CSR_BASE	0x10220000 */
#define AN8855_SGMII_REG_AN0		0x10220000
/*        AN8855_SGMII_AN_ENABLE	BMCR_ANENABLE */
/*        AN8855_SGMII_AN_RESTART	BMCR_ANRESTART */
#define AN8855_SGMII_REG_AN_13		0x10220034
#define   AN8855_SGMII_REMOTE_FAULT_DIS	BIT(8)
#define   AN8855_SGMII_IF_MODE		GENMASK(5, 0)
#define AN8855_SGMII_REG_AN_FORCE_CL37	0x10220060
#define   AN8855_RG_FORCE_AN_DONE	BIT(0)

/*	AN8855_HSGMII_CSR_PCS_BASE	0x10220000 */
#define AN8855_RG_HSGMII_PCS_CTROL_1	0x10220a00
#define   AN8855_RG_TBI_10B_MODE	BIT(30)
#define AN8855_RG_AN_SGMII_MODE_FORCE	0x10220a24
#define   AN8855_RG_FORCE_CUR_SGMII_MODE GENMASK(5, 4)
#define   AN8855_RG_FORCE_CUR_SGMII_SEL	BIT(0)

/*	AN8855_MULTI_SGMII_CSR_BASE	0x10224000 */
#define AN8855_SGMII_STS_CTRL_0		0x10224018
#define   AN8855_RG_LINK_MODE_P0	GENMASK(5, 4)
#define   AN8855_RG_LINK_MODE_P0_SPEED_2500 FIELD_PREP_CONST(AN8855_RG_LINK_MODE_P0, 0x3)
#define   AN8855_RG_LINK_MODE_P0_SPEED_1000 FIELD_PREP_CONST(AN8855_RG_LINK_MODE_P0, 0x2)
#define   AN8855_RG_LINK_MODE_P0_SPEED_100 FIELD_PREP_CONST(AN8855_RG_LINK_MODE_P0, 0x1)
#define   AN8855_RG_LINK_MODE_P0_SPEED_10 FIELD_PREP_CONST(AN8855_RG_LINK_MODE_P0, 0x0)
#define   AN8855_RG_FORCE_SPD_MODE_P0	BIT(2)
#define AN8855_MSG_RX_CTRL_0		0x10224100
#define AN8855_MSG_RX_LIK_STS_0		0x10224514
#define   AN8855_RG_DPX_STS_P3		BIT(24)
#define   AN8855_RG_DPX_STS_P2		BIT(16)
#define   AN8855_RG_EEE1G_STS_P1	BIT(12)
#define   AN8855_RG_DPX_STS_P1		BIT(8)
#define   AN8855_RG_TXFC_STS_P0		BIT(2)
#define   AN8855_RG_RXFC_STS_P0		BIT(1)
#define   AN8855_RG_DPX_STS_P0		BIT(0)
#define AN8855_MSG_RX_LIK_STS_2		0x1022451c
#define   AN8855_RG_RXFC_AN_BYPASS_P3	BIT(11)
#define   AN8855_RG_RXFC_AN_BYPASS_P2	BIT(10)
#define   AN8855_RG_RXFC_AN_BYPASS_P1	BIT(9)
#define   AN8855_RG_TXFC_AN_BYPASS_P3	BIT(7)
#define   AN8855_RG_TXFC_AN_BYPASS_P2	BIT(6)
#define   AN8855_RG_TXFC_AN_BYPASS_P1	BIT(5)
#define   AN8855_RG_DPX_AN_BYPASS_P3	BIT(3)
#define   AN8855_RG_DPX_AN_BYPASS_P2	BIT(2)
#define   AN8855_RG_DPX_AN_BYPASS_P1	BIT(1)
#define   AN8855_RG_DPX_AN_BYPASS_P0	BIT(0)
#define AN8855_PHY_RX_FORCE_CTRL_0	0x10224520
#define   AN8855_RG_FORCE_TXC_SEL	BIT(4)

/*	AN8855_XFI_CSR_PCS_BASE		0x10225000 */
#define AN8855_RG_USXGMII_AN_CONTROL_0	0x10225bf8

/*	AN8855_MULTI_PHY_RA_CSR_BASE	0x10226000 */
#define AN8855_RG_RATE_ADAPT_CTRL_0	0x10226000
#define   AN8855_RG_RATE_ADAPT_RX_BYPASS BIT(27)
#define   AN8855_RG_RATE_ADAPT_TX_BYPASS BIT(26)
#define   AN8855_RG_RATE_ADAPT_RX_EN	BIT(4)
#define   AN8855_RG_RATE_ADAPT_TX_EN	BIT(0)
#define AN8855_RATE_ADP_P0_CTRL_0	0x10226100
#define   AN8855_RG_P0_DIS_MII_MODE	BIT(31)
#define   AN8855_RG_P0_MII_MODE		BIT(28)
#define   AN8855_RG_P0_MII_RA_RX_EN	BIT(3)
#define   AN8855_RG_P0_MII_RA_TX_EN	BIT(2)
#define   AN8855_RG_P0_MII_RA_RX_MODE	BIT(1)
#define   AN8855_RG_P0_MII_RA_TX_MODE	BIT(0)
#define AN8855_MII_RA_AN_ENABLE		0x10226300
#define   AN8855_RG_P0_RA_AN_EN		BIT(0)

/*	AN8855_QP_DIG_CSR_BASE		0x1022a000 */
#define AN8855_QP_CK_RST_CTRL_4		0x1022a310
#define AN8855_QP_DIG_MODE_CTRL_0	0x1022a324
#define   AN8855_RG_SGMII_MODE		GENMASK(5, 4)
#define   AN8855_RG_SGMII_AN_EN		BIT(0)
#define AN8855_QP_DIG_MODE_CTRL_1	0x1022a330
#define   AN8855_RG_TPHY_SPEED		GENMASK(3, 2)

/*	AN8855_SERDES_WRAPPER_BASE	0x1022c000 */
#define AN8855_USGMII_CTRL_0		0x1022c000

/*	AN8855_QP_PMA_TOP_BASE		0x1022e000 */
#define AN8855_PON_RXFEDIG_CTRL_0	0x1022e100
#define   AN8855_RG_QP_EQ_RX500M_CK_SEL	BIT(12)
#define AN8855_PON_RXFEDIG_CTRL_9	0x1022e124
#define   AN8855_RG_QP_EQ_LEQOSC_DLYCNT	GENMASK(2, 0)

#define AN8855_SS_LCPLL_PWCTL_SETTING_2	0x1022e208
#define   AN8855_RG_NCPO_ANA_MSB	GENMASK(17, 16)
#define AN8855_SS_LCPLL_TDC_FLT_2	0x1022e230
#define   AN8855_RG_LCPLL_NCPO_VALUE	GENMASK(30, 0)
#define AN8855_SS_LCPLL_TDC_FLT_5	0x1022e23c
#define   AN8855_RG_LCPLL_NCPO_CHG	BIT(24)
#define AN8855_SS_LCPLL_TDC_PCW_1	0x1022e248
#define  AN8855_RG_LCPLL_PON_HRDDS_PCW_NCPO_GPON GENMASK(30, 0)
#define AN8855_INTF_CTRL_8		0x1022e320
#define AN8855_INTF_CTRL_9		0x1022e324
#define AN8855_INTF_CTRL_10		0x1022e328
#define   AN8855_RG_DA_QP_TX_FIR_C2_SEL	BIT(29)
#define   AN8855_RG_DA_QP_TX_FIR_C2_FORCE GENMASK(28, 24)
#define   AN8855_RG_DA_QP_TX_FIR_C1_SEL	BIT(21)
#define   AN8855_RG_DA_QP_TX_FIR_C1_FORCE GENMASK(20, 16)
#define AN8855_INTF_CTRL_11		0x1022e32c
#define   AN8855_RG_DA_QP_TX_FIR_C0B_SEL BIT(6)
#define   AN8855_RG_DA_QP_TX_FIR_C0B_FORCE GENMASK(5, 0)
#define AN8855_PLL_CTRL_0		0x1022e400
#define   AN8855_RG_PHYA_AUTO_INIT	BIT(0)
#define AN8855_PLL_CTRL_2		0x1022e408
#define   AN8855_RG_DA_QP_PLL_SDM_IFM_INTF BIT(30)
#define   AN8855_RG_DA_QP_PLL_RICO_SEL_INTF BIT(29)
#define   AN8855_RG_DA_QP_PLL_POSTDIV_EN_INTF BIT(28)
#define   AN8855_RG_DA_QP_PLL_PHY_CK_EN_INTF BIT(27)
#define   AN8855_RG_DA_QP_PLL_PFD_OFFSET_EN_INTRF BIT(26)
#define   AN8855_RG_DA_QP_PLL_PFD_OFFSET_INTF GENMASK(25, 24)
#define   AN8855_RG_DA_QP_PLL_PCK_SEL_INTF BIT(22)
#define   AN8855_RG_DA_QP_PLL_KBAND_PREDIV_INTF GENMASK(21, 20)
#define   AN8855_RG_DA_QP_PLL_IR_INTF	GENMASK(19, 16)
#define   AN8855_RG_DA_QP_PLL_ICOIQ_EN_INTF BIT(14)
#define   AN8855_RG_DA_QP_PLL_FBKSEL_INTF GENMASK(13, 12)
#define   AN8855_RG_DA_QP_PLL_BR_INTF	GENMASK(10, 8)
#define   AN8855_RG_DA_QP_PLL_BPD_INTF	GENMASK(7, 6)
#define   AN8855_RG_DA_QP_PLL_BPA_INTF	GENMASK(4, 2)
#define   AN8855_RG_DA_QP_PLL_BC_INTF	GENMASK(1, 0)
#define AN8855_PLL_CTRL_3		0x1022e40c
#define   AN8855_RG_DA_QP_PLL_SSC_PERIOD_INTF GENMASK(31, 16)
#define   AN8855_RG_DA_QP_PLL_SSC_DELTA_INTF GENMASK(15, 0)
#define AN8855_PLL_CTRL_4		0x1022e410
#define   AN8855_RG_DA_QP_PLL_SDM_HREN_INTF GENMASK(4, 3)
#define   AN8855_RG_DA_QP_PLL_ICOLP_EN_INTF BIT(2)
#define   AN8855_RG_DA_QP_PLL_SSC_DIR_DLY_INTF GENMASK(1, 0)
#define AN8855_PLL_CK_CTRL_0		0x1022e414
#define   AN8855_RG_DA_QP_PLL_TDC_TXCK_SEL_INTF BIT(9)
#define   AN8855_RG_DA_QP_PLL_SDM_DI_EN_INTF BIT(8)
#define AN8855_RX_DLY_0			0x1022e614
#define   AN8855_RG_QP_RX_SAOSC_EN_H_DLY GENMASK(13, 8)
#define   AN8855_RG_QP_RX_PI_CAL_EN_H_DLY GENMASK(7, 0)
#define AN8855_RX_CTRL_2		0x1022e630
#define   AN8855_RG_QP_RX_EQ_EN_H_DLY	GENMASK(28, 16)
#define AN8855_RX_CTRL_5		0x1022e63c
#define   AN8855_RG_FREDET_CHK_CYCLE	GENMASK(29, 10)
#define AN8855_RX_CTRL_6		0x1022e640
#define   AN8855_RG_FREDET_GOLDEN_CYCLE	GENMASK(19, 0)
#define AN8855_RX_CTRL_7		0x1022e644
#define   AN8855_RG_FREDET_TOLERATE_CYCLE GENMASK(19, 0)
#define AN8855_RX_CTRL_8		0x1022e648
#define   AN8855_RG_DA_QP_SAOSC_DONE_TIME GENMASK(27, 16)
#define   AN8855_RG_DA_QP_LEQOS_EN_TIME	GENMASK(14, 0)
#define AN8855_RX_CTRL_26		0x1022e690
#define   AN8855_RG_QP_EQ_RETRAIN_ONLY_EN BIT(26)
#define   AN8855_RG_LINK_NE_EN		BIT(24)
#define   AN8855_RG_LINK_ERRO_EN	BIT(23)
#define AN8855_RX_CTRL_42		0x1022e6d0
#define   AN8855_RG_QP_EQ_EN_DLY	GENMASK(12, 0)

/*	AN8855_QP_ANA_CSR_BASE		0x1022f000 */
#define AN8855_RG_QP_RX_DAC_EN		0x1022f000
#define   AN8855_RG_QP_SIGDET_HF	GENMASK(17, 16)
#define AN8855_RG_QP_RXAFE_RESERVE	0x1022f004
#define   AN8855_RG_QP_CDR_PD_10B_EN	BIT(11)
#define AN8855_RG_QP_CDR_LPF_BOT_LIM	0x1022f008
#define   AN8855_RG_QP_CDR_LPF_KP_GAIN	GENMASK(26, 24)
#define   AN8855_RG_QP_CDR_LPF_KI_GAIN	GENMASK(22, 20)
#define AN8855_RG_QP_CDR_LPF_MJV_LIM	0x1022f00c
#define   AN8855_RG_QP_CDR_LPF_RATIO	GENMASK(5, 4)
#define AN8855_RG_QP_CDR_LPF_SETVALUE	0x1022f014
#define   AN8855_RG_QP_CDR_PR_BUF_IN_SR	GENMASK(31, 29)
#define   AN8855_RG_QP_CDR_PR_BETA_SEL	GENMASK(28, 25)
#define AN8855_RG_QP_CDR_PR_CKREF_DIV1	0x1022f018
#define   AN8855_RG_QP_CDR_PR_KBAND_DIV	GENMASK(26, 24)
#define   AN8855_RG_QP_CDR_PR_DAC_BAND	GENMASK(12, 8)
#define AN8855_RG_QP_CDR_PR_KBAND_DIV_PCIE 0x1022f01c
#define   AN8855_RG_QP_CDR_PR_XFICK_EN	BIT(30)
#define   AN8855_RG_QP_CDR_PR_KBAND_PCIE_MODE BIT(6)
#define   AN8855_RG_QP_CDR_PR_KBAND_DIV_PCIE_MASK GENMASK(5, 0)
#define AN8855_RG_QP_CDR_FORCE_IBANDLPF_R_OFF 0x1022f020
#define   AN8855_RG_QP_CDR_PHYCK_SEL	GENMASK(17, 16)
#define   AN8855_RG_QP_CDR_PHYCK_RSTB	BIT(13)
#define   AN8855_RG_QP_CDR_PHYCK_DIV	GENMASK(12, 6)
#define AN8855_RG_QP_TX_MODE		0x1022f028
#define   AN8855_RG_QP_TX_RESERVE	GENMASK(31, 16)
#define   AN8855_RG_QP_TX_MODE_16B_EN	BIT(0)
#define AN8855_RG_QP_PLL_IPLL_DIG_PWR_SEL 0x1022f03c
#define AN8855_RG_QP_PLL_SDM_ORD	0x1022f040
#define   AN8855_RG_QP_PLL_SSC_PHASE_INI BIT(4)
#define   AN8855_RG_QP_PLL_SSC_TRI_EN	BIT(3)

/*	AN8855_ETHER_SYS_BASE		0x1028c800 */
#define AN8855_RG_GPHY_AFE_PWD		0x1028c840
#define AN8855_RG_GPHY_SMI_ADDR		0x1028c848

#define MIB_DESC(_s, _o, _n)	\
	{			\
		.size = (_s),	\
		.offset = (_o),	\
		.name = (_n),	\
	}

struct an8855_mib_desc {
	unsigned int size;
	unsigned int offset;
	const char *name;
};

struct an8855_fdb {
	u16 vid;
	u8 port_mask;
	u16 aging;
	u8 mac[6];
	bool noarp;
	u8 live;
	u8 type;
	u8 fid;
	u8 ivl;
};

struct an8855_priv {
	struct device *dev;
	struct dsa_switch *ds;
	struct regmap *regmap;
	struct gpio_desc *reset_gpio;
	/* Protect ATU or VLAN table access */
	struct mutex reg_mutex;

	struct phylink_pcs pcs;

	u8 mirror_rx;
	u8 mirror_tx;
	u8 port_isolated_map;

	bool phy_require_calib;
};

#endif /* __AN8855_H */
