#ifndef PLANE_H
#define PLANE_H

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <vector>

class Plane
{
public:
    Plane( QOpenGLShaderProgram *program,
           int vertexAttr,
           int textureAttr,
           int textureUniform );
    ~Plane();

    void draw();

    void setX0( float x );
    void setY0( float y );

    float x0() const;
    float y0() const;

    void setSize( float size );
    float size() const;

    void setTexture( QOpenGLTexture *texture );

private:
    void initVertices();
    void initTextureCoords();

    std::vector<float> m_vertices;
    std::vector<float> m_textureCoords;

    QOpenGLShaderProgram *m_program;
    QOpenGLTexture *m_texture;
    int m_vertexAttr;
    int m_textureAttr;
    int m_textureUniform;

    float m_x0;
    float m_y0;
    float m_size;
};

#endif // PLANE_H
