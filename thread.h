#ifndef _THREAD_H_
#define _THREAD_H_

void RunList(Lista<object>);


template< class Rep, class Period >
void sleep_for( const std::chrono::duration<Rep, Period>& sleep_duration );

#endif