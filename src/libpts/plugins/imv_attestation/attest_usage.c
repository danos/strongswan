/*
 * Copyright (C) 2011 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
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

#include <stdio.h>

#include "attest_usage.h"

/**
 * print attest usage info
 */
void usage(void)
{
	printf("\
Usage:\n\
  ipsec attest --files|--products|--keys|--hashes [options]\n\
  \n\
  ipsec attest --components|-keys|--measurements|--add|--del [options]\n\
  \n\
  ipsec attest --files [--product <name>|--pid <id>]\n\
    Show a list of files with a software product name or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --products [--file <path>|--fid <id>]\n\
    Show a list of supported software products with a file path or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --hashes [--sha1|--sha256|--sha384] [--product <name>|--pid <id>]\n\
    Show a list of measurement hashes for a given software product or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --hashes [--sha1|--sha256|--sha384] [--file <path>|--fid <id>]\n\
    Show a list of measurement hashes for a given file or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --components [--key <digest>|--kid <id>]\n\
    Show a list of components with an AIK digest or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --keys [--components <cfn>|--cid <id>]\n\
    Show a list of AIK key digests with a component or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --measurements [--sha1|--sha256|--sha384] [--component <cfn>|--cid <id>]\n\
    Show a list of component measurements for a given component or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --measurements [--sha1|--sha256|--sha384] [--key <digest>|--kid <id>|--aik <path>]\n\
    Show a list of component measurements for a given AIK or\n\
    its primary key as an optional selector.\n\
  \n\
  ipsec attest --add --file <path>|--dir <path>|--product <name>|--component <cfn>\n\
    Add a file, directory, product or component entry\n\
    Component <cfn> entries must be of the form <vendor_id>/<name>-<qualifier>\n\
  \n\
  ipsec attest --add [--owner <name>] --key <digest>|--aik <path>\n\
    Add an AIK public key digest entry preceded by an optional owner name\n\
  \n\
  ipsec attest --del --file <path>|--fid <id>|--dir <path>|--did <id>\n\
    Delete a file or directory entry referenced either by value or primary key\n\
  \n\
  ipsec attest --del --product <name>|--pid <id>|--component <cfn>|--cid <id>\n\
    Delete a product or component entry referenced either by value or primary key\n\
  \n\
  ipsec attest --del --key <digest>|--kid <id>|--aik <path>\n\
    Delete an AIK entry referenced either by value or primary key\n\
  \n");
}

