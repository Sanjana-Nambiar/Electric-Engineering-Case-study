#ifndef GRAPH_H
#define GRAPH_H

# include <GL/glew.h>
# include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int Graph(double x1, double y1, double x2, double y2)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CURRENT POSE OF THE ROBOT CHAIN", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glMatrixMode(GL_PROJECTION);
    // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glLoadIdentity();
    // essentially set coordinate system
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glMatrixMode(GL_MODELVIEW);
    // same as above comment
    glLoadIdentity();

    GLfloat lineVertices[] =
    {
        x1, y1, 0,
        x2, y2, 0
    };

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        // glEnable(GL_LINE_STIPPLE);
        glPushAttrib(GL_LINE_BIT);
        glLineWidth(10);
        // glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, lineVertices);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPopAttrib();
        // glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
#endif

