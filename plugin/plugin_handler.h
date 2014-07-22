/*
 * plugin_handler.h
 *
 *  Created on: Jul 21, 2014
 *      Author: Gil
 */

#ifndef PLUGIN_HANDLER_H_
#define PLUGIN_HANDLER_H_

class plugin_handler
{
public:
	enum event { READY, DATA, DONE };

	typedef void (*handler_t)( plugin_handler *, event , void * );

	virtual ~plugin_handler( ) { }

	virtual void add_cbk( event e, handler_t h, void *data ) = 0;

	virtual void set_param( char const *, double ) = 0;

	virtual double get_value( char const * ) const = 0;

	virtual void run( ) = 0;

	virtual void reset( ) = 0;

	virtual void quit( ) = 0;

}; //class plugin_handler

extern "C" void install( plugin_handler * );

extern "C" void service( );

#endif /* PLUGIN_HANDLER_H_ */
