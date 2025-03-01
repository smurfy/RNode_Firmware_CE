#ifndef FILE_SYSTEM_h
#define FILE_SYSTEM_h

#ifdef HAS_RNS

#include <FileSystem.h>
#include <FileStream.h>
#include <Bytes.h>
#include <Type.h>

class FileSystem : public RNS::FileSystemImpl {

public:
	FileSystem() {}

	bool init();
	bool format();
	bool reformat();

public:
	static void listDir(const char* dir, const char* prefix = "");
	static void dumpDir(const char* dir);

public:
	 bool file_exists(const char* file_path);
	 size_t read_file(const char* file_path, RNS::Bytes& data);
	 size_t write_file(const char* file_path, const RNS::Bytes& data);
	 RNS::FileStream open_file(const char* file_path, RNS::FileStream::MODE file_mode);
	 bool remove_file(const char* file_path);
	 bool rename_file(const char* from_file_path, const char* to_file_path);
	 bool directory_exists(const char* directory_path);
	 bool create_directory(const char* directory_path);
	 bool remove_directory(const char* directory_path);
	 std::list<std::string> list_directory(const char* directory_path);
	 size_t storage_size();
	 size_t storage_available();

};

#endif

#endif