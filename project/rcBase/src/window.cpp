/*
 *  file    src/window.cpp
 *  date    2011/11/27
 *  author  Azuma_Yoshitaka
 */

#if 0

#include "window.h"

/* ------------------------------- */
namespace rc {
namespace base {
/* ------------------------------- */

/* ========================================================== */
/* static function                                            */
/* ========================================================== */
static IWindowEventListener::EVENT convert_event_sdl_to_rc(u8 event)
{
    return (event == SDL_WINDOWEVENT_SHOWN ) ? IWindowEventListener::EVENT_SHOWN:
    (event == SDL_WINDOWEVENT_HIDDEN       ) ? IWindowEventListener::EVENT_HIDDEN:
    (event == SDL_WINDOWEVENT_EXPOSED      ) ? IWindowEventListener::EVENT_EXPOSED:
    (event == SDL_WINDOWEVENT_MOVED        ) ? IWindowEventListener::EVENT_MOVED:
    (event == SDL_WINDOWEVENT_RESIZED      ) ? IWindowEventListener::EVENT_RESIZED:
    (event == SDL_WINDOWEVENT_SIZE_CHANGED ) ? IWindowEventListener::EVENT_SIZE_CHANGED:
    (event == SDL_WINDOWEVENT_MINIMIZED    ) ? IWindowEventListener::EVENT_MINIMIZED:
    (event == SDL_WINDOWEVENT_MAXIMIZED    ) ? IWindowEventListener::EVENT_MAXIMIZED:
    (event == SDL_WINDOWEVENT_RESTORED     ) ? IWindowEventListener::EVENT_RESTORED:
    (event == SDL_WINDOWEVENT_ENTER        ) ? IWindowEventListener::EVENT_ENTER:
    (event == SDL_WINDOWEVENT_LEAVE        ) ? IWindowEventListener::EVENT_LEAVE:
    (event == SDL_WINDOWEVENT_FOCUS_GAINED ) ? IWindowEventListener::EVENT_FOCUS_GAINED:
    (event == SDL_WINDOWEVENT_FOCUS_LOST   ) ? IWindowEventListener::EVENT_FOCUS_LOST :
    (event == SDL_WINDOWEVENT_CLOSE        ) ? IWindowEventListener::EVENT_CLOSE:
                                               IWindowEventListener::EVENT_NONE;
}



static void notice_window_event(EVENT_LIST *evt_list, u8 evt)
{
    IWindowEventListener::EVENT rc_win_evt = convert_event_sdl_to_rc(evt);
    if ( rc_win_evt == IWindowEventListener::EVENT_NONE )
        return;

    EVENT_LIST_IT it = evt_list->begin();
    while(it != evt_list->end() ) {
        (*it)->event(rc_win_evt);
        ++it;
    }
}

/* 
 *  @class WindowGame
 *  @brief ゲームで使用するウィンドウクラス
 */
WindowGame::WindowGame()
: m_p_window(NULL)
, m_window_id(0)
{
}


WindowGame::~WindowGame()
{
    destroy();
}

bool WindowGame::create(const char* window_name, int width, int height)
{
    // SDL 描画モジュールを初期化
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) { 
        return false;
    }

    // 使用するOpenGLのバージョンを指定
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    /* Turn on double buffering with a 24bit Z buffer.
     * You may need to change this to 16 or 32 for your system */
    // 描画バッファの設定
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    /* Create our window centered at 512x512 resolution */
    m_p_window = SDL_CreateWindow(window_name, 
                                  SDL_WINDOWPOS_CENTERED, 
                                  SDL_WINDOWPOS_CENTERED,
                                  width,
                                  height, 
                                  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!m_p_window) { 
        return false;
    }
    m_window_id = SDL_GetWindowID(m_p_window);

    /* Create our opengl context and attach it to our window */
    m_context = SDL_GL_CreateContext(m_p_window);
    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);
    return true;
}

void WindowGame::destroy()
{
    if ( m_p_window != NULL ) {
        SDL_GL_DeleteContext(m_p_window);
        SDL_DestroyWindow(m_p_window);
        m_p_window = NULL;
    }
}

void WindowGame::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_WINDOWEVENT) {
            notice_window_event(&m_evt_list, event.window.event);
        }
    }
}

void WindowGame::swapBackBuffer()
{
    SDL_GL_SwapWindow(m_p_window);
}

void WindowGame::addEventListener(IWindowEventListener *p_evt)
{
    m_evt_list.push_back(p_evt);
}

/* ------------------------------- */
};	// namespace base
};	// namespace rc
/* ------------------------------- */
#endif
