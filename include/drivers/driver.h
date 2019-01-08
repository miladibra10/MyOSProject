//
// Created by miladibra on 1/8/19.
//

#ifndef __MYOS_DRIVERS__DRIVER_H
#define __MYOS_DRIVERS__DRIVER_H

namespace myos{
    namespace drivers{
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
    }
}


#endif
