/*
 * eval_node.cpp
 *
 *  Created on: Jul 21, 2014
 *      Author: Gil
 */

#include "plugin_handler.h"
#include <iostream>

class plugin
{
public:
	static void ready( plugin_handler *h, plugin_handler::event e, void *data )
	{
		std::cout << "handling READY\n";
		h->set_param( "a", 1 );
		h->set_param( "b", 1 );
		h->run( );
	}

	static void data( plugin_handler *h, plugin_handler::event e, void *data )
	{
		std::cout << "handling DATA\n";
	}

	static void done( plugin_handler *h, plugin_handler::event e, void *data )
	{
		std::cout << "handling DONE\n";
		std::cout << "value: " << h->get_value( nullptr );
		h->quit( );
	}
}; //class plugin

void install( plugin_handler *h )
{
	if ( h )
	{
		h->add_cbk( plugin_handler::event::READY, &plugin::ready, nullptr );
		h->add_cbk( plugin_handler::event::DATA, &plugin::data, nullptr );
		h->add_cbk( plugin_handler::event::DONE, &plugin::done, nullptr );
	}
}

