
#include <GLFW\glfw3.h>

typedef unsigned char boolean;
#define TRUE  1
#define FALSE 0

#define WINDOW_HEIGHT   720 
#define WINDOW_WIDTH    1280

#define RECTANGLE_HEIGHT    75.0f
#define RECTANGLE_WIDTH     75.0f

static float x = 3.5f;
static float y = 1.5f;
static boolean up    = TRUE;
static boolean right = TRUE;

static void draw
    (
    void
    );
static void update_position
    (
    void
    );

int main( int argc, char *argv[] )
{
    GLFWwindow* window;

    /*
    Initialize library
    */
    if( !glfwInit() ) {
        return( -1 );
        }

    /*
    Create a windowed mode window and its OpenGL context
    */
    window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL );
    if( !window ) {
        glfwTerminate();
        return( -1 );
        }

    /*
    Make the window's context current
    */
    glfwMakeContextCurrent( window );

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        update_position();
        draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);



        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return( 0 );
}

/*
*
*   update_position()
*
*
*/
static void update_position
    (
    void
    )
{

if( right 
 && ( x+1+RECTANGLE_WIDTH >= WINDOW_WIDTH ) )
    {
    right = FALSE;
    }
else if( !right 
      && ( x-1 <= 0.0f ) ) 
    {
    right = TRUE;
    }

if( up
 && ( y+1+RECTANGLE_HEIGHT >= WINDOW_HEIGHT ) )
    {
    up = FALSE;
    }
else if( !up
      && ( y-1 <= 0.0f ) )
    {
    up = TRUE;
    }

if( up )
    {
    y++;
    }
else
    {
    y--;
    }

if( right )
    {
    x++;
    }
else
    {
    x--;
    }

}

/*
*
*   draw()
*
*
*/
static void draw
    (
    void
    )
{
glLoadIdentity();

glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
glClear( GL_COLOR_BUFFER_BIT );
    
glColor4f( 1.0, 1.0, 1.0, 0.0 );
glOrtho( 0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -1.0, 1.0 );
glBegin( GL_POLYGON );
        glVertex3f( x,                   y,                    0.0 );
        glVertex3f( x + RECTANGLE_WIDTH, y,                    0.0 );
        glVertex3f( x + RECTANGLE_WIDTH, y + RECTANGLE_HEIGHT, 0.0 );
        glVertex3f( x,                   y + RECTANGLE_HEIGHT, 0.0 );
glEnd();
glFlush();

}