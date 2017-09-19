#include <regex>
#include "Job.h"

Job::Job(unsigned short aJobID, const std::string &mInput)
	: jobID(aJobID), input(mInput)
{
	ParseTaskConfig();
}

Job::~Job()
{
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

unsigned short Job::ReturnTotalTime() const
{
	unsigned short totalTime = 0;
	for (auto &e : taskVector)
	{
		totalTime += e.getTaskDuration();
	}
	return totalTime;
}

std::vector<Task> &Job::GetTaskVector()
{
	return taskVector;
}

Job &Job::operator=(const Job &b)
{
	if (this != &b)
	{
		jobID = b.jobID;
	}
	return *this;
}

unsigned short Job::GetEndTime() const
{
	return endTime;
}

unsigned short Job::GetJobId() const
{
	return jobID;
}

unsigned short Job::GetStartTime() const
{
	return startTime;
}

bool Job::AllTasksScheduled() const
{
	return std::all_of(taskVector.begin(), taskVector.end(), [=](const Task &t) { return t.getTaskScheduled() == true; });
}

Task Job::GetFirstUnscheduledTask()
{
	for (auto t : taskVector)
	{
		if (t.getTaskScheduled() == false)
		{
			return t;
		}
	}
}

void Job::SetJobEndTime(unsigned short anEndTime)
{
	endTime = anEndTime;
}

void Job::SetJobStartTime(unsigned short aStartTime)
{
	startTime = aStartTime;
}

void Job::SetTask(unsigned short taskId)
{
	for (auto &t : taskVector)
	{
		if(t.getTaskID() == taskId)
		{
			t.SetTaskScheduled(true);
		}
	}
}