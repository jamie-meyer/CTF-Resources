# CTF-Resources

## Background
I TA'd an introductory ethical hacking class that included creating a set of CTF challenges. The following is my own work, but I'll also explain a few challenges we used that are not included here. Feel free to use any and all of the work here, but please credit me. This was easily my favorite part of the semester.

## Usage
If you go into the code for create_key.cpp, you'll need to enter a flag. The flag will then be XOR'ed with some random bits to get two strings that, when XOR'ed together, will create the flag. Use this to input into the final.cpp and morse.cpp challenges to avoid attacks looking for strings and other trivial attacks. Final.cpp creates a challenge that requires the solver to solve 1000 simple math challenges, and morse.cpp requires the solver to translate 10 random morse code strings to letters within 10 seconds. Preferably, the solver will create a script to actually answer the problems, but Ghidra is probably faster if you know what you're doing.

IsItTheFlag.java is a scripting challenge that requires the solver to find the string that was hashed with the java hashcode function. Have them use the rockyou.txt dictionary.

Flag.zip is a deformed zip file that claims to have a few too many bytes dedicated to the name of the file inside. Use zipdetails to figure out what is wrong and a hex editor to fix it.

## Other interesting challenges

We used a ton more challenges including things like zero width character steganography, cracking zips, pdfs, and hashes, embedding locations in Microsoft Word document metadata, cracking cryptograms using frequency analysis, embedding an mp3 of DTMF tones within a picture (my personal favorite), recursively unzipping a zip file over 1000 times, searching for flags within a huge sqlite database, and deciphering various ciphers.
