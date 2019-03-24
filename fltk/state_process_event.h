///////////////////////////////////



//////This file did not get used 





















#include <iostream>


    class State {// we have 2 states. searching_for_end or backtracking_to_last_unknown

        public:

        //! Construct an unnamed State
        State(){
        }

        // //! \return The name of the state
        // inline std::string name() { return _name; }

        // //! A method that derived instances should define. It is called when the state is
        // //! entered by the state machine either when the machine starts or when a transition
        // //! to the state is fired.
        // //! \param e The event that led to the transition into the state
        // virtual void entry(const Event& e) = 0;

        // //! A method that derived instances should define. It is called just before the state is
        // //! exited by the state machine when a transition
        // //! from the state is fired.
        // //! \param e The event that led to the transition out of the state        
        // virtual void exit(const Event& e) = 0;


        private:
        std::string name;

    };



//processes during searching_for_end state: checkWalls, chooseDirection, updateState, moveOneBlock, updateMemory, 
//processes during backtracking_to_last_unknown state: moveBackOneBlock, morseBreadthFirstSearch, 
     class Process {

        public:


        //! Default constructor. Names process "no name"
        Process() {}

        // //! Constructor that takes a name for the process
        // /*!
        //   \param name The name of the process
        // */
        // Process(std::string name) : _name(name), _status(UNINITIALIZED), _manager_ptr(NULL) {}

        // // Interface for derived classes

        // //! Initialization method. This method should be overridden by derived
        // //! classes. It will usually be called once, after all processes and
        // //! communication objects have been added to the manager, but before
        // //! the Manager starts running.
        // virtual void init() = 0;

        // //! Start method. This method should be  overridden by derived
        // //! classes. It will be called just before the manager starts running.
        // //! It may be called multiple times, if the manager is started and stopped.
        // virtual void start() = 0;

        // //! Update method. This method should be  overridden by derived
        // //! classes. It will be called repeatedly by the manager at a frequency
        // //! determined by the period used when the process is scheduled with the
        // //! Manager (see Manager::schedule).
        // virtual void update() = 0;

        // //! Stop method. This method should be  overridden by derived
        // //! classes. It will be called just after the manager stops running.
        // //! It may be called multiple times, if the manager is started and stopped.        
        // virtual void stop() = 0;

        // // Inline methods that just replace method calls with their bodies

        // //! Getter
        // //! \return The name of the process.
        // inline string name() { return _name; }

        // //! Getter
        // //! \return The status of the process
        // inline status_type status() { return _status; }

        // //! Getter
        // //! \return The period of the process.
        // inline high_resolution_clock::duration period() { return _period; }

        // //! Getter
        // //! \return The number of updates since the process was last started by the Manager.
        // inline int num_updates() { return _num_updates; }

        // //! Getter
        // //! \return The time the process was last started by the Manager.        
        // inline time_point<high_resolution_clock> start_time() { return _start_time; }

        // //! Getter
        // //! \return The duration of time between the start time and the most recent 
        // //! time the Manager called the update() method.   
        // inline high_resolution_clock::duration last_update() { return _last_update; }

        // //! Getter
        // //! \return The duration of time between the start time and the second most recent 
        // //! time the Manager called the update() method.        
        // inline high_resolution_clock::duration previous_update() { return _previous_update; }

        // // documentation for these methods is in process.cc
        // Channel& channel(string name);
        // double milli_time();
        // double delta();

        // void watch(string event_name, std::function<void(Event&)> handler);
        // void emit(const Event& event);

        // void http_get(std::string url, std::function<void(json&)> handler);

        // private:

        // // Manager interface
        // void _init();
        // void _start(high_resolution_clock::duration elapsed);
        // void _update(high_resolution_clock::duration elapsed);
        // void _stop();

        // // Instance variables
        // string _name;
        // status_type _status;
        // high_resolution_clock::duration _period,          // request time between updates
        //                                 _previous_update, // duration from start to update before last
        //                                 _last_update;     // duration from start to last update
        // time_point<high_resolution_clock> _start_time;    // time of most recent start
        // int _num_updates;                                 // number of times update() has been called
        // Manager * _manager_ptr;                           // a pointer to the manager        

    };

    //! Events that can be emitted, watched, and responded to with event handlers.

    //! Events are constructed with a jsonable value, as in
    //! @code
    //!    Event(3.14);
    //!    Event("hello world");
    //!    Event({1,2,3});
    //! @endcode
    //! See https://github.com/nlohmann/json for details about how to define and manipulated json values.
    class Event {

        public:

        //! Construct a new event
        // //! \param value A json object 
        // Event(std::string name, json value) : _name(name), _value(value), _empty(false), _propagate(true) {}
        // Event(std::string name) : _name(name), _value(0), _empty(true), _propagate(true) {}


        // //! Determine whether the event has no data
        // //! \return Whether the event has no data
        // inline bool empty() const { return _empty; }        

        // //! \return Whether the event has no data
        // inline std::string name() const { return _name; }        

        // //! Determine whether the event will propagate to the next event handler
        // //! \return True or false
        // inline bool propagate() const { return _propagate; }

        // //! Prevent the event from propagating to the next event handler. Typically
        // //! called within an event handler to prevent an subsequent events that
        // //! are watching the same event from firing. See the Manager methods emit() and watch().
        // inline void stop_propagation() { _propagate = false; }

        // //! Turn propagation back on
        // inline void reset() { _propagate = true; }

        // private:
        // json _value;
        // bool _propagate;
        // bool _empty;
        // std::string _name;

    };
