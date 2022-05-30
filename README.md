# Squiggle Drawing Tool via. Open Frameworks

![Alt text](bin/data/SampleFrame.png?raw=true "Title")

App currently gives user tools to draw/erase/record circles on the screen. Each vertex of each squiggle then has it's radial component updated every frame according to,

![equation](https://latex.codecogs.com/svg.image?dr_i&space;=&space;\theta(\mu_i&space;-&space;r_i)dt&space;&plus;&space;\sigma&space;dW(t))

Where,

![equation](https://latex.codecogs.com/svg.image?\mu_i&space;=&space;\frac{r_{i-1}&plus;r_{i&plus;1}}{2})

So that each point gets a random jiggle that diffuses across the neighboring points. This is a modified stochastic process that overtime drifts to, ![equation](https://latex.codecogs.com/svg.image?r_i=\mu_i) (given its constant, which it isn't).
There is an additional GUI panel that controls, radius, distance between vertices, random coefficient, diffusion coefficient, distance between circles, whether or not to use perspective, and whether or not to pause the circle animation. Mouse also previews current squiggle parameters.


Done using the [Open Frameworks](https://openframeworks.cc/) c++ framework, the OfxGUI add on, and visual studio (2017).

### Classes not included in standard OF project
- Squiggle
  - sets up, updates, and draws each circle while handling the squiggling motion.
- MultiSquig
  - Manages any and all Squiggle instances on screen, has capacity to add squiggles and delete squiggles.