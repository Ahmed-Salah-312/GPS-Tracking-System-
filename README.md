## GPS Tracking System

This project focuses on developing a GPS tracking system using TM4C123GH6PM LaunchPad & using GPS module neo6m with EPROM. The system incorporates the following functionalities:

### GPS Subsystem
The GPS subsystem is responsible for dynamically storing the coordinates of both the start and end points. It also calculates the total distance covered by the user between these points. The system produces the following outputs based on the user's progress:

- Stage 1: When the target destination is reached, the built-in LED turns on (green).
- Stage 2: When the user is within a 5-meter radius of the target destination, the built-in LED turns on (yellow) to indicate proximity.
- Stage 3: When the target destination is far away (distance > 5 meters), the built-in LED turns on (red).

### Path Criteria
The trajectory of the distance traveled must adhere to the following criteria:

1. Total distance: The distance between the start and end points should be greater than 100 meters.
2. Path shape: The path followed from the start point to the end point should resemble a non-straight line.

## Authors
- Leader: [Ahmed Salah](https://github.com/Ahmed-Salah-312)
- [Youssef Wael](https://github.com/youssefashmawy)
- [Muhammad Mahmoud](https://github.com/skipcl4ss)
- [Youssef Ehab](https://github.com/Youssef231001)
- [Mohamed Hany](https://github.com/mohamed-hany1016)
- [kebrianous Wagih](https://github.com/kebrianous-wagih)
- [Mahmoud Hassan](https://github.com/MahmoudHassan72)
- [Ahmed Ibrahim](https://github.com/ahmeedibrahim)
- [Saied Mohamed](https://github.com/Saa3ed)
- [Ziad Fikry](https://github.com/ZiadFikry)
