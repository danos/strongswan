/*
 * Copyright (C) 2013 Tobias Brunner
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

/**
 * @defgroup sshky_public_key sshky_public_key
 * @{ @ingroup sshkey_p
 */

#ifndef SSHKEY_BUILDER_H_
#define SSHKEY_BUILDER_H_

#include <credentials/builder.h>
#include <credentials/keys/public_key.h>

typedef struct sshkey_public_key_t sshkey_public_key_t;

/**
 * Public key implementation supporting RFC 4253 decoding.
 */
struct sshkey_public_key_t {

	/**
	 * Implements public_key_t interface.
	 */
	public_key_t interface;
};

/**
 * Load a public key in RFC 4253 format.
 *
 * Takes a BUILD_BLOB_SSHKEY to parse the public key.
 *
 * @param type		type of the key, must be KEY_ANY
 * @param args		builder_part_t argument list
 * @return 			built key, NULL on failure
 */
sshkey_public_key_t *sshkey_public_key_load(key_type_t type, va_list args);

#endif /** SSHKEY_BUILDER_H_ @}*/
