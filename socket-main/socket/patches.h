//
//  patches.h
//  socket
//
//  Created by staturnz on 1/24/23.
//  Copyright © 2023 Staturnz. All rights reserved.
//

#ifndef patches_h
#define patches_h

#define TTB_SIZE            4096
#define L1_SECT_S_BIT       (1 << 16)
#define L1_SECT_PROTO       (1 << 1)        /* 0b10 */
#define L1_SECT_AP_URW      (1 << 10) | (1 << 11)
#define L1_SECT_APX         (1 << 15)
#define L1_SECT_DEFPROT     (L1_SECT_AP_URW | L1_SECT_APX)
#define L1_SECT_SORDER      (0)            /* 0b00, not cacheable, strongly ordered. */
#define L1_SECT_DEFCACHE    (L1_SECT_SORDER)
#define L1_PROTO_TTE(entry) (entry | L1_SECT_S_BIT | L1_SECT_DEFPROT | L1_SECT_DEFCACHE)
#define L1_PAGE_PROTO       (1 << 0)
#define L1_COARSE_PT        (0xFFFFFC00)
#define PT_SIZE             256
#define L2_PAGE_APX         (1 << 9)

#define CHUNK_SIZE 0x800
#define KERNEL_TEXT_BASEADDR (0x80001000)
#define _pfx(delta) 0xF000 | ((delta >> 12) & 0x7FF)
#define sfx_1k(delta) 0xB800 | ((delta >>  1) & 0x7FF);
#define sfx_2k(delta) 0xB000 | ((delta >>  1) & 0x7FF);
#define sfx_3k(delta) 0x9800 | ((delta >>  1) & 0x7FF);
#define sfx_4k(delta) 0x9000 | ((delta >>  1) & 0x7FF);
#define b_w_ret(pfx, sfx) (unsigned int)pfx | ((unsigned int)sfx << 16);

