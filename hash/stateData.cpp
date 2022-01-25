#include <iostream>
#include "hashTable.h"
#include "stateData.h"

void stateData::setStateInfo(std::string sName, std::string sCapital, double stArea, int yAdm, int oAdm)
{
    this->_stateName = sName;
    this->_stateCapital = sCapital;
    this->_stateArea = stArea;
    this->_yearOfAdmission = yAdm;
    this->_orderOfAdmission = oAdm;
}
void stateData::getStateInfo(std::string &sName, std::string &sCapital, double &stArea, int &yAdm, int &oAdm)
{
    sName = this->_stateName;
    sCapital = this->_stateCapital;
    stArea = this->_stateArea;
    yAdm = this->_yearOfAdmission;
    oAdm = this->_orderOfAdmission;
}
std::string stateData::getStateName()
{
    return _stateName;
}

std::string stateData::getStateCapitalName()
{
    return _stateCapital;
}

double stateData::getArea()
{
    return _stateArea;
}

int stateData::getYearOfAdmission()
{
    return _yearOfAdmission;
}

int stateData::getOrderOfAdmission()
{
    return _orderOfAdmission;
}

void stateData::printInfo()
{
    std::cout << "State name: " << _stateName << std::endl;
    std::cout << "Capital name: " << _stateCapital << std::endl;
    std::cout << "Area: " << _stateArea << std::endl;
    std::cout << "Year of admission: " << _yearOfAdmission << std::endl;
    std::cout << "Order of admission: " << _orderOfAdmission << std::endl;
}

bool stateData::operator==(const stateData &right) const
{
    return (_stateName == right._stateName);
}

bool stateData::operator!=(const stateData &right) const
{
    return (_stateName != right._stateName);
}