I tried my best to design an Occupancy Detection and Alert System. This is what it does. 

I was going to use an initilization function, but then I decided against it. I am not spectacular at programming, and messing up a function was the last thing I need to do. My first steps were to stop the watchdog timer, and then to unlock the MSP so that it is able to be programmed. The first steps of any program requiring the MSP. I then set my LEDs as outputs and my reset button as an input. I cleared any previously configured settings for the LEDs. 

I set my program to operate similar to Prof. Trafford's skeleton, using three different states. An actual sensor was not provided, so I made a variable called "sensor" to act as my sensor. A "1" in my sensor represented the detection of someone. 

In my armed state, if a sensor  detected someone, I first set my little time variable to 0. I then set my state to the warning state. If it did not detect anyone, it would turn off the red LED, blink the green LED every three seconds, and reset my time variable. 

In my warning state, I started by turning off the red LED. Then, if it detected someone, I first reset my time. Then, I blinked the red LED every half a second, and incremented my time. If my time reached nineteen (by the time it realized, the time would have reached twenty), then ten seconds would have elapsed. The time resets, and state turns to armed. After half a second, it would continue to add time. If my time had not yet reached ten sseconds, the state moved to armed. 

In the alert state, if the reset button 1.4 is pressed, the state moves back to armed. Then, the red LED is turned on. 

Thanks for reading!
