#include "Job.h"

Job::Job(unsigned short aJobID)
:jobID(aJobID)
{

}

Job::~Job()
{

}


std::vector<Task>& Job::getTaskVector()
{
    return taskVector;
}