#include <iostream>
#include <GLFW/glfw3.h>

extern "C"
{
  static void glfw_error(int code, const char *msg)
  {
    fprintf(stderr, "Error<%d>: %s.", code, msg);
  }
}

const int WINDOW_WIDTH = 400, WINDOW_HEIGHT = 400;

int main(int, const char*[])
{
  glfwSetErrorCallback(glfw_error);
  if(glfwInit() < 0) fprintf(stderr, "Error<glfwInit>: Unknow");

  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "GLFW - Window", NULL, NULL);
  if(!window) glfwTerminate();
  glfwMakeContextCurrent(window);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(-50., 50., -50., 50., 1., -1.);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.f, 1.f, 1.f);
    glBegin(GL_QUADS);
      glVertex3f(-10.f, 10.f, 0.f);
      glVertex3f(10.f, 10.f, 0.f);
      glVertex3f(10.f, -10.f, 0.f);
      glVertex3f(-10.f, -10.f, 0.f);
    glEnd();

    glfwSwapBuffers(window);
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}
