/*
 * Vehicle.h
 *
 *  Created on: Sep 27, 2012
 *      Author: ster
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <string>
#include <vector>

using namespace std;

/*
 *
 */
class Vehicle
{
private:
  int ID;
  string brand;
  string model;
  string licensePlate;
public:
  Vehicle();
  Vehicle(int id, string bd, string mdl, string lp);
  int getID() const;
  string getBrand() const;
  string getModel() const;
  string getLicensePlate() const;
  virtual
  ~Vehicle();
};

/*
 *
 */
class Car: public Vehicle
{
private:
  string type;
public:
  Car();
  Car(int id, string bd, string mdl, string lp, string tp);
  string getType() const;
  virtual
  ~Car();
};


/*
 *
 */
class Truck: public Vehicle
{
private:
  string category;
public:
  Truck();
  Truck(int id, string bd, string mdl, string lp, string cat);
  string getCategory() const;
  virtual
  ~Truck();
};


/*
 *
 */
class Bike: public Vehicle
{
public:
  Bike();
  Bike(int id, string bd, string mdl, string lp);
  virtual
  ~Bike();
};


#endif /* VEHICLE_H_ */
