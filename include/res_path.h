#ifndef _RES_PATH_H
#define _RES_PATH_H

#include <string>

/**
 * Get the resource path for resoures located under "res/"
 * assuming the project directory has its binaries under "bin/".
 *
 * @return        Absolute path in UTF-8 encoding to "res/"
 */
std::string getResourcePath();

#endif
