#include "Ground.h"

Ground::Ground( QOpenGLShaderProgram *program,
                int vertexAttr, int textureAttr,
                int textureUniform ) :
    Plane( program, vertexAttr, textureAttr, textureUniform )
{
    m_texture = new QOpenGLTexture( QImage( ":/Textures/Ice.jpg" ) );
    setTexture( m_texture );
}

Ground::~Ground()
{
    delete m_texture;
}
