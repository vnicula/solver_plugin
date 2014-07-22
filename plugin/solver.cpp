/*
 * solver.cpp
 *
 *  Created on: Jul 21, 2014
 *      Author: Gil
 */

#include "plugin_handler.h"
#include <functional>
#include <map>
#include <algorithm>

class solver : public plugin_handler
{
public:
	solver( )
	{
	}

	void add_cbk( event e, handler_t h, void * )
	{
		cbks_[ e ] = h;
	}

	void set_param( char const *name, double val )
	{
		params_[ name ] = val;
	}

	double get_value( char const *name ) const
	{
		return std::accumulate( params_.begin(), params_.end(), 0.0,
				[](double p , std::pair< std::string, double > p2)->double
				{ return p + p2.second; } );
	}

	void run( )
	{
		cbks_[ event::DATA ]( this, event::DATA, nullptr );
		cbks_[ event::DONE ]( this, event::DONE, nullptr );
	}

	void reset( )
	{
		params_.clear( );
		cbks_[ event::READY ]( this, event::READY, nullptr );
	}

	void quit( )
	{
		should_quit_ = true;
	}

	bool should_quit_ = false;

private:
	std::map< event, handler_t > cbks_;
	std::map< std::string, double > params_;
}; //class solver

int main( )
{
	solver s;
	install( &s );
	s.reset( );
	while ( !s.should_quit_ )
	{
		//sleep( 1 );
		//service( );
	}

}
