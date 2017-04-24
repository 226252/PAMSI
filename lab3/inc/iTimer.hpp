#ifndef itimer_HPP
#define itimer_HPP

class iTimer 
{
	virtual void begin()=0;
	virtual void stop()=0;
	virtual void duration_out()=0;
	virtual float duration()=0;
};
#endif