**Class Course:** <br />
<br />
The class named Course is implemented in the files named **"course.cpp"** and **"course.h"**. It has a constructor that takes a multiline string that denotes a 2-d racetrack. The periods are the grass, the asterisks are pavement, the 'S' character denotes the start position, and the 'F' denotes the finish position. 

The Course class uses the insertion operator to write the layout to an ostream. The layout is wrapped in '+' (plus signs) to make it easier to distinguish multiple courses printed to the same stream.

A void member function named **"AddVehicleToStart"** takes a pointer to a Vehicle object. This member function is used to register a Vehicle with the Course. Henceforth, the insertion operator shows where that Vehicle is on the course (starting at the start (S)). If multiple Vehicles occupy the same position, Only the most recently provided to the "AddVehicleToStart" is displayed.

Course implements a copy constructor that copies the layout, but not the Vehicles on it.

Course implements an assignment operator that assigns the layout and the vehicles to the lhs.

 The member function named **"VehiclesAtFinish"** takes no parameters, and returns a std::set of Vehicles denoting the Vehicles that are currently occupying the Finish position. The second member function is **"ReturnOffTrackVehiclesToStart"** which also doesn't take any parameters. Its primary purpose is to move all Vehicles that aren't on the course (meanng not on S, *, or F positions) to the start. This function should returns the number of Vehicles that needed to be moved.

 

**Class Vehicles:**<br />
<br />
The class named **Vehicle** is implemented in the files named **"vehicle.cpp"** and **"vehicle.h"**. Vehicles are constructed with a char. This char is how the Vehicle is represented in the course layout. Vehicles implement the < and == operators, using their char for comparisons. When a Vehicle is written to an ostream, its char is written. Vehicles have a SetBearing member function that takes a char **('N', 'S, 'E', or 'W')**, which denotes the cardinal direction the object is facing, anything else throws an std::invalid_argument exception. The **MoveForward** member function takes an int (defaulting to 1) indicating how many spaces to move in the direction of its bearing. For example, if a Vehicle's bearing is East and it moves forward by 2, its location is 2 spaces to the right (as depicted in the Course's layout). Vehicles also have **TurnLeft** and **TurnRight** member functions that adjust its bearing. 
Each Vehicle is only  associated with one Course.
