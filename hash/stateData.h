#ifndef h_stateData
#define h_stateData
#include <iostream>
#include "hashTable.h"

class stateData
{
    friend std::ostream &operator<<(std::ostream &, const stateData &);
    friend std::istream &operator>>(std::istream &, stateData &);

public:
    void setStateInfo(std::string sName, std::string sCapital, double stateArea, int yAdm, int oAdm);
    void getStateInfo(std::string &sName, std::string &sCapital, double &stateArea, int &yAdm, int &oAdm);
    std::string getStateName();
    std::string getStateCapitalName();
    double getArea();
    int getYearOfAdmission();
    int getOrderOfAdmission();
    void printInfo();
    bool operator==(const stateData &right) const;
    bool operator!=(const stateData &right) const;

private:
    std::string _stateName;
    std::string _stateCapital;
    double _stateArea;
    int _yearOfAdmission;
    int _orderOfAdmission;
};
#endif