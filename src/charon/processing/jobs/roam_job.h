/**
 * @file roam_job.h
 * 
 * @brief Interface of roam_job_t.
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

#ifndef ROAM_JOB_H_
#define ROAM_JOB_H_

typedef struct roam_job_t roam_job_t;

#include <library.h>
#include <sa/ike_sa_id.h>
#include <processing/jobs/job.h>

/**
 * @brief A job to inform IKE_SAs about changed local address setup.
 * 
 * If a local address appears or disappears, the kernel fires this job to
 * update all IKE_SAs.
 * 
 * @b Constructors:
 * - roam_job_create()
 * 
 * @ingroup jobs
 */
struct roam_job_t {

	/**
	 * implements job_t interface
	 */
	job_t job_interface;
};

/**
 * @brief Creates a job to inform IKE_SAs about an updated address list.
 * 
 * @param address		TRUE if address list changed, FALSE if routing changed
 * @return				initiate_ike_sa_job_t object
 * 
 * @ingroup jobs
 */
roam_job_t *roam_job_create(bool address);

#endif /*ROAM_JOB_H_*/
