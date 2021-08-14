#include "headers.hpp"
#include "ventana.hpp"

/*smart pointer for GLFWwindow* instance */
std::shared_ptr<const char*> Ventana::nombre = std::make_shared<const char*>("defualt");
std::shared_ptr<GLFWwindow*> Ventana::ventana = std::make_shared<GLFWwindow*>(nullptr);
/*window size and name*/
GLuint Ventana::alto = 640, Ventana::ancho = 480;  
Ventana::Ventana(const char* name) { *nombre = std::move(name); }

/* main control func*/
void Ventana::init()
{
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: al iniciar glfw");
		glfwTerminate();
	}
	glfwSetErrorCallback(Ventana::error_callback); 		 	/* set the callback func */

	*ventana = glfwCreateWindow(alto, ancho, *nombre, NULL, NULL); /* create it */

	if (!ventana)
	{
		fprintf(stderr, "ERROR al crear la ventana");
		glfwTerminate();  		  /* end of glfw */
	}
	/* set key controller and main context*/
	glfwSetKeyCallback(*ventana, key_callback);
	glfwMakeContextCurrent(*ventana);         /*set main context in "ventana" -> smart pointer (GLWFwindow*)*/
	glfwSwapInterval(1);                      /*intervar for swap it */

	while (!glfwWindowShouldClose(*ventana))
	{
        /* main loop*/

		glfwSwapBuffers(*ventana);

		glfwPollEvents();         /*  to control the window this is important!*/
	}

	glfwDestroyWindow(*ventana); 
}


/*create the callback func */
void Ventana::error_callback(int error, const char* msg) {  
	fprintf(stderr, "ERROR: %s ", msg); 
}

void Ventana::key_callback(GLFWwindow* target, int key, int scancode, int actions, int mods)
{
	if (key == GLFW_KEY_ESCAPE && actions == GLFW_PRESS) {
		glfwSetWindowShouldClose(target, GLFW_TRUE);        /* close window if escape is pressed*/
	}
}
