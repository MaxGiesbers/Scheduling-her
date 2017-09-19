#include <vector>
#include "Task.h"

class Job{

private:
    std::vector<Task> taskVector;
    unsigned short jobID;

public:
    Job(unsigned short aJobID = 0);
    ~Job();
    std::vector<Task>& getTaskVector();

};