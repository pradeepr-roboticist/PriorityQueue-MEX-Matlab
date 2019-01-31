% File              : run_tests.m
% Author            : Pradeep Rajendran <pradeepunique1989@gmail.com>
% Date              : 06.10.2018
% Last Modified Date: 29.01.2019
% Last Modified By  : Pradeep Rajendran <pradeepunique1989@gmail.com>

clear all;

pq = PriorityQueue();

num_nodes = 1000;
priority_vals = rand(num_nodes, 1);
for nk = 1 : num_nodes
   priority_val = priority_vals(nk);
   pq.push(nk, priority_val);
end

% Test if size command works
pq.size();
size_expected = num_nodes;
size_actual = pq.size();
assert(size_actual == size_expected, 'Sizes do not match');

% Test if top_value, top, pop commands work
while pq.size() > 0
    [top_value_expected, top_id_expected] = max(priority_vals);
    top_value_actual = pq.top_value();
    top_id_actual = pq.top();
    assert(abs(top_value_actual-top_value_expected) < 1e-10, 'Top values do not match');
    pq.pop();
    priority_vals(top_id_expected) = [];
end
clear all;

