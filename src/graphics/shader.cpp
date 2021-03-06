#include <unified/graphics/shader.hpp>
#include <unified/core/exceptions.hpp>

#include <unified/core/math/matrix.hpp>
#include <unified/core/math/point2.hpp>
#include <unified/core/math/point3.hpp>
#include <unified/core/math/point4.hpp>

#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

Shader::Shader() : _id(0) { }

Shader::Shader(const char *vertex_shader, const char *fragment_shader) {
    compile(vertex_shader, fragment_shader);
}

Shader::~Shader() {
    if (_id)
        free();
}

void Shader::create(const char *vertex_shader, const char *fragment_shader) {
    if (_id)
        free();
    compile(vertex_shader, fragment_shader);
}

UNIFIED_NODISCARD Shader::HandleType Shader::handle() const {
    return _id;
}

void Shader::set_int(const char *name, int value) {
    glUniform1i(glGetUniformLocation(_id, name), value);
}

void Shader::set_int2(const char *name, const int *value) {
    glUniform2i(glGetUniformLocation(_id, name), value[0], value[1]);
}

void Shader::set_int3(const char *name, const int *value) {
    glUniform3i(glGetUniformLocation(_id, name), value[0], value[1], value[2]);
}

void Shader::set_int4(const char *name, const int *value) {
    glUniform4i(glGetUniformLocation(_id, name), value[0], value[1], value[2], value[3]);
}

void Shader::set_int2(const char *name, const Point<int, 2> &value) {
    glUniform2i(glGetUniformLocation(_id, name), value.x, value.y);
}

void Shader::set_int3(const char *name, const Point<int, 3> &value) {
    glUniform3i(glGetUniformLocation(_id, name), value.x, value.y, value.z);
}

void Shader::set_int4(const char *name, const Point<int, 4> &value) {
    glUniform4i(glGetUniformLocation(_id, name), value.x, value.y, value.z, value.w);
}

void Shader::set_float(const char *name, float value) {
    glUniform1f(glGetUniformLocation(_id, name), value);
}

void Shader::set_float2(const char *name, const float *value) {
    glUniform2f(glGetUniformLocation(_id, name), value[0], value[1]);
}

void Shader::set_float3(const char *name, const float *value) {
    glUniform3f(glGetUniformLocation(_id, name), value[0], value[1], value[2]);
}

void Shader::set_float4(const char *name, const float *value) {
    glUniform4f(glGetUniformLocation(_id, name), value[0], value[1], value[2], value[3]);
}

void Shader::set_float2(const char *name, const Point<float, 2> &value) {
    glUniform2f(glGetUniformLocation(_id, name), value.x, value.y);
}

void Shader::set_float3(const char *name, const Point<float, 3> &value) {
    glUniform3f(glGetUniformLocation(_id, name), value.x, value.y, value.z);
}

void Shader::set_float4(const char *name, const Point<float, 4> &value) {
    glUniform4f(glGetUniformLocation(_id, name), value.x, value.y, value.z, value.w);
}

void Shader::set_double(const char *name, double value) {
    glUniform1d(glGetUniformLocation(_id, name), value);
}

void Shader::set_double2(const char *name, const double *value) {
    glUniform2d(glGetUniformLocation(_id, name), value[0], value[1]);
}

void Shader::set_double3(const char *name, const double *value) {
    glUniform3d(glGetUniformLocation(_id, name), value[0], value[1], value[2]);
}

void Shader::set_double4(const char *name, const double *value) {
    glUniform4d(glGetUniformLocation(_id, name), value[0], value[1], value[2], value[3]);
}

void Shader::set_double2(const char *name, const Point<double, 2> &value) {
    glUniform2d(glGetUniformLocation(_id, name), value.x, value.y);
}

void Shader::set_double3(const char *name, const Point<double, 3> &value) {
    glUniform3d(glGetUniformLocation(_id, name), value.x, value.y, value.z);
}

void Shader::set_double4(const char *name, const Point<double, 4> &value) {
    glUniform4d(glGetUniformLocation(_id, name), value.x, value.y, value.z, value.w);
}

void Shader::set_float3x3(const char *name, float *value) {
    glUniformMatrix3fv(glGetUniformLocation(_id, name), 1, GL_FALSE, value);
}

void Shader::set_float4x4(const char *name, float *value) {
    glUniformMatrix4fv(glGetUniformLocation(_id, name), 1, GL_FALSE, value);
}

void Shader::set_float3x3(const char *name, const Matrix<float, 3, 3> &value) {
    glUniformMatrix3fv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::set_float4x4(const char *name, const Matrix<float, 4, 4> &value) {
    glUniformMatrix4fv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::set_double3x3(const char *name, const double *value) {
    glUniformMatrix3dv(glGetUniformLocation(_id, name), 1, GL_FALSE, value);
}

void Shader::set_double4x4(const char *name, const double *value) {
    glUniformMatrix4dv(glGetUniformLocation(_id, name), 1, GL_FALSE, value);
}

void Shader::set_double3x3(const char *name, const Matrix<double, 3, 3> &value) {
    glUniformMatrix3dv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::set_double4x4(const char *name, const Matrix<double, 4, 4> &value) {
    glUniformMatrix4dv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::compile(const char *vertex_shader, const char *fragment_shader) {
    GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader_id, 1, &vertex_shader, 0);
    glCompileShader(vertex_shader_id);
    throw_if_error(vertex_shader_id, GL_COMPILE_STATUS);

    GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader_id, 1, &fragment_shader, 0);
    glCompileShader(fragment_shader_id);
    throw_if_error(fragment_shader_id, GL_COMPILE_STATUS);

    _id = glCreateProgram();
    glAttachShader(_id, vertex_shader_id);
    glAttachShader(_id, fragment_shader_id);
    glLinkProgram(_id);
    throw_if_error(_id, GL_LINK_STATUS);
}

void Shader::free()  {
    glDeleteProgram(_id);
}

void Shader::throw_if_error(u32 id, u32 type) {
    GLint ok = 0;
    switch (type) {
        case(GL_LINK_STATUS): {
            glGetProgramiv(id, GL_LINK_STATUS, &ok);
            if (ok == GL_FALSE) {
                GLint size;
                glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &size);

                string error;
                error.resize(size);

                glGetProgramInfoLog(_id, size, 0, (GLchar*)error.data());

                throw Exceptions::initialization_failed(error.c_str());
            }
            break;
        }

        default: {
            glGetShaderiv(id, type, &ok);
            if (ok == GL_FALSE) {
                GLint size;
                glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &size);

                string error;
                error.resize(size);

                glGetShaderInfoLog(_id, size, 0, (GLchar*)error.data());

                throw Exceptions::initialization_failed(error.c_str());
            }
            break;
        }
    }
}

void Shader::bind(const Shader *shader) {
    if (!shader)
        throw Exceptions::misbehavior("bad " UNIFIED_GRAPHICS_NAMESPACE_STRING "::Shader pointer");

    glUseProgram(shader->handle());
}

void Shader::unbind() {
    glUseProgram(0);
}

Shader *Shader::ScopeBind::current = 0;

Shader::ScopeBind::ScopeBind(const Shader *shader) {
    if (current && (current->handle() == shader->handle())) {
        _prev = 0;
        return;
    }

    _prev = current;
    current = const_cast<Shader*>(shader);

    bind(shader);
}

Shader::ScopeBind::~ScopeBind() {
    if (_prev) {
        bind(_prev);
        current = _prev;
    }
}

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE
