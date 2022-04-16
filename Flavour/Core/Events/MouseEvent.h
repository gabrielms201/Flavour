#pragma once

#include "Event.h"
#include <sstream>

/*
MOUSE EVENTS:
	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
*/

namespace Flavour
{
	// Mouse Moved Event : Event
	class API_EXPORTED MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float mouseX, const float mouseY)
			: _mouseX(mouseX), _mouseY(mouseY) {}

		inline float GetX() const { return _mouseX; }
		inline float GetY() const { return _mouseY; }

		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event in position: " << _mouseX << ", " << _mouseY;
			return str.str();
		}

		SET_EVENT_TYPE(MouseMoved)
		SET_EVENT_CATEGORY( MOUSE | INPUT)
	private:
		float _mouseX;
		float _mouseY;
	};

	// Mouse Scrolled Event : Event
	class API_EXPORTED MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: _xOffset(xOffset), _yOffset(yOffset) {}

		inline float GetYOffset() const { return _yOffset; }
		inline float GetXOffset() const { return _xOffset; }

		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event in offset: " << _xOffset << _yOffset;
			return str.str();
		}

		SET_EVENT_TYPE(MouseScrolled)
		SET_EVENT_CATEGORY(MOUSE | MOUSE_BUTTON | INPUT)
	private:
		float _xOffset;
		float _yOffset;
	};

	// Mouse Button Classes;
	typedef struct 
	{
		unsigned short BUTTON_CODE;
		const char* BUTTON_NAME;
	} ButtonIdentifier ;

	// Mouse Button Event : Event
	class API_EXPORTED MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(ButtonIdentifier buttonIdentifier)
			: _buttonIdentifier(buttonIdentifier) {}

		SET_EVENT_CATEGORY(MOUSE | MOUSE_BUTTON | INPUT)
	protected:
		ButtonIdentifier _buttonIdentifier;
	};

	// Mouse Button Pressed Event : Mouse Button Event
	class API_EXPORTED MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(ButtonIdentifier buttonIdentifier)
			: MouseButtonEvent(buttonIdentifier) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event: " << _buttonIdentifier.BUTTON_NAME;
			return str.str();
		}

		SET_EVENT_TYPE(MouseButtonPressed)
	};

	// Mouse Button Release Event : Mouse Button Event
	class API_EXPORTED MouseReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseReleasedEvent(ButtonIdentifier buttonIdentifier)
			: MouseButtonEvent(buttonIdentifier) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << GetName() << "Event: " << _buttonIdentifier.BUTTON_NAME;
			return str.str();
		}

		SET_EVENT_TYPE(MouseButtonPressed)
	};
}
