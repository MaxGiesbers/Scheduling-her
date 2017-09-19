#pragma once
#include <string>
#include <vector>
#include <numeric>
#include "Task.h"

class Job
{
private:
	std::vector<Task> taskVector;
	unsigned short jobID;
	std::string input;
	void ParseTaskConfig();

public:
	Job(unsigned short aJobID, const std::string &mInput);
	virtual ~Job();
	std::vector<Task> &GetTaskVector();
	unsigned short ReturnTotalTime();
	Job& operator=(const Job &b);
	unsigned short GetJobID() const;
};
