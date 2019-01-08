//
// Created by miladibra on 1/3/19.
//

#ifndef __MYOS__GDT_H
#define __MYOS__GDT_H

#include "common/types.h"
namespace myos{
    class GlobalDescriptorTable{
    public:
        class SegmentDescriptor{
        public:
            SegmentDescriptor(myos::common::uint32_t base, myos::common::uint32_t limit, myos::common::uint8_t type);
            myos::common::uint32_t Base();
            myos::common::uint32_t Limit();
        private:
            myos::common::uint16_t limit_lo;
            myos::common::uint16_t base_lo;
            myos::common::uint8_t base_hi;
            myos::common::uint8_t type;
            myos::common::uint8_t limit_hi;
            myos::common::uint8_t base_vhi;
        }__attribute__((packed));
        GlobalDescriptorTable();
        ~GlobalDescriptorTable();
        myos::common::uint16_t CodeSegmentSelector();
        myos::common::uint16_t DataSegmentSelector();
    private:
        SegmentDescriptor nullSegmentSelector;
        SegmentDescriptor unusedSegmentSelector;
        SegmentDescriptor codeSegmentSelector;
        SegmentDescriptor dataSegmentSelector;
    };

}


#endif //MYOSPROJECT_GDT_H
