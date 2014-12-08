ECE382Lab7
==========
Austin Bolinger

Dr. York

ECE 382

03 Dec 14


Description: Lab 7 is IR senors talking to the MSP430. This builds off of lab 6 where we found a way to use our remote controlls to operate the robot. Now the IR sensors built in to the robot will detect walls. It is up to me to use code to turn on LEDs to show that it is detecting walls.

Objective: This lab is designed to assist you in learning the concepts associated with the analog-to-digital converter (ADC) for your MSP430. A set of three infrared (IR) emitter and detector pairs on your robot is used to bring in analog voltage values for the ADC. You will program your MSP430 to interpret these incoming voltages to determine whether your mobile robot is approaching a wall in front or on one of its sides. The skills you will learn from this lab will come in handy in the future b especially for your senior design project since many designs require you to interface analog systems with digital systems.

##Prelab

**Hardware Setup**
This is what the MSP430 looks like in picture form.

![MSP430]( https://github.com/Austinbolinger/ECE382Lab7/blob/master/MSP430.JPG?raw=true "MSP430" )

The pins I chose are important. As you can see below, they line up with A3, A4, & A5 which will be used in the coding.

![MSP430 diagram]( https://github.com/Austinbolinger/ECE382Lab7/blob/master/MSP430diagram.JPG?raw=true "MSP430 diagram" )

**Psuedo Code**
In order to operate the sensors, I used code from the lesson powerpoint. It demonstrates the right registers to use.

First: turn on interrupt for the ADC
Second: select the input (in this case the pin's A value)
Then: select the pin
Next: select the SMCLK
Then: enable the conversion and sampling for the ADC
Then: force exit the CPU
Next: compare the register with the voltage reading to half of 2^10 bits
Finally: change the lights according to which pin was read and what the voltage was.

![Flow Chart]( https://github.com/Austinbolinger/ECE382Lab7/blob/master/FlowChart.JPG?raw=true "Flow Chart" )


**Testing**
I first started by hooking up power to the the sensors. Next I hooked up the DMM to test the voltage outputs when a piece of paper got closer and closer. I noticed that the voltage range is from 0.1V to 3V. And 3V only occurs when really close to the sensors. I also noticed that my right sensor does not always work. I played around with the angle and noticed that I could position it so that it worked better most of the time.

##Lab

####Functionality
Use the ADC subsystem to light LEDs based on the presence of a wall. The presence of a wall next to the left sensor should light LED1 on your Launchpad board. The presence of a wall next to the right sensor should light LED2 on your Launchpad board. Demonstrate that the LEDs do not light until they come into close proximity with a wall.

####B Functionality
Create a standalone library for your ATD code and release it on Github. This should be separate from your lab code. It should have a thoughtful interface and README, capable of being reused in the robot maze laboratory.
https://github.com/Austinbolinger/ECE382Lab7/tree/master/Lab7pre

####A Functionality

![Data]( https://github.com/Austinbolinger/ECE382Lab7/blob/master/data.JPG?raw=true "data" )

![Graph]( https://github.com/Austinbolinger/ECE382Lab7/blob/master/graph.JPG?raw=true "graph" )

####Debuggin Functionality
I could not figure out how to read the ADCMEM for multiple sensors at one time. I tried googling the problem. But, the clearity did not kick in until I talked with Dr. York. He suggested that I just do what I know I can do [one sensor reading at a time] and then just repeat the process three times. So I went with three functions that called up each sensor. They pins I picked on the MSP430 relate to the A3, A4, and A5. In the code I had to specify which pin to talk to and which 

####Debuggin B Functionality


####Debuggin A Functionality


#### Documentation
Lesson 35 powerpoint sent out by Dr. York
Dr. York suggested multiple functions instead of trying to cram it all in to one function for each sensor
