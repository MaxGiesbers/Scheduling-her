#pragma once
#include <iostream>
#include <vector>
#include "Task.h"

class Job
{
  private:
    std::vector<Task> taskVector;
    std::string input;
    const unsigned short jobID;

  public:
    Job(unsigned short aJobID, const std::string &mInput);
    virtual ~Job();
    std::vector<Task> &getTaskVector();
};