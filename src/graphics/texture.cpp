#include <unified/graphics/texture.hpp>
#include <unified/core/exceptions.hpp>

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

Texture::Texture(string image, bool flip) {
    stbi_set_flip_vertically_on_load(static_cast<int>(flip));

    auto buffer = stbi_load(image.c_str(), &_width, &_height, &_channels, 4);

    if (!buffer)
        throw Exceptions::misbehavior("failed to load image");

    generate_texture(_id, 1, buffer);

    stbi_image_free(buffer);
}

Texture::Texture(u8 *data, u32 size, bool flip) {
    stbi_set_flip_vertically_on_load(static_cast<int>(flip));

    auto buffer = stbi_load_from_memory(data, static_cast<int>(size), &_width, &_height, &_channels, 4);

    if (!buffer)
        throw Exceptions::misbehavior("failed to load image");

    generate_texture(_id, 1, buffer);

    stbi_image_free(buffer);
}

Texture::~Texture() {
    glDeleteTextures(1, &_id);
}

Texture::HandleType Texture::handle() const {
    return _id;
}

void Texture::bind(const Texture *texture, SlotType slot) {
    if (!texture)
        throw Exceptions::misbehavior("bad " UNIFIED_GRAPHICS_NAMESPACE_STRING "::Texture pointer");

    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture->handle());
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture *Texture::ScopeBind::current = 0;

Texture::ScopeBind::ScopeBind(const Texture *texture) {
    if (current && (current->handle() == texture->handle())) {
        _prev = 0;
        return;
    }

    _prev = current;
    current = const_cast<Texture*>(texture);;

    bind(texture);
}

Texture::ScopeBind::~ScopeBind() {
    if (_prev) {
        bind(_prev);
        current = _prev;
    }
}

Texture::HandleType Texture::generate_texture(HandleType &id, u32 size, u8 *buffer) {
    glGenTextures(static_cast<GLsizei>(size), &id);

    Texture::ScopeBind texture_bind(this);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

    return id;
}

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE
