#ifndef SQUARE_H
#define SQUARE_H

#include "Plane.h"

class Square : public Plane
{
public:
    Square( QOpenGLShaderProgram *program,
            int vertexAttr, int textureAttr,
            int textureUniform );
    ~Square();

    enum Direction { Left, Up, Right, Down };

    Direction direction() const;
    void setDirection( Direction dir );

private:
    Direction m_direction;
    QOpenGLTexture *m_texture;
};

#endif // SQUARE_H
