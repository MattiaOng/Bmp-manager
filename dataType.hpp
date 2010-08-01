/**
 * \file dataType.hpp
 *
 *  Copyright (C) 2009-2010, Ongaro Mattia <moongaro at gmail.com>
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdint.h>

typedef struct BMPTYPE {
  unsigned char magic[2];
} bmpType;

typedef struct FILEHEADER
{
  uint32_t size;
  uint16_t res1;
  uint16_t res2;
  uint32_t offset;
} fileHeader;

typedef struct INFOHEADER
{
  uint32_t headerSz;
  uint32_t width;
  uint32_t height;
  uint16_t nplanes;
  uint16_t bitspp;
  uint32_t compressType;
  uint32_t bytesz;
  uint32_t hres;
  uint32_t vres;
  uint32_t ncolors;
  uint32_t nimpcolors;
} infoHeader;

typedef struct RGB
{
    bool color : 1;
} rgb;

typedef struct RGB4
{
    short unsigned int color : 4;
} rgb4;

typedef struct RGB8
{
    uint8_t color;
} rgb8;

typedef struct RGB16
{
    short unsigned int blue, green, red : 5;
} rgb16;

typedef struct RGB24
{
    uint8_t blue, green, red;
} rgb24;

typedef struct RGB32
{
    uint8_t blue, green, red, res;
} rgb32;

#endif

/* End of dataType.hpp */