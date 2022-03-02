// The include file for GLAD includes the required OpenGL headers behind the scenes (like GL/gl.h)
// , so be sure to include GLAD before other header files that require OpenGL (like GLFW).
#include <glad/gl.h>

#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
constexpr int WIN_WIDTH = 800;
constexpr int WIN_HEIGHT = 600;

int main() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();

    // Window hints need to be set before the creation of the window and context you wish to have
    // the specified attributes. They function as additional arguments to glfwCreateWindow.
    //
    // Some affect the window itself, others affect the framebuffer or context.
    // These hints are set to their default values each time the library is initialized with
    // glfwInit. Integer value hints can be set individually with glfwWindowHint and string value
    // hints with glfwWindowHintString. You can reset all at once to their defaults with
    // glfwDefaultWindowHints.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    // This window object holds all the windowing data and is required by most of GLFW's other
    // functions.
    GLFWwindow *window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Register the callbacks after creating the window and before the render loop is initiated.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    // We pass GLAD the function to load the address of the OpenGL function pointers which is
    // OS-specific. GLFW gives us glfwGetProcAddress that defines the correct function based on
    // which OS we're compiling for.
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        std::cout << "Failed to initialize OpenGL context\n";
        return -1;
    }

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        processInput(window);

        // render
        // ------
        // glClearColor is a state-setting function and glClear is a state-using function.
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Double buffering
        // ------------------
        // The front buffer contains the final output image that is shown at the screen, while all
        // the rendering commands draw to the back buffer. As soon as all the rendering commands
        // are finished we swap the back buffer to the front buffer.
        glfwSwapBuffers(window);

        // Checks if any events are triggered (like keyboard input or mouse movement events),
        // updates the window state, and calls the corresponding functions (which we can register
        // via callback methods).
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react
// accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
// When the window is first displayed framebuffer_size_callback gets called as well.
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    // This function specifies the rendering window respect to the GUI window.
    // It requires 4 coordinates (left, bottom, right and top).
    // The coordinates tell OpenGL how it shoud map its normalized device
    // coordinates (-1 to 1) to window coordinates (specified by the given coordinates).
    glViewport(0, 0, width, height);
}
