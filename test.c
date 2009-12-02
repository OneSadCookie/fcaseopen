#include <assert.h>
#include <unistd.h>

#include "fcaseopen.h"

static long flength(FILE *f)
{
    assert(f);
    long pos = ftell(f);
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, pos, SEEK_SET);
    return length;
}

int main()
{
    FILE *_fcaseopen_h = fcaseopen("fcaseopen.h", "rb");
    FILE *FCASEOPEN_H = fcaseopen("FCASEOPEN.H", "rb");
    FILE *dir_file_txt = fcaseopen("dir/file.txt", "rb");
    FILE *DIR_FILE_txt = fcaseopen("DIR/FILE.txt", "rb");
    FILE *dir_FILE2_txt = fcaseopen("dir/FILE2.txt", "rb");
    FILE *DIR_file2_txt = fcaseopen("DIR/file2.txt", "rb");
    FILE *DIR_file3_txt = fcaseopen("DIR/file3.txt", "wb");
    fwrite("...", 1, 3, DIR_file3_txt);
    fclose(DIR_file3_txt);
    FILE *dir_FILE3_TXT = fcaseopen("dir/FILE3.TXT", "rb");
    unlink("dir/file3.txt"); // TODO caseunlink?
    casechdir("DIR");
    FILE *file_txt = fcaseopen("file.txt", "rb");
    FILE *FILE_TXT = fcaseopen("FILE.TXT", "rb");
    
    FILE* no = fcaseopen("dir/no.txt", "rb");
    assert(!no);
    
    printf(
        "fcaseopen.h:\t%ld\n"
        "FCASEOPEN.H:\t%ld\n"
        "dir/file.txt:\t%ld\n"
        "DIR/FILE.txt:\t%ld\n"
        "dir/FILE2.txt:\t%ld\n"
        "DIR/file2.txt:\t%ld\n"
        "dir/FILE3.TXT:\t%ld\n"
        "file.txt:\t%ld\n"
        "FILE.TXT:\t%ld\n",
        flength(_fcaseopen_h),
        flength(FCASEOPEN_H),
        flength(dir_file_txt),
        flength(DIR_FILE_txt),
        flength(dir_FILE2_txt),
        flength(DIR_file2_txt),
        flength(dir_FILE3_TXT),
        flength(file_txt),
        flength(FILE_TXT));
    
    return 0;
}
