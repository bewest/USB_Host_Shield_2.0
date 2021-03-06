/* Copyright (C) 2011 Circuits At Home, LTD. All rights reserved.

This software may be distributed and modified under the terms of the GNU
General Public License version 2 (GPL2) as published by the Free Software
Foundation and appearing in the file GPL2.TXT included in the packaging of
this file. Please note that GPL2 Section 2[b] requires that all works based
on this software must also be made publicly available under the terms of
the GPL2 ("Copyleft").

Contact information
-------------------

Circuits At Home, LTD
Web      :  http://www.circuitsathome.com
e-mail   :  support@circuitsathome.com
*/
#if !defined(__PRINTHEX_H__)
#define __PRINTHEX_H__

#include <WProgram.h>

template <class T> 
void PrintHex(T val)
{
    T    mask = (((T)1) << (((sizeof(T) << 1) - 1) << 2));
    
    while (mask > 1)
    {
		if (val < mask)
		  Serial.print("0");

		mask >>= 4;
    }
    Serial.print((T)val, HEX);
}

template <class T> 
void PrintHex2(Print *prn, T val)
{
    T    mask = (((T)1) << (((sizeof(T) << 1) - 1) << 2));
    
    while (mask > 1)
    {
		if (val < mask)
		  prn->print("0");

		mask >>= 4;
    }
    prn->print((T)val, HEX);
}

template <class T> 
void PrintBin(T val)
{
	for (T mask = (((T)1) << (sizeof(T) << 3)-1); mask; mask>>=1)
		if (val & mask)
			Serial.print("1");
		else
			Serial.print("0");
}

#endif // __PRINTHEX_H__