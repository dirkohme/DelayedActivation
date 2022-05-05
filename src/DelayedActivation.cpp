/*
 The MIT License (MIT)

 Copyright (c) 2019-2022 Dirk Ohme

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*/

//---| definitions |----------------------------------------------------------
#undef TEST

//---| includes |-------------------------------------------------------------
#if defined(ESP8266)
#  include <pgmspace.h>
#else
#  include <avr/pgmspace.h>
#endif
#include <Arduino.h>
#include "DelayedActivation.h"

//----------------------------------------------------------------------------
// constructor
//----------------------------------------------------------------------------
DelayedActivation::DelayedActivation(const uint32_t dwThresholdTrigger /*= 1*/,
	                             const uint32_t dwThresholdReset   /*= 10*/)

{
	m_dwThresholdTriggerMax = dwThresholdTrigger + dwThresholdReset;
	m_dwThresholdTriggerMax = (m_dwThresholdTriggerMax >= dwThresholdTrigger)
	                        ? m_dwThresholdTriggerMax : dwThresholdTrigger;
	m_dwThresholdTrigger    = dwThresholdTrigger;
	m_dwThresholdReset      = dwThresholdReset;
	Clear();
}

//----------------------------------------------------------------------------
// trigger activation
//----------------------------------------------------------------------------
void DelayedActivation::TriggerActivation()
{
	if (m_dwCounterTrigger < m_dwThresholdTriggerMax)
	{
		m_dwCounterTrigger++;
	}
	
	m_dwCounterReset = 0;
}

//----------------------------------------------------------------------------
// trigger reset
//----------------------------------------------------------------------------
void DelayedActivation::TriggerReset()
{
	if (m_dwCounterReset < m_dwThresholdReset)
	{
		m_dwCounterReset++;
	}
	else
	{
		m_dwCounterReset = 0;
		
		if (m_dwCounterTrigger > 0)
		{
			m_dwCounterTrigger--;
		}
	}
}

//===| eof - end of file |====================================================
