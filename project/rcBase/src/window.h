/*
 *  file    src/window.h
 *  date    2011/11/27
 *  author  Azuma_Yoshitaka
 */

#ifndef _WINDOW_H_INCLUDED_
#define _WINDOW_H_INCLUDED_


#if 0

#include <list>
#include "rcBase.h"

/* ------------------------------- */
namespace rc {
namespace base {
/* ------------------------------- */







/* ------------------------------- */
class IWindowEventListener
/* ------------------------------- */
{
    public:
        typedef enum {
            EVENT_NONE,       
            EVENT_SHOWN,      
            EVENT_HIDDEN,     
            EVENT_EXPOSED,    
            EVENT_MOVED,      
            EVENT_RESIZED,    
            EVENT_SIZE_CHANGED,
            EVENT_MINIMIZED,  
            EVENT_MAXIMIZED,  
            EVENT_RESTORED,   
            EVENT_ENTER,      
            EVENT_LEAVE,      
            EVENT_FOCUS_GAINED,
            EVENT_FOCUS_LOST, 
            EVENT_CLOSE,
        } EVENT;

    public:
        virtual void event(EVENT evt) = 0;
};

typedef std::list<IWindowEventListener*> EVENT_LIST;
typedef EVENT_LIST::iterator             EVENT_LIST_IT;


/* ------------------------------- */
class IWindow
/* ------------------------------- */
{
	public:
		virtual bool create(const char* window_name, int width, int height) = 0;
		virtual void destroy() = 0;

        virtual void update() = 0;

        virtual void addEventListener(IWindowEventListener *p_evt) = 0;
};

/* ------------------------------- */
class IWindowGame : public IWindow
/* ------------------------------- */
{
    public:
		virtual void swapBackBuffer() = 0;
};

/* ------------------------------- */
class WindowGame : public IWindowGame
/* ------------------------------- */
{
	public:
        WindowGame();
        ~WindowGame();

		virtual bool create(const char* window_name, int width, int height);
		virtual void destroy();

        virtual void update();

		virtual void swapBackBuffer();

        virtual void addEventListener(IWindowEventListener *p_evt);

	private:
        u32           m_window_id;
		SDL_Window   *m_p_window;
		SDL_GLContext m_context;

        EVENT_LIST    m_evt_list;
};


/* ------------------------------- */
};	// namespace base
};	// namespace rc
/* ------------------------------- */

#endif

#endif // _WINDOW_H_INCLUDED_
