/**
 * @file auth_controller.h
 * 
 * @brief Interface of auth_controller_t.
 * 
 */

/*
 * Copyright (C) 2007 Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#ifndef AUTH_CONTROLLER_H_
#define AUTH_CONTROLLER_H_


#include <controller.h>

typedef struct auth_controller_t auth_controller_t;

/**
 * @brief Authentication controller.
 */
struct auth_controller_t {

	/**
	 * Implements controller_t interface.
	 */
	controller_t controller;
};

/**
 * @brief Create a auth_controller controller instance.
 */
controller_t *auth_controller_create(context_t *context, void *param);

#endif /* AUTH_CONTROLLER_H_ */