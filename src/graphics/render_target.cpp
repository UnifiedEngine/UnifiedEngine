#include <unified/graphics/render_target.hpp>
#include <unified/core/exceptions.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

RenderTarget::RenderTarget() {
    if (!gladLoadGL())
        throw Exceptions::initialization_failed("failed to initialize glad");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RenderTarget::clear(const Color &color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderTarget::draw(const Drawable &object, const Shader *shader) const {
    object.draw(*this, shader);
}

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE
