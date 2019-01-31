% File              : run_me.m
% Author            : Pradeep Rajendran <pradeepunique1989@gmail.com>
% Date              : 06.10.2018
% Last Modified Date: 29.01.2019
% Last Modified By  : Pradeep Rajendran <pradeepunique1989@gmail.com>

%% Compile MEX code
run compile_priority_queue.m
run run_tests
%% Usage
% Instantiate priority queue
pq = PriorityQueue();

% Let's push a few numbers and their corresponding IDs
% The IDs have to be unsigned integers. 0,1,2,3,... are fine.
pq.push(1, 31);
pq.push(2, 35);
pq.push(3, 200);
pq.push(4, -1);
pq.push(5, 53);

top_value = pq.top_value(); % Take a peek at the top of the queue. This should be 200
top_id = pq.top(); % Get the ID of the top value. This should be 3

pq.pop(); % Pop (remove) the top

top_value = pq.top_value(); % Get the next top value. This should be 53 now.
top_id = pq.top(); %  Get the next top ID. This should be 5 now.

size = pq.size(); % Get the size of queue. This should be 4 now.