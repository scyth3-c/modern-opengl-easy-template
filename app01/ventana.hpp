#ifndef VENTANA_HPP
#define VENTANA_HPP

#include "headers.hpp"

class Ventana {

protected:

	static std::shared_ptr<const char*>nombre;  			/* window name */
	static std::shared_ptr<GLFWwindow*> ventana; 			/* GLFWwindow* instance */
	static GLuint alto, ancho; 					/* window size and name */

public:

	Ventana(const char*);					 	/* constructor whith window just the name */
	static void init();  				 	 	/*this in main.cpp is so important  */
	static void error_callback(int, const char*); 	          	/*control funcs */
	static void key_callback(GLFWwindow*, int, int, int, int);	/*control funcs */

};

#endif // !VENTANA_HPP


