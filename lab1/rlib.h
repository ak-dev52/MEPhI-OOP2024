/*!
\file
\bref Input of string and integer functions header file

This file contains the definitions of functions 
to input of string and integer functions.
It is used to clean up the code and make it easier to read.

*/
#ifndef RLIB_H
#define RLIB_H


#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <limits>

template<typename T>
/*!
Tries to read a template T from cin. If there is no problems 
in reading returns true, if there is a problem in reading 
but not critical return false. If there is a critical problem 
in reading throws an exception
\param T &str object to write data from cin to
\return boolean value wheather data was successfully read
(if there is no critical problem)
\throws std::rutime_error if there is no 
critical problem while reading
*/
bool try_read(T &str);

/*!
Calls try_read() while it is not true, 
returns read by try_read() data
\return std::string res read by try_read() data
*/
std::string sread();

/*!
In cycle do-while prints prompt to enter an integer 
inside an interval and calls try_read() in another cycle 
while it is returns false, while try_read() input integer 
is not in written interval
\param int min lower limit of the interval
\param int max upper limit of the interval
return int res read integer in the interval
*/
int int_input(int min, int max);

/*!
Gives user options how to represent input data:
C-style string or std::string
\return boolean value wheather to represent
input as std::string or not
*/
bool menu();

/*!
Prints a prompt for a word, calls a function to read
and returns a copy of input word in char* format using
to_char function to return the word from std::cin
\param std::string &word a line in which to write the entered word
\return char *word a line in which to write the entered word
*/
char *subword_input(std::string &word);

/*!
Prints a prompt for a file name to open and calls a function
that checks whether the file exists and is accessible
\param std::ifstream &file source file
*/
void file_input(std::ifstream &file);

/*!
Checks whether the file exists and is accessible
\param std::ifstream &file file to check
\param const std::string &filename name of file to check
\throw std::runtime_error if there is a problem in opening file
*/
void file_is_OK(std::ifstream &file, const std::string &filename);

/*!
Makes a copy of std::string in char* format
\param std::string s source string
\return char* res copy of s
\throw std::bad_alloc if there is a lack of memory
*/
char *to_char(std::string s);


#endif
