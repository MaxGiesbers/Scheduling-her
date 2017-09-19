#include "Job.h"

Job::Job(unsigned short aJobID, const std::string &mInput)
    : jobID(aJobID), input(mInput)
{
}

Job::~Job()
{
}

std::vector<Task> &Job::getTaskVector()
{
    return taskVector;
}