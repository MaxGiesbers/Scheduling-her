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
	std::string input;
	unsigned short jobID;
	unsigned short startTime;
	unsigned short endTime;

	void ParseTaskConfig();
public:
	Job(const std::string &mInput ="", unsigned short aJobID = 0 , unsigned short aStartTime = 0, unsigned short aEndTime =0 );
	virtual ~Job();
	Job& operator=(const Job &b);

	bool AllTasksScheduled () const;
	unsigned short ReturnTotalTime() const;

	//Getters
	unsigned short GetEndTime() const;
	unsigned short GetJobID() const;
	unsigned short GetStartTime() const;
	Task GetFirstUnscheduledTask();
	std::vector<Task> &GetTaskVector();

	//Setters
	void SetJobEndTime(unsigned short anEndTime);
	void SetJobStartTime(unsigned short aStartTime);
	void SetTask(unsigned short TaskID);
};
