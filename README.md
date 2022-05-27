# Squiggle Drawing Tool via. Open Frameworks

App currently lets user trace out a path with the mouse and then draw circles along those paths. The squiggle effect is done by updating the radial component of each circle with,

![equation](https://latex.codecogs.com/svg.image?dr_i&space;=&space;\theta(\mu&space;-&space;r_i)&space;&plus;&space;\sigma&space;dW(t))

Where,

![equation](https://latex.codecogs.com/svg.image?\mu&space;=&space;\frac{r_{i-1}&plus;r_{i&plus;1}}{2})

So that each point gets a random jiggle, that over time drifts to the average radius of the neighboring points. This lets the circles stay at approximatley the same radius and lets the jiggle of points effect their neighbors almost in a diffusive way. There are also other small things like, the radius being scaled by the y-coordinate to add perspective, and trying to place circles (roughly) equidistant.

Done using the [Open Frameworks](https://openframeworks.cc/) c++ framework in visual studio.

### Classes not included in standard OF project
- Squiggle
  - sets up, updates, and draws each circle while handling the squiggling motion.
- MultiSquig
  - Takes in a set of points (assumed to be a path traced by mouse) and automaticly makes Squiggles along the path