//File Reader Header File

#pragma once

#include <string>
#include <map>

class FileReader
{
public:
	FileReader();
	~FileReader();

	void Initialize(std::string directory);
	void LoadFile(std::string filename);

public:
	std::map<std::string, float> m_settings;

private:
	std::string m_directory;

};