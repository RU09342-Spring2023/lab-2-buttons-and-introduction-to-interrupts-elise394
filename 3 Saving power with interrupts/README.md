# 1. What is causing the bias/baseline in the polling example to be higher than the interrupt example?
With polling, the program is continuously checking, while the interrupt only checks when a flag tells the program to do so.

# 2. Even with the LED unplugged, why is there still power increases when you press the button?
The interrupt is still being recognized by the MSP, and therefore power is still being used to process that information. 
