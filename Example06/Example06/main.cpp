
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

GLuint VBO, VAO, EBO;
GLuint VAOs[2], VBOs[2];

GLuint shaderProgram;
GLuint shaderProgram_Rad;


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
	//glfwSetMouseButtonCallback(window, );

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


	//DrawTriangle_Initialize();
	Exp_CreateShader();
	//drawTriangle_Buffer();
	//DrawTriangle_IndexBuffer();
	Exp_drawTriangleBuffer();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/*检查事件;*/
		glfwPollEvents();

		// Clear the colorbuffer;
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		/*渲染代码;*/
		//drawTriangle();
		//DrawTriangle_Index_drawTriangle();
		//Exp_drawTriangle();
		Exp_Shader_drawTriangle();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	// Properly de-allocate all resources once they've outlived their purpose

	//drawTriangle_DeleteVOA();
	//DrawTriangle_Index_DeleteVOA();
	Exp_DeleteVOA();

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}

/*初始化;*/
void DrawTriangle_Initialize()
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

}

/*绑定顶点对象;*/
void drawTriangle_Buffer()
{
	/*vertices*/
	GLfloat vertices[] =
	{
		/*draw one triangle*/
		//-0.5f,-0.5f,0.0f,
		//0.5f,-0.5f,0.0f,
		//0.0f, 0.5f,0.5f

		/*draw two triangle*/
		-0.5f,-0.5f,0.0f,
		 0.0f,-0.5f,0.0f,
		-0.25f,0.5f,0.0f,

		0.0f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.25f,0.5f,0.0f

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

/*绘制;*/
void drawTriangle()
{
	// Draw our first triangle
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);

	//glDrawArrays(GL_TRIANGLES, 0, 3);
	/*draw two triangle*/
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);


}

void drawTriangle_DeleteVOA()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}


void DrawTriangle_IndexBuffer()
{
	/*vertices*/
	GLfloat vertices[] =
	{
		0.5f, 0.5f,0.5f,
		0.5f,-0.5f,0.0f,
		-0.5f,-0.5f,0.0f,
		-0.5f, 0.5f,0.5f
	};

	GLuint indices[] =
	{
		0,1,3,
		1,2,3
	};

	/*创建索引缓冲对象;*/

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	/*绑定顶点数组对象;*/
glBindVertexArray(VAO);

	/*将顶点数组复制到顶点缓冲中，供OpenGL使用;*/
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/*将索引数组赋值到索引缓冲中;*/
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/*设置顶点属性指针;*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	
	/*解绑VAO;*/
glBindVertexArray(0);

}

void DrawTriangle_Index_drawTriangle()
{
	// Draw our first triangle
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void DrawTriangle_Index_DeleteVOA()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}


/*练习;*/
void Exp_drawTriangleBuffer()
{
	/*vertices*/
	GLfloat Fristvertices[] =
	{
		-0.5f,-0.5f,0.0f,
		0.0f,-0.5f,0.0f,
		-0.25f,0.5f,0.0f,

	};

	GLfloat Secondvertices[] =
	{
		0.0f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.25f, 0.5f, 0.0f
	};

/*创建VAO,创建缓存;*/
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);


/*绑定VAO*/
glBindVertexArray(VAOs[0]);
	/*将顶点数据绑定到顶点对象中;*/
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Fristvertices), Fristvertices, GL_STATIC_DRAW);
	/*设置顶点数据解析格式;*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
glBindVertexArray(0);


glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Secondvertices), Secondvertices, GL_STATIC_DRAW);
	/*设置顶点属性指针;*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
glBindVertexArray(0);


}

void Exp_drawTriangle()
{
	// Draw our first triangle
	glUseProgram(shaderProgram);

	glBindVertexArray(VAOs[0]);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, 3); 
	glBindVertexArray(0);

	glBindVertexArray(VAOs[1]);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

}

void Exp_DeleteVOA()
{
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);

	//glDeleteVertexArrays(1, &FristVAO);
	//glDeleteVertexArrays(1, &SecondVAO);

	//glDeleteBuffers(1, &FristVBO);
	//glDeleteBuffers(1, &SecondVBO);

}


/*使用两个作色器;*/
void Exp_CreateShader()
{
	/*顶点作色器;*/
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";

	/*片段作色器;*/
	const GLchar* fragmentShaderSourceOranger = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	const GLchar* fragmentShaderSourceYellow = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
		"}\n\0";


/*创建作色器 顶点;*/
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
/*创建片段作色器;*/
	GLuint fragmentShadeOranger = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint fragmentShader_Yellow = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);/*绑定作色器源码;*/
	glCompileShader(vertexShader);/*编译作色器源码;*/

	glShaderSource(fragmentShadeOranger, 1, &fragmentShaderSourceOranger, NULL);
	glCompileShader(fragmentShadeOranger);

	/*创建片段作色器;*/
	glShaderSource(fragmentShader_Yellow, 1, &fragmentShaderSourceYellow, NULL);
	glCompileShader(fragmentShader_Yellow);

	//GLuint shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShadeOranger);
	glLinkProgram(shaderProgram);

	shaderProgram_Rad=glCreateProgram();
	glAttachShader(shaderProgram_Rad, vertexShader);
	glAttachShader(shaderProgram_Rad, fragmentShader_Yellow);
	glLinkProgram(shaderProgram_Rad);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShadeOranger);
	glDeleteShader(fragmentShader_Yellow);

}

void Exp_Shader_drawTriangle()
{

	glUseProgram(shaderProgram);
	glBindVertexArray(VAOs[0]);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glUseProgram(shaderProgram_Rad);
	glBindVertexArray(VAOs[1]);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

}

// Is called whenever a key is pressed/released via GLFW    
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}