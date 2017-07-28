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

To compile, please enter the following command:
g++ -std=c++11 main.cpp GPS_Measurements.cpp City_Nodes.cpp Message_Queues.cpp -o Hock.o
Then to run the file please enter the following command:
./Hock.o
