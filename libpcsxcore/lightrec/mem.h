/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2022 Paul Cercueil <paul@crapouillou.net>
 */

#ifndef __LIGHTREC_MEM_H__
#define __LIGHTREC_MEM_H__

#ifdef LIGHTREC

#ifdef HW_WUP /* WiiU */
/* The JIT code lives in the OS codegen area (OSGetCodegenVirtAddrRange,
 * 32 MiB on Aroma), not in the legacy 0x00800000 HBL area: under Aroma
 * that one is shared with the function patcher trampolines and the
 * loader, and overwriting it crashed hooked calls and app switches. */
#    define CODE_BUFFER_SIZE_DFT	(8 * 1024 * 1024)
#else
#    define CODE_BUFFER_SIZE_DFT	(8 * 1024 * 1024)
#endif

#ifndef CODE_BUFFER_SIZE
#define CODE_BUFFER_SIZE CODE_BUFFER_SIZE_DFT
#endif

extern void *code_buffer;

int lightrec_init_mmap(void);
void lightrec_free_mmap(void);

#else /* if !LIGHTREC */

#define lightrec_init_mmap() -1 /* should not be called */
#define lightrec_free_mmap()

#undef LIGHTREC_CUSTOM_MAP
#define LIGHTREC_CUSTOM_MAP 0

#endif

#endif /* __LIGHTREC_MEM_H__ */
