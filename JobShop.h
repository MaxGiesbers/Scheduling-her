#pragma once
#include <vector>
#include <iostream>
#include "Job.h"
#include "Machine.h"
#include <algorithm>
#include <functional>

class JobShop
{
private:
	std::string input;
	unsigned short currentTime;
	std::vector<Job> jobVector;
	std::vector<Machine> machineVector;

	void ParseJobsConfig();
	void ParseMachinesConfig();

public:
	JobShop(const std::string &mInput = "", unsigned short aCurrentTime = 0);
	virtual ~JobShop();

	void SortJobs();
	bool checkAvailableMachines(unsigned short machineNumber);
	void RunSchedulingAlgorithm();
	void SetCurrentTime(unsigned short aCurrentTime);
	bool AllJobsScheduled ()const ;

	//getters
	unsigned short GetCurrentTime() const;
	const std::vector<Job> GetJobVector() const;
	const std::vector<Machine> &GetMachineVector() const;

	//printing
	void PrintResults();
	void PrintAllConfigData();
};
