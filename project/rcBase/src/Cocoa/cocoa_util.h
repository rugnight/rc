/*
 *  file    project/rcBase/src/Cocoa/cocoa_util.h
 *  date    2012年 5月19日 土曜日 15時43分50秒 JST
 *
 */

#ifndef _RC_COCOA_UTIL_H_
#define _RC_COCOA_UTIL_H_

#include "../rc_base.h"

#ifdef RC_USE_XCODE_COCOA_FRAMEWORK
namespace rc {
namespace base {

std::string get_work_directory();
std::string get_resource_path(const char* file_name, const char* file_ext);
//std::string to_c_char(NSString *string);

}//namespace rc {
}//namespace base {
#endif//RC_USE_XCODE_COCOA_FRAMEWORK

#endif//_RC_COCOA_UTIL_H_
