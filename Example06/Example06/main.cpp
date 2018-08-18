
#include <iostream>    
// GLEW    
//#define GLEW_STATIC    
//#include <GL/glew.h>    
//
//// GLFW    
//#include <GLFW/glfw3.h> 

#include "main.h"

//#ifdef _MSC_VER//隐藏控制台;
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
//#endif


// Window dimensions    
//const GLuint WIDTH = 800, HEIGHT = 600;
//static float dis = 0.0;
//static int  nRot = 0;
//
float rotateX = 20.0f;
float rotateY = 30.0f;

// The MAIN function, from here we start the application and run the game loop    
int main(void)
{
	GLFWwindow* window;

	glfwInit();

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	drawTriangle_Buffer();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/*检查事件;*/
		glfwPollEvents();

		drawTriangle();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}


// Is called whenever a key is pressed/released via GLFW    
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

GLuint VBO, VAO;
GLuint shaderProgram;

void drawTriangle_Buffer()
{
	/*绑定作色器语言;*/

	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";

	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	/*作色器语言;*/
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	/*给作色器绑定源码;*/
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// Check for compile time errors

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// Check for compile time errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	/*GLuint shaderProgram*/shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// Check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	/*vertices*/
	GLfloat vertices[] =
	{
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f, 0.5f,0.5f
	};


	//GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

}


void drawTriangle()
{
	// Clear the colorbuffer;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw our first triangle
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);


}








void drawPoint()
{
	/* Draw a point */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(2.0f);
	glBegin(GL_POINTS);

	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.5f, 0.8f);
	glEnd();
}

void drawcure()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex2f(-0.50f, -0.50f);
	glVertex2f(0.50f,-0.50f);
	glVertex2f(0.50f, 0.50f);
	glVertex2f(-0.50f, 0.50f);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.50f, -0.50f,0.0f);
	glVertex3f(0.50f, -0.50f, 0.0f);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, 0.0f, 0.5f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex3f(0.50f, -0.50f, 0.0f);
	glVertex3f(0.50f, 0.50f, 0.0f);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, 0.0f, 0.5f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex3f(0.50f, 0.50f, 0.0f);
	glVertex3f(-0.50f, 0.50f, 0.0f);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, 0.0f, 0.5f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex3f(-0.50f, 0.50f, 0.0f);
	glVertex3f(-0.50f, -0.50f, 0.0f);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, 0.0f, 0.5f);
	glEnd();

}

void cube()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// 立方体的8个顶点坐标;
	GLfloat vertex_list[][3] = {
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,
	};

	GLint index_list[][4] = {
		0, 2, 3, 1,
		0, 4, 6, 2,
		0, 1, 5, 4,
		4, 5, 7, 6,
		1, 3, 7, 5,
		2, 6, 7, 3,
	};

#if 0
	// 只有正面，并且只显示边线，不进行填充;
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif

	// 设置旋转;
	glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotateY, 0.0f, 1.0f, 0.0f);

	// 定义不同的颜色;
	GLfloat colors[][3] = { { 0.0, 0.0, 1.0 },{ 0.0, 1.0, 0.0 },{ 1.0, 0.0, 0.0 },
	{ 1.0, 0.0, 1.0 },{ 1.0, 1.0, 0.0 },{ 0.0, 1.0, 1.0 },
	{ 1.0, 0.5, 0.5 },{ 0.0, 0.5, 0.5 } };

	int i, j;

	glBegin(GL_QUADS); // 绘制四边形;
	for (i = 0; i < 6; ++i)         // 有六个面，循环六次;
	{
		glColor3f(colors[i][0], colors[i][1], colors[i][2]);
		for (j = 0; j < 4; ++j)     // 每个面有四个顶点，循环四次;
		{
			glVertex3fv(vertex_list[index_list[i][j]]);
		}
	}
	glEnd();

	//glutSwapBuffers();
}