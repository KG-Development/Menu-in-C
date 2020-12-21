1. Copy the Files in the Files Ordner in your Project

2. Go into Code::Blocks and Right-Click your Project and Click ADD FILES...

3. Select the myconio.c, myconio.h, menu.h, menu.c files

4. Make a Cross at Debug and Release and press OK

5. Now we can inlclude the file write:
#include "menu.h"
#include "myconio.h"

6. in the main write:
TMenu menu = {0}; 

to init a menu;

At least your main should like this:

#include "menu.h"
#include "myconio.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	TMenu menu = {0};
	
}
==============
Read the function text file to learn how to use this header.
Now have fun
