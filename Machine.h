/*
 * Machine.h
 *
 *  Created on: 19 sep. 2017
 *      Author: max_g
 */

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine
{
private:
	const unsigned short machineID;
	unsigned short occupiedUntil;
public:
	Machine(unsigned short aMachineID, unsigned short aOccupiedUntil);
	virtual ~Machine();
	unsigned short GetMachineId() const;
	void SetMachineId(unsigned short machineId);
	unsigned short GetOccupiedUntil() const;
	void SetOccupiedUntil(unsigned short occupiedUntil);
};

#endif /* MACHINE_H_ */
