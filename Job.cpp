#include <regex>
#include "Job.h"

Job::Job(const std::string &anInput, const unsigned short aJobID, unsigned short aStartTime, unsigned short aEndTime, bool aJobScheduled) 
: input(anInput), jobID(aJobID), startTime(aStartTime), endTime(aEndTime), jobScheduled(aJobScheduled)
{
	ParseTaskConfig();
}

Job::~Job()
{
}

unsigned short Job::GetTotalJobTime() const
{
	unsigned short totalTime = 0;
	for (auto &aTask : taskVector)
	{
		if (aTask.GetTaskScheduled() == false)
		{
			totalTime += aTask.GetTaskDuration();
		}
	}
	return totalTime;
}

bool Job::AllTasksScheduled() const
{
	return std::all_of(taskVector.begin(), taskVector.end(), [=](const Task &t) { return t.GetTaskScheduled() == true; });
}

Task Job::GetFirstUnscheduledTask()
{
	for (auto t : taskVector)
	{
		if (t.GetTaskScheduled() == false)
		{
			return t;
		}
	}
	return 0;
}

void Job::StartJob(unsigned short aStartTime)
{
	startTime = aStartTime;
	jobScheduled = true;
}

void Job::ScheduleTask(unsigned short taskID, unsigned short anEndTime)
{
	for (auto &t : taskVector)
	{
		if (t.GetTaskID() == taskID)
		{
			t.SetTaskScheduled(true);
		}
	}
	endTime = anEndTime;
}

void Job::ParseTaskConfig()
{
	std::regex rgx("[0-9]+");
	std::regex_iterator<std::string::iterator> regexIterator(input.begin(), input.end(), rgx);
	std::regex_iterator<std::string::iterator> regexEnd;
	unsigned short matches = 0, taskID = 0, machineID = 0, taskDuration = 0;

	while (regexIterator != regexEnd)
	{
		if (matches % 2)
		{
			taskDuration = std::stoi(regexIterator->str());
		}
		else
		{
			machineID = std::stoi(regexIterator->str());
		}

		if (matches % 2)
		{
			taskVector.push_back(Task(taskID, machineID, taskDuration, false));
			machineID = 0;
			taskDuration = 0;
			taskID++;
		}
		++matches;
		++regexIterator;
	}
}

std::vector<Task> &Job::GetTaskVector()
{
	return taskVector;
}

unsigned short Job::GetEndTime() const
{
	return endTime;
}

unsigned short Job::GetJobID() const
{
	return jobID;
}

unsigned short Job::GetStartTime() const
{
	return startTime;
}

bool Job::GetJobScheduled() const
{
	return jobScheduled;
}