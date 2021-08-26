//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int heigth);
//void processInput(GLFWwindow* window);
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource1 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\0";
//
//const char* fragmentShaderSource2 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"	FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
//"}\0";
//
//int main() {
//	// OpenGL Initialization
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//	//============================================
//
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
//	unsigned int fragmentShaderRed = glCreateShader(GL_FRAGMENT_SHADER);
//	unsigned int shaderProgramOrange = glCreateProgram();
//	unsigned int shaderProgramRed = glCreateProgram();
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	// Vertex Shader Compilation Logging
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	glShaderSource(fragmentShaderOrange, 1, &fragmentShaderSource1, NULL);
//	glCompileShader(fragmentShaderOrange);
//	// Fragment Shader Orange Compilation Logging
//	glGetShaderiv(fragmentShaderOrange, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	glShaderSource(fragmentShaderRed, 1, &fragmentShaderSource2, NULL);
//	glCompileShader(fragmentShaderRed);
//	// Fragment Shader Yellow Compilation Logging
//	glGetShaderiv(fragmentShaderRed, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShaderRed, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	glAttachShader(shaderProgramOrange, vertexShader);
//	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//	glLinkProgram(shaderProgramOrange);
//	// Linking Shader Program Orange Logging
//	glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgramOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	glAttachShader(shaderProgramRed, vertexShader);
//	glAttachShader(shaderProgramRed, fragmentShaderRed);
//	glLinkProgram(shaderProgramRed);
//	// Linking Shader Program Orange Logging
//	glGetProgramiv(shaderProgramRed, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgramRed, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//
//	// Memory cleanup
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShaderOrange);
//	glDeleteShader(fragmentShaderRed);
//
//	float firstTriangle[] = {
//		-0.9f, -0.5f, 0.0f,
//		-0.0f, -0.5f, 0.0f,
//		-0.45f, 0.5f, 0.0f,
//	};
//	float secondTriangle[] = {
//		0.0f, -0.5f, 0.0f,
//		0.9f, -0.5f, 0.0f,
//		0.45f, 0.5f, 0.0f
//	};
//	unsigned int VBOs[2], VAOs[2];
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	// first triangle
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	//second triangle
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgramOrange);
//		// first triangle
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		// second triangle
//		glUseProgram(shaderProgramRed);
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int heigth) {
//	glViewport(0, 0, 800, 600);
//}
//
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}