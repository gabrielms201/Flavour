#pragma once

#include "Event.h"
#include <sstream>

/*
APP EVENTS:
	AppRender,
	AppTick,
	AppUpdate,
	AppCrash,
WINDOW EVENTS:
	WindowMove,
	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMoved,
*/

namespace Flavour
{
	// ------> APP EVENTS

	// App Render Event : Event
	class API_EXPORTED AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(AppRender)

	};

	// App Tick Event : Event
	class API_EXPORTED AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(AppTick)
	};

	// App Update Event : Event
	class API_EXPORTED AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(AppUpdate)
	};

	// App Crash Event : Event 
	class API_EXPORTED AppCrashEvent : public Event
	{
	public:
		AppCrashEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(AppCrash)
	};

	// ------> WINDOW EVENTS

	// Window Move Event : Event
	class API_EXPORTED WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(WindowMove)
	};

	// Window Close Event : Event
	class API_EXPORTED WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(WindowClose)
	};

	// Window Resize Event : Event
	class API_EXPORTED WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height){}

		unsigned int GetWidth() const { return _width; }
		unsigned int GetHeight() const { return _height; }

		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event :" << _width << ", " << _height;
			return str.str();
		}

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(WindowResize)
	private:
		unsigned int _width;
		unsigned int _height; 
	};

	// Window Focus Event : Event
	class API_EXPORTED WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(WindowFocus)
	};

	// Window Lost Focus Event : Event
	class API_EXPORTED WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(WindowLostFocus)
	};

	// Window Moved Event : Event
	class API_EXPORTED WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent() = default;

		SET_EVENT_CATEGORY(APPLICATION)
		SET_EVENT_TYPE(WindowMoved)
	private:

	};

}
