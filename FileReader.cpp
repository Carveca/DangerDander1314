//FileReader source file

#include "stdafx.h"
#include "FileReader.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>

FileReader::FileReader()
{
	m_directory = "";
}

FileReader::~FileReader()
{

}

void FileReader::Initialize(std::string directory)
{
	m_directory = directory;
}

void FileReader::LoadFile(std::string filename)
{
	std::ifstream openfile(m_directory + filename);

	std::string key;
	float value = 0;

	if(openfile.is_open())
	{
		while(!openfile.eof())
		{
			openfile >> key >> value;

			if(key == "PlayerHPDrain")
				std::cout << value << std::endl;
			
			m_settings.insert( std::pair <std::string, float>(key, value) );
		}
		openfile.close();
	}
	else
	{
		std::cout << "Error, could not read from file" << std::endl;
	}
}