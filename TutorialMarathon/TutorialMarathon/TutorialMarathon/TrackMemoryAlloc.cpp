
#include "Print.h"

#pragma region AllocationTracker

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics allocationMetrics;

void* operator new(size_t size)
{
	allocationMetrics.TotalAllocated += size;

	return malloc(size);// put here a break point and just track allocations
}

void operator delete(void* memory, size_t size)
{
	allocationMetrics.TotalFreed += size;

	free(memory);// put here a break point and just track destructions
}

#pragma endregion

struct Object
{
	int x, y, z;
};

int MAIN36()
{
	prt::Print(allocationMetrics.CurrentUsage());

	Object* obj = new Object;

	prt::Print(allocationMetrics.CurrentUsage());

	delete obj;

	prt::Print(allocationMetrics.CurrentUsage());

	return 0;
}
