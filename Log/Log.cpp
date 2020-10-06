#include "pch.h"

#include "Log.h"
#include "CommonUtil.h"

#include <cstdarg>
#include <fstream>

using namespace std;
using namespace algorithm;

string Log::logFileName = getNowDateStr() + string(".log");

Log::Log(const std::string & level, const std::string & file,
	const int & line, const std::string & methodName, const char * format, ...)
	: Log(level, file, line, methodName, string())
{
	va_list args;
	char msg[4096];
	va_start(args, format);
	vsnprintf(msg, 4096, format, args);
	va_end(args);
	this->msg = msg;
}

Log::Log(const string & level, const std::string& file,const int& line, 
	const std::string& methodName, const std::string& msg)
	: level(level), line(line), methodName(methodName), msg(msg)
{
	this->file = getRelativePath(file);
	this->time = getNowTimeStr();
}

void Log::writeToFile()
{
	ofstream stream(logFileName, ios::app);

	stream << this->time << " ";
	stream << "[" << this->level << "] ";
	stream << "(" << this->file << ":" << this->line << ") ";
	stream << "<" << this->methodName << "> ";
	stream << this->msg << endl;

	stream.close();
}