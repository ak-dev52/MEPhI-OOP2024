/*!
\file
\bref Operating functions header file

This file contains the definitions of operating functions.
It is used to clean up the code and make it easier to read.

*/
#ifndef LIB_H
#define LIB_H
#include "rlib.h"
/*!
Checks if a string contains a subword, 
case insensitive using std::strig parameters
\param const std::string &subword word to find in the line
\param const std::string &temp_line line in which to search for the word
\return boolean value weather the line contains a subword, 
case insensitive or not
*/
bool in_check(const std::string &subword, const std::string &temp_line);

/*!
Reads the file line by line while there is no no eof 
or any problems in reading from file. Calls in_check() 
that receives const std::string parameters 
to check weather to print this line or not and prints line 
if in_check() returns true. Uses std::string parameter
\param std::ifstream &file source file from which to read
\param const std::string &word word which to find in the file 
lines, case insensitive
\throws std::runtime_error if occurs any 
problems with reading the file
*/
void cycle(std::ifstream &file, const std::string &word);

/*!
Checks if a string contains a subword, 
case insensitive using const char* parameters
\param const char *c_subword word to find in the line
\param const char *c_temp_line line in which to search fo the word
\return boolean value weather the line contains a subword, 
case insensitive or not
*/
bool in_check(const char *c_subword, const char *c_temp_line);

/*!
Reads the file line by line while there is no no eof 
or any problems in reading from file. Calls in_check() 
that uses const char* parameters
to check weather to print this line or not and prints line 
if in_check() returns true. Uses const char* parameter
\param std::ifstream &file source file from which to read
\param const std::string &word word which to find in the file 
lines, case insensitive
\throws std::runtime_error if occurs any 
problems with reading the file
*/
void cycle(std::ifstream &file, const char *c_subword);


#endif
