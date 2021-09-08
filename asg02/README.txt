CPSC 1020 - Section 300
Mike Brandin

BRIEF DESCRIPTION:
Two instances of pgm_t classes are declared in main. The first, "mandrill.pgm"
exists in the directory and thus copies the image data using ifstream operations.
The second, gray.pgm does not exist yet, so all that is assigned to the class is
the file name. A copy of the original pgm_t type is then created using ofstream
operations. Using a copy assignment= operator the cpy pgm_t instance which held
no image data then copies the image data from the org pgm_t instance. An output
stream with the name "gray.pgm" from the second line of code, then copies the cpy
pmg_t type to the corresponding file now storing image data.


LESSONS LEARNED:
Through completing this assignment I gained a deeper understanding of fstream
operation and how they can be used with overloading operators to create an
image copying successful program. I also cemented my understanding of overloaded
operators by having multiple functions and the main driver call these operators.
I also utilized the skills of reusing previous code in order to convert a C
language program to a C++ language program. Lastly, I had the opportunity to use
"The Big Three" to work in tandem with one another and gain additional usability.

SPECIAL USAGE INSTRUCTIONS:
Though my program did not require the utilization of a copy constructor, I left
a commented out example in main to confirm it works.
