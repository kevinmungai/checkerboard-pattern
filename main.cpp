/*
	The Code Below is used to develop a Checker Board Pattern.

	1. Start with Identifying the First Square
	2. Put in the coordinates for the First Square
	3. Create a for-loop to to create squares at the same time
	4. Introduce a variable to help keep track of the color. Using an IF Statement.
	5. Introduce an outer for-loop to cater for the y - axis.
*/


//#include <windows.h>  for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h




/* Initialize OpenGL Graphics */

void initGL() {

// Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    //initialize the variables.
    GLint x = 50;
    GLint y = 50;
    GLint colorCode = 1;

    for(y = 50; y <= 350; y += 50) {

        for(x = 50; x <= 350; x += 50) {

            //helps toggle the color.
            if (colorCode == 1) {
                glColor3f(0.0, 0.0, 0.0);
                colorCode = 0;
            }
            else {
                glColor3f(1.0, 1.0, 1.0);
                colorCode = 1;
            }

            //identify the first square
            glBegin(GL_QUADS);
            glVertex2i(x, y);
            glVertex2i(x, y + 50);
            glVertex2i(x + 50, y + 50);
            glVertex2i(x + 50, y);
            glEnd();

        }

    }


    glFlush(); // Render now
}




/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow("Understandable Checkers"); // Create window with the given title
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register callback handler for window re-paint event
    initGL(); // Our own OpenGL initialization
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}