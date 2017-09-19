#pragma once
#include <vector>
#include "Task.h"
#include <numeric>

class Job{

private:
    std::vector<Task> taskVector;
    unsigned short jobID;

public:
    Job(unsigned short aJobID = 0);
    ~Job();
    std::vector<Task>& GetTaskVector();
    unsigned short ReturnTotalTime();
    Job& operator=(const Job &b);
};
