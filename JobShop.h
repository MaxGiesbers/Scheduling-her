#pragma once
#include "Job.h"
#include "Machine.h"

#include <vector>
#include <algorithm>
#include <functional>

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
	bool checkAvailableMachines(unsigned short machineNumber);

	unsigned short GetCurrentTime() const;
	void SetCurrentTime(unsigned short currentTime);
	std::vector<Job> GetJobVector() const;
	const std::vector<Machine>& GetMachineVector() const;
};
