#pragma once
#include <string>
#include <vector>
#include <numeric>
#include "Task.h"
#include <algorithm>

class Job
{
private:
	/// <summary>
	/// Vector that contains all the tasks from a job
	/// </summary>
	std::vector<Task> taskVector;

	/// <summary>
	/// String created by the configuration file containing all data for one specific job
	/// </summary>
	std::string input;

	/// <summary>
	/// ID to find individual jobs
	/// </summary>
	unsigned short jobID;

	/// <summary>
	/// Time on that will be set once the job has started
	/// </summary>
	unsigned short startTime;

	/// <summary>
	/// Time that will be updated every time a task is scheduled
	/// </summary>
	unsigned short endTime;

	/// <summary>
	/// Turns true when the first task of the job is scheduled
	/// </summary>
	bool jobScheduled;

	/// <summary>
	/// Parse config file and create tasks
	/// </summary>
	void ParseTaskConfig();

public:
	/// <summary>
	/// Constructor with for creating Job class
	/// </summary>
	/// <param name="anInput">String created by the configuration file</param>
	/// <param name="aJobID">ID to find individual jobs</param>
	/// <param name="aStartTime">Time on that will be set once the job has started</param>
	/// <param name="aEndTime">Time that will be updated every time a task is scheduled</param>
	/// <param name="aJobScheduled">Turns true when the first task of the job is scheduled</param>
	Job(const std::string &anInput = "", const unsigned short aJobID = 0, unsigned short aStartTime = 0, unsigned short aEndTime = 0, bool aJobScheduled = false);

	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~Job();

	/// <summary>
	/// Adds all the taskdurations from one job to a variable
	/// </summary>
	/// <returns>Returns added taskdurations of one job</returns>
	unsigned short GetTotalJobTime() const;

	/// <summary>
	/// Checks if all tasks from one job are scheduled
	/// </summary>
	/// <returns>Returns true when all tasks form one job are scheduled</returns>
	bool AllTasksScheduled() const;

	/// <summary>
	/// Find first unscheduled task in taskVector from one job
	/// </summary>
	/// <returns>Returns a task object</returns>
	Task GetFirstUnscheduledTask();

	/// <summary>
	/// Set the startTime of the job and set the job a started so the startTime can only be set once
	/// </summary>
	/// <param name="aStartTime">The startTime of the job will be set to this parameter</param>
	void StartJob(unsigned short aStartTime);

	/// <summary>
	/// Set one task as scheduled and update the endTime of the job
	/// </summary>
	/// <param name="taskID">The ID of the task that will be set as scheduled</param>
	/// <param name="anEndTime">The endTime of the job will be set to this variable</param>
	void ScheduleTask(unsigned short taskID, unsigned short anEndTime);

	/// <summary>
	/// Getter for taskVector
	/// </summary>
	/// <returns>Returns std::vector taskVector</returns>
	std::vector<Task> &GetTaskVector();

	/// <summary>
	/// Getter for jobID
	/// </summary>
	/// <returns>Returns unsigned short jobID</returns>
	unsigned short GetJobID() const;

	/// <summary>
	/// Getter for endTime
	/// </summary>
	/// <returns>Returns unsigned short endTime</returns>
	unsigned short GetEndTime() const;

	/// <summary>
	/// Getter for startTime
	/// </summary>
	/// <returns>Returns unsigned short startTime</returns>
	unsigned short GetStartTime() const;

	/// <summary>
	/// Getter for jobScheduled
	/// </summary>
	/// <returns>Returns bool jobScheduled</returns>
	bool GetJobScheduled() const;
};