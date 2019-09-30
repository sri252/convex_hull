# convex_hull
Jarvis Algorithm or wrapping.

The steps involve in jarvis algorithm are:

creating a structure of Point type having x, y coordinate.
In the loop :
  a. Finding the left most Point using the x coordinate of the Points.
  b. Creating a vector of Point type to hold the hull or outer points.
  c. Now in the do while loop, search the next left most element using the orientation function and assign the next element to a vector of 
     Point type.
  d. now take the next point as the current point and repeat in loop till we reah the starting point.   
