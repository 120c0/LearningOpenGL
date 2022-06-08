#include <iostream>
#include <GLFW/glfw3.h>

// export code C
extern "C"
{
  void callback_error_ouput(int code, const char *msg)
  {
    fprintf(stderr, "Error<GLFW>: %s. exit code %d", msg, code);
    exit(code);
  }
}

int main(int, char *const[])
{
  glfwSetErrorCallback(callback_error_ouput);
  if(glfwInit() < 0)
  {
    exit(-1);
  }
  GLFWwindow *window = glfwCreateWindow(480, 480, "My first GLFW Window", NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    exit(-1);
  }
  glfwMakeContextCurrent(window);

  std::cout << "Company: " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "Model: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

  glClearColor(1., 1., 1., 1.);
  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return EXIT_SUCCESS;
}
