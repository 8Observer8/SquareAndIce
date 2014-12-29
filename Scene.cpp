#include <QMatrix4x4>
#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent )
{
    setFocusPolicy( Qt::StrongFocus );

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotMove() ) );

    m_timer.start( 0 );
}

Scene::~Scene()
{
    makeCurrent();
    delete m_square;
    delete m_ground;
    doneCurrent();
}

void Scene::initializeGL()
{
    glClearColor( 0.1f, 0.1f, 0.2f, 1.0f );

    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vShader.glsl" );

    QOpenGLShader fShader( QOpenGLShader::Fragment );
    fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

    m_program.addShader( &vShader );
    m_program.addShader( &fShader );
    if ( !m_program.link() )
    {
        qWarning( "Error: unable to link a shader program." );
        return;
    }

    m_vertexAttr = m_program.attributeLocation( "vertexAttr" );
    m_textureAttr = m_program.attributeLocation( "textureAttr" );
    m_textureUniform = m_program.uniformLocation( "textureUniform" );
    m_matrixUniform = m_program.uniformLocation( "matrix" );

    m_square = new Square( &m_program, m_vertexAttr, m_textureAttr,
                           m_textureUniform );

    m_ground = new Ground( &m_program, m_vertexAttr, m_textureAttr,
                           m_textureUniform );
    m_ground->setX0( m_ground->x0() - 1.5f );
    m_ground->setY0( m_ground->y0() - 1.5f );
    m_ground->setSize( 4.0f );
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );

    if ( !m_program.bind() )
        return;

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    QMatrix4x4 matrix;
    matrix.ortho( -2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f );
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_ground->draw();
    m_square->draw();

    m_program.release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

void Scene::slotMove()
{
    const float step = 0.001f;

    switch ( m_square->direction() )
    {
        case Square::Up:
            m_square->setY0( m_square->y0() + step );
            break;
        case Square::Left:
            m_square->setX0( m_square->x0() - step );
            break;
        case Square::Right:
            m_square->setX0( m_square->x0() + step );
            break;
        case Square::Down:
            m_square->setY0( m_square->y0() - step );
            break;
    }

    update();
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
        case Qt::Key_Up:
            m_square->setDirection( Square::Up );
            break;
        case Qt::Key_Left:
            m_square->setDirection( Square::Left );
            break;
        case Qt::Key_Right:
            m_square->setDirection( Square::Right );
            break;
        case Qt::Key_Down:
            m_square->setDirection( Square::Down );
            break;
    }

    update();
}
