#include "Task.h"

Task::Task(unsigned short aTaskID, unsigned short aMachineID, unsigned short aTaskDuration, bool aTaskScheduled)
    : taskID(aTaskID), machineID(aMachineID), taskDuration(aTaskDuration), taskScheduled(aTaskScheduled)
{
}

Task::~Task()
{
}

unsigned short Task::getTaskID() const
{
    return taskID;
}

unsigned short Task::getMachineID() const
{
    return machineID;
}

unsigned short Task::getTaskDuration() const
{
    return taskDuration;
}

bool Task::getTaskScheduled() const
{
    return taskScheduled;
}

void Task::SetTaskScheduled(bool aTaskScheduled)
{
    taskScheduled = aTaskScheduled;
}