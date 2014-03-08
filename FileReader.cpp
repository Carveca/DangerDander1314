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
	int value = 0;

	if(openfile.is_open())
	{
		while(!openfile.eof())
		{
			openfile >> key >> value;
			
			m_settings.insert( std::pair <std::string, int>(key, value) );
		}
	}
	else
	{
		std::cout << "Error, could not read from file" << std::endl;
	}
}