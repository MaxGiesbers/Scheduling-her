#pragma once

class Machine
{
  public:
	/// <summary>
	/// Constructor with for creating Machine class
	/// </summary>
	/// <param name="aMachineID">ID to find individual machines</param>
	/// <param name="anOccupiedUntil">Time until the machine is currently running a task</param>
	Machine(const unsigned short aMachineID = 0, unsigned short anOccupiedUntil = 0);

	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~Machine();

	/// <summary>
	/// Getter for machineID
	/// </summary>
	/// <returns>Returns unsigned short machineID</returns>
	unsigned short GetMachineID() const;

	/// <summary>
	/// Getter for occupiedUntil
	/// </summary>
	/// <returns>Returns unsigned short occupiedUntil</returns>
	unsigned short GetOccupiedUntil() const;

	/// <summary>
	/// Setter for occupiedUntil
	/// </summary>
	/// <param name="machineNumber">The occupiedUntil from this machine will be set to this time</param>
	void SetOccupiedUntil(unsigned short anOccupiedUntil);

  private:
	/// <summary>
	/// ID to find individual machines
	/// </summary>
	const unsigned short machineID;

	/// <summary>
	/// Time until the machine is currently running a task
	/// </summary>
	unsigned short occupiedUntil;
};
