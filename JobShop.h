#pragma once
#include <vector>
#include <iostream>
#include "Job.h"
#include "Machine.h"

class JobShop
{
  private:
	/// <summary>
	/// String created by the configuration file
	/// </summary>
	std::string input;

	/// <summary>
	/// Time to use when running the scheduling algorithm
	/// </summary>
	unsigned short currentTime;

	/// <summary>
	/// Vector which contains all the jobs
	/// </summary>
	std::vector<Job> jobVector;

	/// <summary>
	/// Vector which contains all the machines
	/// </summary>
	std::vector<Machine> machineVector;

	/// <summary>
	/// Main funtion that contains all the logic of the scheduling algorithm
	/// </summary>
	void RunSchedulingAlgorithm();

	/// <summary>
	/// Sort all jobs based on total time and jobID
	/// </summary>
	void SortJobs();

	/// <summary>
	/// Checks if the given machine is available to schedule a task
	/// </summary>
	/// <param name="machineNumber">The machineID that needs to be checked</param>
	/// <returns>Returns true when the machine is available to schedule a task</returns>
	bool CheckAvailableMachines(unsigned short machineNumber);

	/// <summary>
	/// Check if all tasks from all jobs are scheduled
	/// </summary>
	/// <returns>Returns true when all tasks from all jobs are scheduled</returns>
	bool AllJobsScheduled() const;

	/// <summary>
	/// Parse config file and create jobs
	/// </summary>
	void ParseJobsConfig();

	/// <summary>
	/// Parse config file and create machines
	/// </summary>
	void ParseMachinesConfig();

	/// <summary>
	/// Print all results for the output file
	/// </summary>
	void PrintResults();

  public:
	/// <summary>
	/// Constructor with for creating JobShop class
	/// </summary>
	/// <param name="anInput">String created by the configuration file</param>
	/// <param name="aCurrentTime">Time to use when running the scheduling algorithm</param>
	JobShop(const std::string &anInput = "", unsigned short aCurrentTime = 0);

	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~JobShop();
};
