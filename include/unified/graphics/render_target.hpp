#ifndef UNIFIED_GRAPHICS_RENDER_TARGET_HPP
#define UNIFIED_GRAPHICS_RENDER_TARGET_HPP

#include <unified/core/color.hpp>
#include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class Drawable;

class RenderTarget
{
public:

    RenderTarget();
    virtual ~RenderTarget() _OSL_NOEXCEPT = default;

    void clear(Color const &color = Color(0, 0, 0, 255)) _OSL_NOEXCEPT;

    void push_gl_states() _OSL_NOEXCEPT;
    void pop_gl_states() _OSL_NOEXCEPT;

    void reset_gl_states() _OSL_NOEXCEPT;

public:

    void draw(Drawable const &buffer) const;

};

UNIFIED_END_NAMESPACE

#endif