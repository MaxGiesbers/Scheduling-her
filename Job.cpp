#include <regex>
#include "Job.h"

Job::Job(const std::string &mInput,unsigned short aJobID , unsigned short aStartTime, unsigned short aEndtime) :
input(mInput), jobID(aJobID)
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
	for(auto &e : taskVector)
	{
		totalTime += e.GetTaskDuration();
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

unsigned short Job::GetJobID() const
{
	return jobID;
}

unsigned short Job::GetStartTime() const
{
	return startTime;
}

bool Job::AllTasksScheduled() const
{
	return std::all_of(taskVector.begin(), taskVector.end(), [=](const Task &t)
	{	return t.GetTaskScheduled() == true;});
}

Task Job::GetFirstUnscheduledTask()
{
	for(auto t : taskVector)
	{
		if (t.GetTaskScheduled() == false)
		{
			return t;
		}
	}
	return 0;
}

void Job::SetJobEndTime(unsigned short anEndTime)
{
	endTime = anEndTime;
}

void Job::SetJobStartTime(unsigned short aStartTime)
{
	startTime = aStartTime;
}

void Job::SetTask(unsigned short taskID)
{
	for(auto &t : taskVector)
	{
		if (t.GetTaskID() == taskID)
		{
			t.SetTaskScheduled(true);
		}
	}
}
