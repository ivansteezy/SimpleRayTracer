#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <filesystem>
#include <fstream>
#include <string>

class File
{
public:
	static void file(std::string _path)
	{
		std::experimental::filesystem::path path{ _path };
		std::experimental::filesystem::create_directories(path.parent_path());

		std::ofstream ofs(path);
		ofs << "this is some text in the new file\n";
		ofs.close();
	}
};

#endif 
