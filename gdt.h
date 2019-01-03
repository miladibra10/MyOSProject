//
// Created by miladibra on 1/3/19.
//

#ifndef MYOSPROJECT_GDT_H
#define MYOSPROJECT_GDT_H

#include "types.h"

class GlobalDescriptorTable{
public:
  class SegmentDescriptor{
  public:
    SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
    uint32_t Base();
    uint32_t Limit();
  private:
    uint16_t limit_lo;
    uint16_t base_lo;
    uint8_t base_hi;
    uint8_t type;
    uint8_t limit_hi;
    uint8_t base_vhi;
  }__attribute__((packed));
  GlobalDescriptorTable();
  ~GlobalDescriptorTable();
  uint16_t CodeSegmentSelector();
  uint16_t DataSegmentSelector();
private:
  SegmentDescriptor nullSegmentSelector;
  SegmentDescriptor unusedSegmentSelector;
  SegmentDescriptor codeSegmentSelector;
  SegmentDescriptor dataSegmentSelector;
};

#endif //MYOSPROJECT_GDT_H
