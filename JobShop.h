#pragma once
#include <vector>
#include <iostream>
#include "Job.h"
#include "Machine.h"

class JobShop
{
private:
	unsigned short currentTime;
	std::string input;
	std::vector<Job> jobVector;
	std::vector<Machine> machineVector;
	void parseJobsConfig();
	void parseMachinesConfig();

public:
	JobShop(const std::string &mInput);
	virtual ~JobShop();
	void SortJobs();
	void checkAvailableMachines();
	unsigned short GetCurrentTime() const;
	void SetCurrentTime(unsigned short aCurrentTime);
	const std::vector<Job> GetJobVector() const;
	const std::vector<Machine> &GetMachineVector() const;
};
