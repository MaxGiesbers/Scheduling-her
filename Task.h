#pragma once

class Task{

private:
    unsigned short taskID;
    unsigned short machineID;
    unsigned short taskDuration;
    bool taskScheduled;

public:
    Task(unsigned short aTaskID = 0, unsigned short aMachineID = 0, unsigned short aTaskDuration = 0, bool aTaskScheduled = false);
    virtual ~Task();
    Task (const Task &aTask);

    unsigned short GetTaskID() const;
    unsigned short GetMachineID() const;
    unsigned short GetTaskDuration() const;
    bool GetTaskScheduled() const;
    void SetTaskScheduled(bool aTaskScheduled);

};
