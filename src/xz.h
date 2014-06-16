/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  Plug-in Manager Plugin - XZ archive decompression
 * Author:   Pavel Kalian
 *
 * Based on code from 02_decompress.c liblzma example by Lasse Collin
 *
 ***************************************************************************
 *   Copyright (C) 2014 by Pavel Kalian                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */
 
#ifndef _XZ_H_
#define _XZ_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <lzma.h>

class Xz
{
public:
    Xz ( void );
    ~Xz ( void );
    bool Decompress(const wxString infile, const wxString outfile);
    
private:
    lzma_stream strm = LZMA_STREAM_INIT;
    
    bool init_decoder(lzma_stream *strm);
    bool decompress(lzma_stream *strm, const char *inname, FILE *infile, FILE *outfile);
};

#endif //_XZ_H_
