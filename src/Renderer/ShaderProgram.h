#pragma once

#include <glad/glad.h>
#include <string>

namespace Renderer {
	class ShaderProgram
	{
	public:
		
		ShaderProgram(const std::string& vertexSader, const std::string& fragmentSader);
		~ShaderProgram();

		bool isCompiled() const { return m_isCompiled; }
		void use() const;

		//Запреты
		ShaderProgram() = delete;
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator = (const ShaderProgram&) = delete;
		ShaderProgram& operator = (ShaderProgram&& shaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept;


	private:
		bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderId);

		bool m_isCompiled;
		GLuint m_ID = 0;
	};
}
