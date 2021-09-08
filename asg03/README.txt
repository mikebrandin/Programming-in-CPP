CPSC 1020- Section 300
Mike Brandin

BRIEF DESCRIPTION:

The pgm header is almost identical as from asg02, though I add the forward declaration of
the ppm_t class and the copy constructor function with a ppm_t type parameter which 
changes the name and calculates the gray, aswell as setting the rest of the image info.
In the ppm header, I inherit most from the base class, pgm_t, and add the rpix and gpix
data types aswell as the proper constructors, destructor, getters, setters, and operators.
I update the read and write operators to repeat 3 times per iteration for the rpix, gpix,
and bpix.

LESSONS LEARNED:
Through completing this assignment I learned how how derived and base classes work with
one another to complete a task.  In this case, allowing the base class to use derived class
objects through a forward declaration of the class. I also learned how to use the c++ 
string find() and replace() operations to convert a ppm filename to a pgm filename.



