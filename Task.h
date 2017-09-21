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
  /// <summary>
  /// Constructor with for creating Task class
  /// </summary>
  /// <param name="aTaskID">ID to find individual tasks</param>
  /// <param name="aMachineID">ID to find individual jobs</param>
  /// <param name="aTaskDuration">Duration of the task parsed from the config file</param>
  /// <param name="aTaskScheduled">Task is not scheduled as default</param>
  Task(const unsigned short aTaskID = 0, unsigned short aMachineID = 0, unsigned short aTaskDuration = 0, bool aTaskScheduled = false);

  /// <summary>
  /// Destructor
  /// </summary>
  virtual ~Task();

  /// <summary>
  /// Copy constructor for Task
  /// </summary>
  /// <param name="aTask">Task that needs to be copied</param>
  Task(const Task &aTask);

  /// <summary>
  /// Getter for taskID
  /// </summary>
  /// <returns>Returns unsigned short taskID</returns>
  unsigned short GetTaskID() const;

  /// <summary>
  /// Getter for machineID
  /// </summary>
  /// <returns>Returns unsigned short machineID</returns>
  unsigned short GetMachineID() const;

  /// <summary>
  /// Getter for taskDuration
  /// </summary>
  /// <returns>Returns unsigned short taskDuration</returns>
  unsigned short GetTaskDuration() const;

  /// <summary>
  /// Getter for taskSchuled
  /// </summary>
  /// <returns>Returns unsigned short taskScheduled</returns>
  bool GetTaskScheduled() const;

  /// <summary>
  /// Setter for taskScheduled
  /// </summary>
  /// <param name="aStartTime">taskScheduled will be set to this value</param>
  void SetTaskScheduled(bool aTaskScheduled);
};
