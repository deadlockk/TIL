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

## Quiz 3
1. computer A -> 10 seconds run, 2GHz clock

    computer B -> 6 seconds run, 1.2 times of 2GHz( 2.4 GHz )

    __clock rate = clock cycles/cpu time__

    A rate = 2/10 = 0.2
    B rate = 2.4/6 = 0.4

    **Ans : B must have twice the clock rate of A.**

2. computer A -> clock cycle time = 250ps , CPI = 2.0

    computer B -> clock cycle time = 500ps , CPI = 1.2

    __Cpu time = IC * CPI * clock cycle time__

    A time = IC * 2 * 250 = 500
    B time = IC * 1.2 * 500 = 600

    **Ans : A is 1.2 times faster than B**

3. 
    

    lw $t1, 0($t0)  
    lw $t2, 4($t0)  
    add $t3, $t1, $t2  
    sw $t3, 12($t0)  
    lw $t4, 8($t0)  
    add $t5, $t1, $t4  
    sw $t5, 16($t0)  


Reordering to avoid pripeline stalls.

        
    lw $t1, 0($t0)  
    lw $t2, 4($t0)  
    lw $t4, 8($t0) 
    add $t3, $t1, $t2  
    sw $t3, 12($t0)   
    add $t5, $t1, $t4  
    sw $t5, 16($t0)  