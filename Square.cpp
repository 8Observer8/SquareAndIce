#include "Square.h"

Square::Square( QOpenGLShaderProgram *program,
                int vertexAttr, int textureAttr,
                int textureUniform ) :
    Plane( program, vertexAttr, textureAttr, textureUniform ),
    m_direction( Square::Up )
{
    m_texture = new QOpenGLTexture( QImage( ":/Textures/Blocks.jpg" ) );

    setTexture( m_texture );
}

Square::~Square()
{
    delete m_texture;
}

Square::Direction Square::direction() const
{
    return m_direction;
}

void Square::setDirection( Square::Direction dir )
{
    m_direction = dir;
}
