#pragma once
#include <iostream>
#include <vector>
#include "Task.h"
#include <numeric>
#include <algorithm>

class Job
{
private:
	std::vector<Task> taskVector;
	unsigned short jobID;
	std::string input;
	unsigned short startTime;
	unsigned short endTime;

public:
	Job(unsigned short aJobID, const std::string &mInput);
	virtual ~Job();
	std::vector<Task> &GetTaskVector();
	unsigned short ReturnTotalTime();
	Job& operator=(const Job &b);
	bool AllTasksScheduled () const;
	unsigned short GetEndTime() const;
	unsigned short GetJobId() const;
	unsigned short GetStartTime() const;
};
