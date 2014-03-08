//File Reader Header File

#pragma once

class FileReader
{
public:
	FileReader();
	~FileReader();

	void Initialize(std::string directory);
	void LoadFile(std::string filename);

public:
	std::map<std::string, int> m_settings;

private:
	std::string m_directory;

};