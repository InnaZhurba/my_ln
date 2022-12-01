#include <iostream>
#include <unistd.h>

//implement ln command with soft/hard link
int main(int argc, char *argv[])
{
    std::string help = ("Usage: ln -s/-h source_file target_file");

    if(argc == 1){
        return 0;
    }

    if(strcmp(argv[1], "--help") == 0 || argc != 4) {
        std::cerr << help << std::endl;
    }

    if(strcmp(argv[1], "--soft") == 0)
    {
        //if file exists return error
        /*if(access(argv[3], F_OK) == 0)
        {
            perror("File already exists");
        }*/
        if(symlink(argv[2], argv[3]) == -1)
        {
            perror("symlink error");
        }
    }
    else if(strcmp(argv[1], "--hard") == 0)
    {
        //if file exists return error
        /*if(access(argv[3], F_OK) == 0)
        {
            perror("File already exists");
        }*/
        if(link(argv[2], argv[3]) == -1)
        {
            perror("link error");
        }
    }

    return 0;
}
