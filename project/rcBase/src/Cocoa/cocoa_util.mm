/*
 *  file    project/rcBase/src/Cocoa/cocoa_util.mm
 *  date    2012年 5月19日 土曜日 15時43分50秒 JST
 *
 */

#include "cocoa_util.h"

#ifdef RC_USE_XCODE_COCOA_FRAMEWORK

#import <Cocoa/Cocoa.h>

static std::string to_c_char(NSString *string)
{
	return [string cStringUsingEncoding:NSUTF8StringEncoding];
}

namespace rc {
namespace base {

std::string get_work_directory()
{
	return to_c_char([[NSFileManager defaultManager] currentDirectoryPath]);
}

std::string get_resource_path(const char* file_name, const char* file_ext)
{
	NSString* name = [NSString stringWithCString: file_name encoding:NSUTF8StringEncoding];
	NSString* ext  = [NSString stringWithCString: file_ext  encoding:NSUTF8StringEncoding];

    NSBundle* bundle = [NSBundle mainBundle];
    NSString* path = [bundle pathForResource:name ofType:ext];
	return to_c_char(path);
}

}//namespace rc {
}//namespace base {

#endif//RC_USE_XCODE_COCOA_FRAMEWORK
