#pragma once
#include <string>
#include <vector>
#include <numeric>
#include "Task.h"
#include <algorithm>

class Job
{
private:
	std::vector<Task> taskVector;
	unsigned short jobID;
	std::string input;
	void ParseTaskConfig();
	unsigned short startTime;
	unsigned short endTime;

public:
	Job(unsigned short aJobID, const std::string &mInput);
	virtual ~Job();
	std::vector<Task> &GetTaskVector();
	unsigned short ReturnTotalTime() const;
	Job& operator=(const Job &b);
	bool AllTasksScheduled () const;
	unsigned short GetEndTime() const;
	unsigned short GetJobId() const;
	unsigned short GetStartTime() const;
	Task GetFirstUnscheduledTask();
	void SetJobEndTime(unsigned short anEndTime);
	void SetJobStartTime(unsigned short aStartTime);
	void SetTask(unsigned short taskId);
};
