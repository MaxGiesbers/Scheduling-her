#pragma once
#include <iostream>
#include <vector>
#include "Task.h"
#include <numeric>

class Job
{
private:
	std::vector<Task> taskVector;
	unsigned short jobID;
	std::string input;

public:
	Job(unsigned short aJobID, const std::string &mInput);
	virtual ~Job();
	std::vector<Task> &GetTaskVector();
	unsigned short ReturnTotalTime();
	Job& operator=(const Job &b);
};
