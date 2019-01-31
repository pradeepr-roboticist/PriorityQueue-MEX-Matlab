% File              : run_me.m
% Author            : Pradeep Rajendran <pradeepunique1989@gmail.com>
% Date              : 06.10.2018
% Last Modified Date: 29.01.2019
% Last Modified By  : Pradeep Rajendran <pradeepunique1989@gmail.com>

classdef PriorityQueue < handle
    properties (Constant)
        NEW_CMD_ID = 0;
        DELETE_CMD_ID = 1;
        PUSH_CMD_ID = 2;
        POP_CMD_ID = 3;
        TOP_CMD_ID = 4;
        SIZE_CMD_ID = 5;
        TOP_VALUE_CMD_ID = 6;
    end
    properties (SetAccess = private, Hidden = true)
        objectHandle; % Handle to the underlying C++ class instance
    end
    methods
        function this = PriorityQueue(varargin)
            this.objectHandle = priority_queue_interface_mex(PriorityQueue.NEW_CMD_ID, varargin{:});
        end

        function delete(this)
            priority_queue_interface_mex(PriorityQueue.DELETE_CMD_ID, this.objectHandle);
        end

        function varargout = push(this, varargin)
            [varargout{1:nargout}] = priority_queue_interface_mex(PriorityQueue.PUSH_CMD_ID, this.objectHandle, varargin{:});
        end

        function varargout = pop(this, varargin)
            [varargout{1:nargout}] = priority_queue_interface_mex(PriorityQueue.POP_CMD_ID, this.objectHandle, varargin{:});
        end

        function varargout = top(this, varargin)
            [varargout{1:nargout}] = priority_queue_interface_mex(PriorityQueue.TOP_CMD_ID, this.objectHandle, varargin{:});
        end

        function varargout = size(this, varargin)
            [varargout{1:nargout}] = priority_queue_interface_mex(PriorityQueue.SIZE_CMD_ID, this.objectHandle, varargin{:});
        end

        function varargout = top_value(this, varargin)
            [varargout{1:nargout}] = priority_queue_interface_mex(PriorityQueue.TOP_VALUE_CMD_ID, this.objectHandle, varargin{:});
        end
    end
end