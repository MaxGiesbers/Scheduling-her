#pragma once

class Task{

private:
    const unsigned short taskID;
    const unsigned short machineID;
    unsigned short taskDuration;
    bool taskScheduled;

public:
    Task(unsigned short aTaskID = 0, unsigned short aMachineID = 0, unsigned short aTaskDuration = 0, bool aTaskScheduled = false);
    virtual ~Task();
    unsigned short GetTaskID() const;
    unsigned short GetMachineID() const;
    unsigned short GetTaskDuration() const;
    bool GetTaskScheduled() const;
    void SetTaskScheduled(bool aTaskScheduled);
};
