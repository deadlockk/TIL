# Performance Issues
* Longest delay determines clock period
* Critical path : load instruction

>Instruction memory
>>register file
>>>ALU
>>>>data memory
>>>>>register file

>IF : instruction fetch from memory
>>ID : instruction decode & register read
>>>EX : execute operation or calculate address
>>>>MEM : access memory operand
>>>>>WB : write back to register