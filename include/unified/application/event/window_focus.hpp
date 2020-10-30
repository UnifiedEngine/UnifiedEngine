#ifndef UNIFIED_APPLICATION_EVENT_WINDOW_FOCUS_HPP
#define UNIFIED_APPLICATION_EVENT_WINDOW_FOCUS_HPP

#include <unified/defines.hpp>
#include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowFocusEvent : public Event
{
public:

    WindowFocusEvent(int focused) _OSL_NOEXCEPT;

    _OSL_NODISCARD virtual string get_name() const;
    _OSL_NODISCARD virtual Type get_type() const;

    _OSL_NODISCARD static Type get_type_static() {
        return Type::WindowFocus;
    }

    const bool focused;

};

UNIFIED_END_NAMESPACE

#endif