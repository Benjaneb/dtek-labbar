## Which lines of code had to be changed? Why?
Line 14 had to be changed to using 3 instead of 1 as it was the incrementation made when stepping through the ASCII characters.
Line 16 also had to be changed to 0x5d instead of 0x5b as 0x5b was skipped when incrementing with 3, unlike 0x5d.