# GPS-Tracking-System-
In this project we developed the following system using TM4C123GH6PM LaunchPad:

The GPS subsystem stores the coordinates of the start point.
After reaching the destination point, the GPS subsystem stores the coordinates of the end point and calculates the total distance that was taken by the user.
The output will be translated as the following.
Stage 1: The built-in LED will be turned on(green) when the target destination is reached.
Stage 2: The built-in LED will be turned on(yellow) when the target destination is about to be reached < 5 meters.
Stage 3: The built-in LED will be turned on(red) when the target destination is far away by distance > 5 meters.
The trajectory of the distance satisfies the following criteria:
The total distance between the start and the end point should be > 100 meters.
The path from the start point to the end point should form a non-straight line that is similar to the provided baseline path below.
