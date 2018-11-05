# StdThreadSample
A simple timer which implement by C++11 std::thread.

## Note
### joinable()
Thread is "unjoinable" before it is created or after joined, i.e., thread.joinalbe()=0.
### join()
0. mThread.join() will block current main thread and wait mThread is return.
0. You can not join a thread twice. Since the second thread you join is another thread which created after the first join, it will lead to undefined behavior.
### detach()
mThread.detach() do not care what mthread return, nor block and wait mThread finish.
It just detach it and mThread will become an orphan and take care by system.