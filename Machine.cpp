/*
 * Machine.cpp
 *
 *  Created on: 19 sep. 2017
 *      Author: max_g
 */

#include "Machine.h"

Machine::Machine(unsigned short aMachineID, unsigned short aOccupiedUntil):
machineID(aMachineID), occupiedUntil(aOccupiedUntil)
{
}

unsigned short Machine::GetMachineId() const
{
	return machineID;
}

void Machine::SetMachineId(unsigned short machineId)
{
	machineID = machineId;
}

unsigned short Machine::GetOccupiedUntil() const
{
	return occupiedUntil;
}

void Machine::SetOccupiedUntil(unsigned short occupiedUntil)
{
	this->occupiedUntil = occupiedUntil;
}

Machine::~Machine()
{
}

