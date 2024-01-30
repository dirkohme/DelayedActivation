/*
 The MIT License (MIT)

 Copyright (c) 2019-2024 Dirk Ohme

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

#pragma once

// This class implements a delayed activation
class DelayedActivation {
public:
protected:
	volatile uint32_t	m_dwCounterTrigger;
	volatile uint32_t	m_dwCounterReset;
	volatile uint32_t	m_dwThresholdTrigger;
	volatile uint32_t	m_dwThresholdTriggerMax;
	volatile uint32_t	m_dwThresholdReset;

public:
	// constructor
	// @param dwThresholdTrigger threshold for activation
	// @param dwThresholdReset threshold for decrement and reset
	DelayedActivation(const uint32_t dwThresholdTrigger = 1,
	                  const uint32_t dwThresholdReset   = 10);

	// clear and reset all internal counters
	inline void Clear()
		{ m_dwCounterTrigger = m_dwCounterReset = 0; }
	
	// get internal activation counter
	// @return raw activation counter value
	inline uint32_t GetActivationCounter()
		{ return m_dwCounterTrigger; }

	// activation state
	// @return true if activation threshold is reached
	inline bool IsActivated()
		{ return (m_dwCounterTrigger >= m_dwThresholdTrigger); }

	// trigger activation
	void TriggerActivation();
	
	// trigger reset
	void TriggerReset();
};

//===| eof - end of file |====================================================
