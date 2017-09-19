#pragma once
#include <vector>
#include "Job.h"
#include "Machine.h"

class JobShop
{

private:
	unsigned short currentTime;

	std::vector<Job> jobVector;
	std::vector<Machine> machineVector;
public:
	JobShop(unsigned short aCurrentTime);
	virtual ~JobShop();

	void SortJobs();
	void checkAvailableMachines();

	unsigned short GetCurrentTime() const;
	void SetCurrentTime(unsigned short currentTime);
	std::vector<Job> GetJobVector() const;
	const std::vector<Machine>& GetMachineVector() const;
};
