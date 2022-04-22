#pragma once

#include "stdafx.h"

namespace Flavour
{
	enum class EventType
	{
		None = 0,

		// Window
		WindowMove,
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		// App
		AppRender,
		AppTick,
		AppUpdate,
		AppCrash,

		// Key
		KeyPressed,
		KeyReleased,
		KeyTyped,

		// Mouse
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		NONE			=  0,
		APPLICATION		= (1 << 0), // 0
		INPUT			= (1 << 1), // 1
		KEYBOARD		= (1 << 2), // 2
		MOUSE			= (1 << 3), // 3
		MOUSE_BUTTON	= (1 << 4)  // 4
	};

	class API_EXPORTED Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool MatchCategory (const EventCategory category) const { return GetCategoryFlags() & category; }
	protected:
		bool _handled = false;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event) : _event(event) {}

		template<typename T>
		bool Dispatch(std::function<bool(T&)> function)
		{
			if (_event.GetType() == T::GetStaticType())
			{
				_event._handled = function(*(T*)&_event);
				return true;
			}
			return false;
		}

	private:
		Event& _event;
	};

	inline std::ostream& operator<<(std::ostream& str, const Event& event)
	{
		return str << event.ToString();
	}

// ---> Event Category && Event Type Macros
#define SET_EVENT_CATEGORY(eventCategory) \
	virtual int GetCategoryFlags() const override { return eventCategory; }
#define SET_EVENT_TYPE(eventType) \
	static EventType GetStaticType() { return EventType::eventType; } \
	virtual EventType GetType() const override { return GetStaticType(); } \
	virtual const char* GetName() const override { return #eventType; }
// <---
}


