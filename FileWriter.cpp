//File Writer source file

#include "stdafx.h"
#include "FileWriter.h"
#include <fstream>
#include <iostream>


FileWriter::FileWriter()
{
	m_directory = "";
}

FileWriter::~FileWriter()
{
	
}

void FileWriter::Initialize(std::string directory)
{
	m_directory = directory;

}

void FileWriter::AddData(std::string key, int value)
{
	m_saveData.insert( std::pair <std::string , int>(key, value));
}

void FileWriter::WriteToFile(std::string filename)
{
	std::ofstream openfile(m_directory + filename);

	if(filename == "SoundSettings.txt")
	{
		if(openfile.is_open())
		{
			openfile << "MusicVolume " << m_saveData["MusicVolume"] << std::endl;
			openfile << "SoundVolume " << m_saveData["SoundVolume"] << std::endl;
			openfile.close();
		}
		else
		{
			std::cout << "Error, could not write to file" << std::endl;
		}
	}
	else if(filename == "HighScore.txt")
	{
		if(openfile.is_open())
		{
			openfile << m_saveData["1:"] << std::endl;
			openfile << m_saveData["2:"] << std::endl;
			openfile << m_saveData["3"] << std::endl;
			openfile << m_saveData["4:"] << std::endl;
			openfile << m_saveData["5:"] << std::endl;
			openfile << m_saveData["6:"] << std::endl;
			openfile << m_saveData["7:"] << std::endl;
			openfile << m_saveData["8:"] << std::endl;
			openfile << m_saveData["9:"] << std::endl;
			openfile << m_saveData["10:"] << std::endl;
			openfile.close();
		}
		else
		{
			std::cout << "Error, could not write to file" << std::endl;
		}
	}
	else
	{
		std::cout << "Error, could not write to file" << std::endl;
	}
}

