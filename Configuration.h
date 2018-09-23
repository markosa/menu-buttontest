/*
 * Configuration.h
 *
 *  Created on: Sep 22, 2018
 *      Author: markos
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#define DEBUG 1
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)


#define MENU_MAX_NODES 10



#endif /* CONFIGURATION_H_ */
