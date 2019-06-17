# PriorityQueue-MEX-Matlab
This a mexified MATLAB wrapper of C++ STL priority queue

This priority queue implementation is simple. Nevertheless, it can be used to keep a "sorted" list of arbitrary objects.
Instead of pushing the entire object, we can push only its index.
This is done by first storing the objects in MATLAB as you normally would. Then, you can push the index and its priority into the priority queue.
When you take an element off the priority queue, you can use the index to find the object. This way, the priority queue given here is quite general.

This implementation keeps the priority queue sorted in descending order. In other words, calling the top_value function returns the largest priority value.
You can easily make it operate in ascending order by supplying negative priorities.

## Credits
I am grateful to the authors of the following packages:

1) Example MATLAB class wrapper for a C++ class by Oliver Woodford
https://www.mathworks.com/matlabcentral/fileexchange/38964-example-matlab-class-wrapper-for-a-c-class

2) C++ STL library

## Usage
1) Download or clone this repository to a folder.
2) Run "run_me.m"
3) Star this repository if you found this useful


## Some tips
1) You need to have set a MEX compiler for this to work
2) This was tested in MATLAB 2018b. But, it should work for any recent version of MATLAB.

## Author

**Pradeep Rajendran**

* [github/pradeepr-roboticist](https://github.com/pradeepr-roboticist)

## License

Copyright © 2019 [Pradeep Rajendran](https://github.com/pradeepr-roboticist)
Released under the [GNU General Public License](https://github.com/pradeepr-roboticist/PriorityQueue-MEX-Matlab/blob/master/LICENSE).
