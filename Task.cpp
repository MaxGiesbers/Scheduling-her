#include "Task.h"

Task::Task(unsigned short aTaskID, unsigned short aMachineID, unsigned short aTaskDuration, bool aTaskScheduled)
    : taskID(aTaskID), machineID(aMachineID), taskDuration(aTaskDuration), taskScheduled(aTaskScheduled)
{
}

Task::~Task()
{
}

unsigned short Task::GetTaskID() const
{
    return taskID;
}

unsigned short Task::GetMachineID() const
{
    return machineID;
}

unsigned short Task::GetTaskDuration() const
{
    return taskDuration;
}

bool Task::GetTaskScheduled() const
{
    return taskScheduled;
}

void Task::SetTaskScheduled(bool aTaskScheduled)
{
    taskScheduled = aTaskScheduled;
}
