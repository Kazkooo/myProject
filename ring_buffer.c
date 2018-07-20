/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "ring_buffer.h"




bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize) 
{
	assert(ringBuffer);
	assert(dataBuffer);
	assert(dataBufferSize > 0);
	
	if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {
	  ringBuffer->dataBuffer = dataBuffer;
		ringBuffer->dataBufferSize = dataBufferSize;
		ringBuffer->head = ringBuffer->tail= 0;
		ringBuffer->cnt = 0;
		return true;
	}
	
	return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	
	if (ringBuffer) { 	
			ringBuffer->cnt = 0;
			ringBuffer->head = ringBuffer->tail= 0;	
		return true;
	}
	return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
  assert(ringBuffer);	
	if(ringBuffer)
	{ 
		return ringBuffer->cnt == 0;
	}
	return false;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		
		return ringBuffer->cnt;
	}
	return 0;
	
}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);
	
	if (ringBuffer) {
		return ringBuffer->dataBufferSize;
	}
	return 0;	
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
	assert(ringBuffer);
	
	if ((ringBuffer) && (RingBuffer_GetLen(ringBuffer) < RingBuffer_GetCapacity(ringBuffer))) {
	    
	    	ringBuffer->dataBuffer[ringBuffer->head] = c;
			ringBuffer->head ++;
			ringBuffer->cnt += 1; 
		
		if (ringBuffer->head > ringBuffer->dataBufferSize)
				ringBuffer->head = 0; 
		return true;
	}
	return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
	assert(ringBuffer);
	assert(c);
	
  if ((ringBuffer) && (c) && ringBuffer->cnt > 0) {
       
		*c = ringBuffer->dataBuffer[(ringBuffer->tail)];
		 ringBuffer->tail ++;
		ringBuffer->cnt --; 	
	if (ringBuffer->tail > ringBuffer->dataBufferSize) 
		ringBuffer->tail = 0; 
		
		return true;
	}
	return false;
}
	