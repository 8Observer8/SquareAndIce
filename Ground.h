#ifndef GROUND_H
#define GROUND_H

#include "Plane.h"

class Ground : public Plane
{
public:
    Ground( QOpenGLShaderProgram *program,
            int vertexAttr, int textureAttr,
            int textureUniform );
    ~Ground();

private:
    QOpenGLTexture *m_texture;
};

#endif // GROUND_H
