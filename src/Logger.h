#include<iostream>
#include<string>
#include<fstream>

#define BUFFER_SIZE 80
#define DEBUG_ON 1
using namespace std;
 
class Logger {
public:
	void info(const std::string message);
	void error(const std::string message);
	std::string getLogPreString();
	void setDebugMode(int mode);
private:
	int m_debugMode;
	int getDebugMode();
	void printDebugMessage(string message);
};

/**
 * Get the log time.
*/
std::string Logger::getLogPreString() {
	time_t now;
	struct tm *ptr;
	char buf[BUFFER_SIZE];
	time(&now);
	ptr = localtime(&now);
	strftime(buf, BUFFER_SIZE, "%x %I:%M:%S |", ptr);
	
	if(this->getDebugMode()== DEBUG_ON) {
		this->printDebugMessage(buf);
	}
	return buf;
}

/**
 * @author kim kiogora <kim.kiogora@gmail.com>
 * @param  message
*/
void Logger::info(const std::string message) {
	std::string buf = getLogPreString();	
	ofstream infolog_stream("info.log",ios::out|ios::app);
	infolog_stream <<buf<<"INFO|"<<message << endl;
	if(this->getDebugMode()==DEBUG_ON) {
		this->printDebugMessage(message);
	}
}

/**
 * @author kim kiogora <kim.kiogora@gmail.com>
 * @param  message
*/
void Logger::error(const std::string message) {
	string buf = getLogPreString();
	ofstream errorlog_stream("error.log",ios::out|ios::app);
	errorlog_stream << buf<<"ERROR|"<< message << endl;
	if(this->getDebugMode()==true) {
		this->printDebugMessage(message);
	}
}

void Logger::setDebugMode(int mode) {
	m_debugMode = mode;
}

int Logger::getDebugMode() {
	return m_debugMode;
}

void Logger::printDebugMessage(string message) {
	cout<<this->getLogPreString()<<message<<endl;
} 
