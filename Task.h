#pragma once

class Task
{
private:
  /// <summary>
  /// ID to find individual tasks
  /// </summary>
  unsigned short taskID;

  /// <summary>
  /// ID of the machine which is linked to the task
  /// </summary>
  unsigned short machineID;

  /// <summary>
  /// Duration of the task
  /// </summary>
  unsigned short taskDuration;

  /// <summary>
  /// True when task is scheduled, false when otherwise
  /// </summary>
  bool taskScheduled;

public:
  Task(unsigned short aTaskID = 0, unsigned short aMachineID = 0, unsigned short aTaskDuration = 0, bool aTaskScheduled = false);
  virtual ~Task();
  Task(const Task &aTask);
  unsigned short GetTaskID() const;
  unsigned short GetMachineID() const;
  unsigned short GetTaskDuration() const;
  bool GetTaskScheduled() const;
  void SetTaskScheduled(bool aTaskScheduled);
};
