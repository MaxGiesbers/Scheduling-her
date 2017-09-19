class Task{

private:
    unsigned short taskID;
    unsigned short machineID;
    unsigned short taskDuration;
    bool taskScheduled;

public:
    Task(unsigned short aTaskID = 0, unsigned short aMachineID = 0, unsigned short aTaskDuration = 0, bool aTaskScheduled = false);
    ~Task();
    unsigned short getTaskID() const;
    unsigned short getMachineID() const;
    unsigned short getTaskDuration() const;
    bool getTaskScheduled() const;
};