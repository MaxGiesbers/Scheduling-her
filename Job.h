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
	bool jobScheduled;
	void ParseTaskConfig();

  public:
	Job(const std::string &mInput = "", unsigned short aJobID = 0, unsigned short aStartTime = 0, unsigned short aEndTime = 0, bool aJobScheduled = false);
	virtual ~Job();
	unsigned short GetTotalJobTime() const;
	bool AllTasksScheduled() const;
	Task GetFirstUnscheduledTask();
	void StartJob(unsigned short aStartTime);
	void ScheduleTask(unsigned short taskID, unsigned short anEndTime);
	std::vector<Task> &GetTaskVector();
	unsigned short GetEndTime() const;
	unsigned short GetJobID() const;
	unsigned short GetStartTime() const;
	bool GetJobScheduled() const;
};