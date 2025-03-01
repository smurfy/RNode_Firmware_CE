#ifndef NOOP_FILE_SYSTEM_h
#define NOOP_FILE_SYSTEM_h

#ifdef HAS_RNS

#include <FileSystem.h>
#include <FileStream.h>
#include <Bytes.h>
#include <Type.h>

class NoopFileSystem : public RNS::FileSystemImpl {

public:
	NoopFileSystem() {}

	bool init() { return true; }
	bool format() { return false; }
	bool reformat() { return false; }

public:
	static void listDir(const char* dir, const char* prefix = "") {}
	static void dumpDir(const char* dir) {}

public:
	 bool file_exists(const char* file_path) { return false; }
	 size_t read_file(const char* file_path, RNS::Bytes& data) { return 0; }
	 size_t write_file(const char* file_path, const RNS::Bytes& data) { return 0; }
	 RNS::FileStream open_file(const char* file_path, RNS::FileStream::MODE file_mode) { return {RNS::Type::NONE}; }
	 bool remove_file(const char* file_path) { return false; }
	 bool rename_file(const char* from_file_path, const char* to_file_path) { return false; }
	 bool directory_exists(const char* directory_path) { return false; }
	 bool create_directory(const char* directory_path) { return false; }
	 bool remove_directory(const char* directory_path) { return false; }
	 std::list<std::string> list_directory(const char* directory_path) { return std::list<std::string>(); }
	 size_t storage_size() { return 0; }
	 size_t storage_available() { return 0; }

};

#endif

#endif