//File Writer header file

#pragma once

#include <string>
#include <map>

class FileWriter
{
public:
	FileWriter();
	~FileWriter();

	bool Initialize(std::string &directory); //bool FileWriter::Initialize(std::string &directory)

	void AddData(std::string &key, int &value);
	void WriteToFile(std::string &filename);

private:
	std::map<std::string, int> m_saveData;

	std::string m_directory;

};