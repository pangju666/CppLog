#pragma once

#include <string>

#define ERROR_LOG(format, ...) Log("ERROR", __FILE__, __LINE__,  __func__, format, __VA_ARGS__).writeToFile()
#define WARN_LOG(format, ...) Log("WARN", __FILE__, __LINE__,  __func__, format, __VA_ARGS__).writeToFile()
#define INFO_LOG(format, ...) Log("INFO", __FILE__, __LINE__,  __func__, format, __VA_ARGS__).writeToFile()
#define DEBUG_LOG(format, ...) Log("DEBUG", __FILE__, __LINE__,  __func__, format, __VA_ARGS__).writeToFile()
#define LOG(level, msg) Log(level, __FILE__, __LINE__,  __func__, msg).writeToFile()

class Log  final
	{
	public:
		Log(const std::string& level, const std::string& file, const int& line, const std::string& methodName, const char* format, ...);
		Log(const std::string& level, const std::string& file, const int& line, const std::string& methodName, const std::string& msg);

	public:
		void writeToFile();

	private:
		std::string time;
		std::string level;
		std::string file;
		int line;
		std::string methodName;
		std::string msg;

	private:
		static std::string logFileName;
};