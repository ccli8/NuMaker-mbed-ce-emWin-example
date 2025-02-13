/*
 * fbutils.h
 *
 * Headers for utility routines for framebuffer interaction
 *
 * Copyright 2002 Russell King and Doug Lowder
 *
 * This file is placed under the GPL.  Please see the
 * file COPYING for details.
 *
 */

#ifndef _FBUTILS_H
#define _FBUTILS_H
#if 0
//#include <asm/types.h>

/* This constant, being ORed with the color index tells the library
 * to draw in exclusive-or mode (that is, drawing the same second time
 * in the same place will remove the element leaving the background intact).
 */
#define XORMODE 0x80000000

extern unsigned int xres, yres;

void setcolor(unsigned colidx, unsigned value);
void put_cross(int x, int y, unsigned colidx);
void put_string(int x, int y, char *s, unsigned colidx);
void put_string_center(int x, int y, char *s, unsigned colidx);
void pixel (int x, int y, unsigned colidx);
void line (int x1, int y1, int x2, int y2, unsigned colidx);
void rect (int x1, int y1, int x2, int y2, unsigned colidx);
void fillrect (int x1, int y1, int x2, int y2, unsigned colidx);
#endif
#endif /* _FBUTILS_H */
