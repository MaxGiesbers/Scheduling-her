/*
 * JobShop.h
 *
 *  Created on: 19 sep. 2017
 *      Author: max_g
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

class JobShop
{

private:
	unsigned short currentTime;

	std::vector<Job> jobVector;
	std::vector<Machine> machineVector;
public:
	JobShop(unsigned short aCurrentTime);
	virtual ~JobShop();

	void SortJobs();
	void checkAvailableMachines();

	unsigned short GetCurrentTime() const;
	void SetCurrentTime(unsigned short currentTime);
	std::vector<Job> GetJobVector() const;
	const std::vector<Machine>& GetMachineVector() const;
};

#endif /* JOBSHOP_H_ */
