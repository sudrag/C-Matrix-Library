# Matrix Operations
## Overview
The objective of this project was to design a matrix library that performs multiplication and transposition functions. The library works in such a way that both the input and output matrices need to be initialized . The matrices are intialized as vector of vectors. The matrix that is to be output from functions , need not have any values provided to the vectors but must be constructed.

Example code on how to use the library has been included in the cpp file src/demo.cpp. The example code depicts how the code works for integer. Since it uses a template the functions can work with INT, FLOAT and DOUBLE s as well. To do so , change all ints to float or double in the demo file to develop your own code 

The functions are written using templates and can accept any input data type for the matrix.

## How to build and run the tests
* To build:
```
mkdir build
cd build
cmake ..
make
```
* Run the tests:
```
cd build
./test/matrix-test
```
To use these functions in your own code. Add the include directory path to the compiler debugging. Include to the start of your code and call the functions:
* To use:
```
#include "matrix_functions.hpp" 
```

## Doxygen Documentation
To generate Doxygen Documentation in HTML and LaTEX, follow the next steps:

```
cd matrix_operation
mkdir <documentation_folder_name>
cd <documentation_folder_name>
doxygen -g <config_file_name>
```
Inside the configuration file, update:
```
PROJECT_NAME = 'your project name'
INPUT = ../LaneDetector ../include ../test
```
Run and generate the documents by running the next command:
```
doxygen <config_file_name>
```
All these steps have already been performed in this project.

To view the documents easily, access `classMatrix.html`, `test_8cpp.html` and `demo_8cpp.html` with your browser.

## License

MIT License

Copyright (c) 2018 Sudarshan Raghunathan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