// dora2-ios
// https://raw.githubusercontent.com/dora2-iOS/p0insettia/main/iphoneos-arm/kernel_patches/shellcode.s
static unsigned char shc_bin[] = {
    0x00, 0xf0, 0x02, 0xb8, 0x00, 0xf0, 0x0f, 0xb8, 0xda, 0xf8, 0x00, 0x00,
    0x40, 0xf0, 0x80, 0x60, 0x40, 0xf0, 0x0f, 0x00, 0x20, 0xf4, 0x7c, 0x50,
    0xca, 0xf8, 0x00, 0x00, 0x00, 0x20, 0x06, 0xb0, 0xbd, 0xe8, 0x00, 0x0d,
    0xf0, 0xbd, 0x03, 0xb1, 0x00, 0xe0, 0xaf, 0xe0, 0xf0, 0xb5, 0x03, 0xaf,
    0x2d, 0xe9, 0x00, 0x0d, 0xf6, 0xb0, 0x6c, 0x46, 0x6f, 0xf3, 0x02, 0x04,
    0xa5, 0x46, 0xd7, 0xf8, 0x0c, 0x90, 0xd7, 0xf8, 0x08, 0xc0, 0xd7, 0xf8,
    0x2c, 0xe0, 0xbc, 0x6a, 0x7d, 0x6a, 0x3e, 0x6a, 0xd7, 0xf8, 0x1c, 0x80,
    0xd7, 0xf8, 0x18, 0xa0, 0xd7, 0xf8, 0x14, 0xb0, 0x1a, 0x90, 0x38, 0x69,
    0x19, 0x90, 0x1a, 0x98, 0x18, 0x90, 0x1d, 0xa8, 0x17, 0x90, 0x00, 0x20,
    0x16, 0x90, 0x18, 0x98, 0x75, 0x90, 0x74, 0x91, 0x73, 0x92, 0x72, 0x93,
    0xcd, 0xf8, 0xc4, 0x91, 0xcd, 0xf8, 0xc0, 0xc1, 0xcd, 0xf8, 0x54, 0xb0,
    0xcd, 0xf8, 0x50, 0x80, 0xcd, 0xf8, 0x4c, 0xa0, 0x12, 0x96, 0x11, 0x95,
    0xcd, 0xf8, 0x40, 0xe0, 0x0f, 0x94, 0x00, 0xf0, 0x6b, 0xf8, 0x1c, 0x90,
    0x00, 0x20, 0x1e, 0x90, 0x1d, 0x90, 0x20, 0x90, 0x4f, 0xf4, 0x60, 0x70,
    0x1f, 0x90, 0x16, 0x98, 0x21, 0x90, 0x72, 0x98, 0x1c, 0x9a, 0x17, 0x99,
    0x00, 0xf0, 0x63, 0xf8, 0x6f, 0x90, 0x6f, 0x98, 0x00, 0x28, 0x22, 0xd1,
    0x00, 0x20, 0x1b, 0x90, 0xbd, 0xf8, 0xc0, 0x00, 0x00, 0xf4, 0x00, 0x60,
    0x00, 0x28, 0x04, 0xd0, 0x01, 0x20, 0x2e, 0x99, 0x74, 0x9a, 0xd1, 0x60,
    0x1b, 0x90, 0xbd, 0xf8, 0xc0, 0x00, 0x00, 0xf4, 0x80, 0x60, 0x00, 0x28,
    0x04, 0xd0, 0x01, 0x20, 0x2f, 0x99, 0x74, 0x9a, 0xd1, 0x61, 0x1b, 0x90,
    0x1b, 0x98, 0x00, 0x28, 0x07, 0xd0, 0x73, 0x98, 0xd0, 0xf8, 0xbc, 0x00,
    0x40, 0xf4, 0x80, 0x70, 0x73, 0x99, 0xc1, 0xf8, 0xbc, 0x00, 0x75, 0x98,
    0x74, 0x99, 0x73, 0x9a, 0x72, 0x9b, 0xdd, 0xf8, 0xc0, 0x91, 0xdd, 0xf8,
    0xc4, 0xc1, 0xd7, 0xf8, 0x10, 0xe0, 0x7c, 0x69, 0xbd, 0x69, 0xfe, 0x69,
    0xd7, 0xf8, 0x20, 0x80, 0xd7, 0xf8, 0x24, 0xa0, 0xd7, 0xf8, 0x28, 0xb0,
    0x0e, 0x90, 0xf8, 0x6a, 0x0d, 0x90, 0x68, 0x46, 0x0c, 0x90, 0x0d, 0x98,
    0x0b, 0x91, 0x0c, 0x99, 0x48, 0x62, 0xc1, 0xf8, 0x20, 0xb0, 0xc1, 0xf8,
    0x1c, 0xa0, 0xc1, 0xf8, 0x18, 0x80, 0x4e, 0x61, 0x0d, 0x61, 0xcc, 0x60,
    0xc1, 0xf8, 0x08, 0xe0, 0xc1, 0xf8, 0x04, 0xc0, 0xc1, 0xf8, 0x00, 0x90,
    0x0e, 0x98, 0x0b, 0x99, 0x00, 0xf0, 0x14, 0xf8, 0xa7, 0xf1, 0x18, 0x04,
    0xa5, 0x46, 0xbd, 0xe8, 0x00, 0x0d, 0xf0, 0xbd, 0x40, 0xf2, 0x20, 0x00,
    0xc0, 0xf2, 0x00, 0x00, 0x78, 0x44, 0x00, 0x68, 0x00, 0x47, 0x40, 0xf2,
    0x16, 0x03, 0xc0, 0xf2, 0x00, 0x03, 0x7b, 0x44, 0x1b, 0x68, 0x18, 0x47,
    0x40, 0xf2, 0x0c, 0x09, 0xc0, 0xf2, 0x00, 0x09, 0xf9, 0x44, 0xd9, 0xf8,
    0x00, 0xc0, 0x60, 0x47, 0x41, 0x41, 0x41, 0x41, 0x42, 0x42, 0x42, 0x42,
    0x43, 0x43, 0x43, 0x43, 0x00, 0x20, 0x70, 0x47, 0x01, 0x20, 0x70, 0x47
};

extern uint32_t _allproc;
void apply_patches(void);
void patch_amfi(void);
void find_patches(uint32_t region, unsigned char *k_data, size_t ksize);

#endif /* patches_h */
