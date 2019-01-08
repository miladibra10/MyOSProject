//
// Created by miladibra on 1/4/19.
//

#ifndef MYOSPROJECT_KEYBOARD_H
#define MYOSPROJECT_KEYBOARD_H
#include "types.h"
#include "interrupts.h"
#include "driver.h"
#include "port.h"

class KeyboardEventHandler
{
public:
    KeyboardEventHandler();

    virtual void OnKeyDown(char);
    virtual void OnKeyUp(char);
};


class KeyboardDriver : public InterruptHandler, public Driver
{
  Port8Bit dataport;
  Port8Bit commandport;
  KeyboardEventHandler* handler;
public:
  KeyboardDriver(InterruptManager* manager, KeyboardEventHandler* handler);
  ~KeyboardDriver();
  virtual uint32_t HandleInterrupt(uint32_t esp);
  virtual void Activate();
};
#endif //MYOSPROJECT_KEYBOARD_H
