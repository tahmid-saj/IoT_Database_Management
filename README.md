Introduction

The development of wireless sensor nodes specific for environmental monitoring using the Long-Range
Wireless Access Network (LoRaWAN) has become a focus in the Internet of Things (IoT) industry. Environmental 
monitoring requires various climatic and environmental parameters such as temperature, humidity, water level and
soil moisture. Throughout this project, the utilization of two specific sensors, the eTape water level sensor and the 
SHT31 temperature and humidity sensor, has provided the measurement of these environmental parameters needed
for monitoring using LoRaWAN. These two sensors were used in this project with a Dragino supplied LoRaWAN 
sensor node, the LSN50 and a supplied gateway. After necessary connection and programming between these 
sensors, the sensor node and gateway, monitoring could reflect the desired environmental parameters.

Purpose of the system

The overall monitoring system consists of two separate monitoring subsystems. Firstly, the eTape sensor 
and the LSN50 will be connected to a gateway to deliver water level data to The Things Network (TTN). This data 
will then be visualized using Cayenne My Devices, such that various water levels and LSN50 battery values are 
measured in different nodes with respect to time. Secondly, the SHT31 sensor will also be connected to the LSN50 
and a gateway to deliver temperature and humidity data of different nodes. This data will also be visualized with 
respect to time. 

IoT Database Application – Planning and Design

Specifications:

Create a database management system and calculator for any csv files inputted into the program. The csv files will contain data of water levels, temperature and humidity of nodes. Also make a linear regression calculator which calculates if the regression equation should change based on percent error calculations using real measures of water levels. 

Functional Requirements:

The data structures should behave as described in the following:

Doubly Linked List - Use a double linked list to hold the daily data files in terms of days. The linked list should hold data of water levels, temperature and humidity of nodes, and to perform calculations for the three parameters. The calculations may be the following: calculating average measure over period of time, calculating maximum measure over a period of time, calculating minimum measure over a period of time, displaying data for the days entered by the user, calculating percent error between a data and an entered value representing the actual measured value. Furthermore, the linear regression calculation will include finding the voltage calibration of a data set of the water levels. (Put the similar operations on the linked list from chapter 3, and allow the user to modify the data files from the application using these operations). 

Operations:

1.Inserting a node to the head
2.Inserting a node to the tail 
3.Inserting a node (should insert data into data file as well)
4.Deleting a node (should delete data from data file as well)
5.Searching a node
6.Check if empty
7.Is in the linked list

Math Operations:

1.Calculating average measure over period of time
2.Calculating maximum measure over a period of time
3.Calculating minimum measure over a period of time
4.Calculating percent error between a data and an entered value representing the actual measured value
5.Calculating the voltage calibration of a data set of the water levels using linear regression calculation (only available for water level data)

Queue – Use a queue to store node upgrade tasks (when there is no priority given to tasks) based on data files of the three types of nodes, the water level measuring, temperature and humidity nodes. (Put the similar operations on the queue from chapter 4, and allow the user to modify the data files from the application using these operations).

Operations:

1.Inserting a node from the tail (should insert data into data file as well)
2.Deleting a node from the head (should delete data from data file as well)
3.Return the front node
4.Check if empty

Priority Queue - Use a priority queue to store node upgrade tasks based on data files of the three types of nodes, the water level measuring, temperature and humidity nodes. If any nodes need immediate update. then it should go first, but if the nodes don’t need immediate update, it can go last. (Put the similar operations on the priority queue from chapter 4, and allow the user to modify the data files from the application using these operations).

Operations:

1.Inserting a node anywhere (should insert data into data file as well)
2.Deleting a node from the head (should delete data from data file as well)
3.Return the front node
4.Check if empty
Stack – Use a stack to reverse a copy of the linked lists, and display the data from the reverse order for the water levels, temperature and humidity if the user chooses. (Put the similar operations on the stack from chapter 4, and allow the user to modify the data files from the application using these operations).

Operations:

1.Pushing (insert) a node
2.Popping (delete) a node
3.Returning (search) the top node
4.Check if empty

Binary Search Tree - Use a binary search tree (from the data files, implement three binary search trees, where the three trees will be for water level data, temperature data and humidity data. For instance, one tree will contain all the water level nodes, and each node contains the most recent water level measurement, and additionally, since this is a binary search tree, the tree will be sorted per the binary search tree criteria). (Put the similar operations on the tree from chapter 6, and allow the user to modify the data files from the application using these operations).

Operations:

1.Inserting a node
2.Deleting a node
3.Searching a node
4.Check if empty

The main function will first load the four data files for water level, temperature, humidity and node upgrade tasks. These data files will be .csv files. The main function will then use these four data files to create the data structures which to operate on and perform calculations for, based on user input.
Non-functional Requirements:

-Quick display of data structures
-Variety of calculations available
-Accurate information displayed
-Applicable to different files with same structures
