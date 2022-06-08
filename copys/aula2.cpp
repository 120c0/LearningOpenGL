#include <iostream>
#include <GLFW/glfw3.h>

extern "C"
{
  static void GLFW_error_output(int code, const char *msg)
  {
    fprintf(stderr, "Error<%d>: %s\n", code, msg);
    exit(EXIT_FAILURE);
  }
}

int main(int, const char*[])
{
  glfwSetErrorCallback(GLFW_error_output);
  if(glfwInit() < 0) exit(EXIT_FAILURE);

  GLFWwindow *window = glfwCreateWindow(300, 300, "GLFW - Window", NULL, NULL);
  if(!window) glfwTerminate();
  glfwMakeContextCurrent(window);

  glClearColor(0.2, 0.2, 0.2, 1.);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1., 1., 1.);
    glBegin(GL_TRIANGLES);
      glVertex3f(0.f, 0.5f, 0.f);
      glVertex3f(-0.5f, -0.5f, 0.f);
      glVertex3f(0.5f, -0.5f, 0.f);
    glEnd();

    glfwSwapBuffers(window);
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}
