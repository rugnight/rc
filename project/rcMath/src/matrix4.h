/*
 * matrix4.h 
 * 2012年 2月18日 土曜日 16時51分24秒 JST
 */

#ifndef _RC_MATRIX4_H_
#define _RC_MATRIX4_H_


namespace rc {
namespace math { 

class matrix4
{
    public:

    public:
        union 
        {
            struct {
            };
            struct {
            };
            MATRIX4_TYPE v[16];
        };
};


}; //namespace math
}; //namespace rc


#endif//_RC_MATRIX4_H_
