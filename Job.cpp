#include "Job.h"


Job::Job(unsigned short aJobID, const std::string &mInput)
    : jobID(aJobID), input(mInput)
{
}

Job::~Job()
{
}


unsigned short Job::ReturnTotalTime()
{
	unsigned short totalTime = 0;
	for(auto & e : taskVector)
	{
		totalTime += e.getTaskDuration();
	}
	return totalTime;
}

std::vector<Task>& Job::GetTaskVector()
{
	return taskVector;
}

Job& Job::operator =(const Job& b)
{
	if (this != &b)
	{
		jobID = b.jobID;
	}
	return *this;
}
