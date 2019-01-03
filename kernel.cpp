//
// Created by miladibra on 1/1/19.
//
#include "types.h"
#include "gdt.h"
void printf(char* str)
{
  static uint16_t* VideoMemory = (uint16_t*)0xb8000;

  for(int i = 0; str[i] != '\0'; ++i)
    VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}



typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
  for(constructor* i = &start_ctors; i != &end_ctors; i++)
    (*i)();
}



extern "C" void kernelMain(const void* multiboot_structure, uint16_t /*multiboot_magic*/)
{
  printf("Milad's Own Operating System !!!");
  GlobalDescriptorTable gdt;
  while(1);
}
