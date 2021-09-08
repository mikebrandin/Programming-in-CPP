CPSC 1020- Section 300
Mike Brandin

BRIEF DESCRIPTION:
The img struct pointer is sent to a read function which takes the header information and 
puts the info into an array. Allocation function is lastly called which initalizes 
variables and allocates memory for all pixels in the original image. The Write function 
then creates a new header given the existing information and loops pixel by pixel to 
output the float color values to the image.  PPM and PGM images use basically the same 
solution, except the PPM requires 3 bytes to be allocated, read, and written instead of 1.

LESSONS LEARNED:
Through completing this assignment I learned how the fread and fwrite functions worked,
previously having used fprintf and fscanf to complete a similar problem. I also learned 
how to use a char* pointer as a string by allocating memory to the component then using
strcpy().


