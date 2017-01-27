#ifndef INCLUDED_SEMAPHORE_
#define INCLUDED_SEMAPHORE_

#include <functional>
#include <mutex>
#include <condition_variable>

class Semaphore
{
    mutable std::mutex d_mutex;
    std::condition_variable d_condition;
    size_t d_nAvailable;

 public:
    Semaphore(size_t nAvailable);

    template <typename T>
	bool wait(T fun)
    {
	std::unique_lock<std::mutex> lk(d_mutex);

	while (d_nAvailable == 0)
	    d_condition.wait(lk);   

	if (d_nAvailable == 1 && not fun(d_nAvailable))
	    return false;

	--d_nAvailable;

	return true;
    };
	
    void notify_all();  
    size_t size() const;
};

#endif

