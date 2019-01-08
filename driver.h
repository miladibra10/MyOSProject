//
// Created by miladibra on 1/8/19.
//

#ifndef MYOSPROJECT_DRIVER_H
#define MYOSPROJECT_DRIVER_H

class Driver{
public:
    Driver();
    ~Driver();

    virtual void Activate();
    virtual int Reset();
    virtual void Deactivate();

};

class DriverManager{
private:
    Driver* drivers[256];
    int numDrivers;
public:
    DriverManager();
    void AddDriver(Driver*);
    void ActivateAll();
};

#endif //MYOSPROJECT_DRIVER_H
