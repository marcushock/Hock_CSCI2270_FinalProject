Project Summary:
This program is used to simulate a messenger bird traveling among cities in post apocalyptic world.
The messenger bird travels between cities (nodes) and can only fly 1,000 to rest.
Therefore, all cities are connected to each other only if they are within 1,00 miles of each other.
This program reads in a text file with each city name, as well the GPS coordinates.
After reading in the text file, new cities can be added, to the network as well.
The user can input a start city, a destination city, and a message to send. Dijkstra's algorithm will
be used to find the shortest distance for the bird to travel to send the message.
The message will be store in a linked list queue because the message transmitting device can only
display one word at a time when presenting the message to the destination city.
If a city is not within 1,000 miles of another city and a bird attempts to transmit the message to
or from that city, the bird will die and the message will not be sent.

Make sure the input text file is comma delimited in the following format.
CityName,Latitude,Longitude
Example:
Boulder,40.0150,-105.2705
Note: North is represented by a positive number, South is represented by a negative number
just as East is positive and South is Negative.

Hot to Run:
To compile, please enter the following command:
g++ -std=c++11 main.cpp GPS_Measurements.cpp City_Nodes.cpp Message_Queues.cpp -o Hock.o
Then to run the file please enter the following command:
./Hock.o
The city coordinate file is called 'cities.txt'. Enter this when loading the program.

Dependencies:
This code does not require any third party libraries. It does require the following standard
libraries though:
iostream, string, sstream, cmath, fstream, climits and vector

System Requirements:
This program has been tested on Linux. It should run on Mac and Windows, but has not been tested.

Name: Marcus Hock

Open Issues/Bugs:
There is input validation for most user input areas. However, when adding a new city,
if a non-numeric value is entered for the latitude or longitude, the program will crash.

Note:
The project requirements state that there needs to be at least one class and seven public
methods. This project has three classes and over 7 public methods in total.
