/*
 * Vehicle.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: ster
 */

#include "Vehicle.h"

Vehicle::Vehicle()
{
  ID = 0;
  brand = "";
  model = "";
  licensePlate = "";
}

Vehicle::Vehicle(int id, string bd, string mdl, string lp)
{
  ID = id;
  brand = bd;
  model = mdl;
  licensePlate = lp;
}

Car::Car(int id, string bd, string mdl, string lp, string tp):Vehicle(id,bd,mdl,lp)
{
  type = tp;
}

Truck::Truck(int id, string bd, string mdl, string lp, string cat):Vehicle(id,bd,mdl,lp)
{
  category = cat;
}

Bike::Bike(int id, string bd, string mdl, string lp):Vehicle(id,bd,mdl,lp)
{}

//Vehicle class methods implementation
int Vehicle::getID() const
{
  return ID;
}

string Vehicle::getBrand() const
{
  return brand;
}

string Vehicle::getModel() const
{
  return model;
}

string Vehicle::getLicensePlate() const
{
  return licensePlate;
}

//Car class methods implementation
string Car::getType() const
{
  return type;
}

//Truck class methods implementation
string Truck::getCategory() const
{
  return category;
}

Vehicle::~Vehicle()
{}

Car::~Car()
{}

Truck::~Truck()
{}

Bike::~Bike()
{}

