/**
 * File              : priority_queue_interface_mex.cpp
 * Author            : Pradeep Rajendran <pradeepunique1989@gmail.com>
 * Date              : 07.10.2018
 * Last Modified Date: 13.11.2018
 * Last Modified By  : Pradeep Rajendran <pradeepunique1989@gmail.com>
 */

#include "mex.h"
#include "class_handle.hpp"

#include <queue>
#include <tuple>
#include <cmath>

#define IDX_ID (0)
#define IDX_PRIORITY_VALUE (1)
using namespace std;

typedef std::tuple<size_t, double> queue_entry;

// Custom comparator for queue_entry
struct queue_entry_comparator
{
    inline bool operator() (const queue_entry &a, const queue_entry &b)
    {
        return (std::get<IDX_PRIORITY_VALUE>(a) < std::get<IDX_PRIORITY_VALUE>(b));
    }
};

// A wrapper for the STL priority queue
class PriorityQueue
{
    priority_queue<queue_entry, std::vector<queue_entry>, queue_entry_comparator > pq;
public:
    void push(const size_t node_id, const double value)
    {
        pq.push(queue_entry(node_id, value));
    };
    double top()
    {
        const queue_entry top_entry = pq.top();
        return std::get<IDX_ID>(top_entry); // extract node_id
    };
    double top_value()
    {
        const queue_entry top_entry = pq.top();
        return std::get<IDX_PRIORITY_VALUE>(top_entry); // return node_id
    };
    void pop()
    {
        pq.pop();
    };
    double size()
    {
        return pq.size();
    }
private:
};

const size_t NEW_CMD_ID = 0;
const size_t DELETE_CMD_ID = 1;
const size_t PUSH_CMD_ID = 2;
const size_t POP_CMD_ID = 3;
const size_t TOP_CMD_ID = 4;
const size_t SIZE_CMD_ID = 5;
const size_t TOP_VALUE_CMD_ID = 6;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{	

	if (nrhs < 1)
    {
		mexErrMsgTxt("First input should be a command id");
    }
    // Get the command id
    const int cmd_id = (const int) mxGetScalar(prhs[0]);
    
    // New
    if ( NEW_CMD_ID == cmd_id ) {
        // Check parameters
        if (nlhs != 1)
            mexErrMsgTxt("New: One output expected.");
        // Return a handle to a new C++ instance
        plhs[0] = convertPtr2Mat<PriorityQueue>(new PriorityQueue);
        return;
    }
    
    // Check there is a second input, which should be the class instance handle
    if (nrhs < 2)
		mexErrMsgTxt("Second input should be a class instance handle.");
    
    // Delete
    if ( DELETE_CMD_ID == cmd_id ) {
        // Destroy the C++ object
        destroyObject<PriorityQueue>(prhs[1]);
        // Warn if other commands were ignored
        if (nlhs != 0 || nrhs != 2)
            mexWarnMsgTxt("Delete: Unexpected arguments ignored.");
        return;
    }
    
    // Get the class instance pointer from the second input
    PriorityQueue *pq_instance = convertMat2Ptr<PriorityQueue>(prhs[1]);
    
    // Call the various class methods
    if ( PUSH_CMD_ID == cmd_id ) {
        // Check parameters
        if (nlhs < 0 || nrhs < 4)
        {
            mexErrMsgTxt("Push: Unexpected arguments");
        }
        const size_t node_id = static_cast<size_t>(mxGetScalar(prhs[2]));
        const double priority_value = mxGetScalar(prhs[3]);
        pq_instance->push(node_id, priority_value);
        return;
    }
    // Test    
    if ( POP_CMD_ID == cmd_id ) {
        // Check parameters
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Pop: Unexpected arguments.");
        pq_instance->pop();
        return;
    }
    if ( TOP_CMD_ID == cmd_id ) {
        // Check parameters
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Top: Unexpected arguments.");
        const double value = pq_instance->top();
        if (nlhs == 1)
        {
            plhs[0] = mxCreateDoubleScalar(value);
        }
        return;
    }
    if ( SIZE_CMD_ID == cmd_id ) {
        // Check parameters
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Size: Unexpected arguments.");
        const double value = pq_instance->size();
        if (nlhs == 1)
        {
            plhs[0] = mxCreateDoubleScalar(value);
        }
        return;
    }
    if ( TOP_VALUE_CMD_ID == cmd_id ) {
        // Check parameters
        if (nlhs < 0 || nrhs < 2)
            mexErrMsgTxt("Top Value: Unexpected arguments.");
        const double value = pq_instance->top_value();
        if (nlhs == 1)
        {
            plhs[0] = mxCreateDoubleScalar(value);
        }
        return;
    }
    mexErrMsgTxt("Command not recognized.");
}
